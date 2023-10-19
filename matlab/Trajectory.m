function p = Trajectory(T,phi)
x1 = @(vx,t)vx*(t);
z1 = @()0;
x2 = @(a,t,vx,x_c)x_c+a.*cos(((a-t.*vx).*(pi-acos((a+x_c)./a)))./(a.*2.0));
z2 = @(a,b,t,vx,z_c)z_c-b.*sin(((a-t.*vx).*(pi+asin(z_c./b)))./(a.*2.0));
x3 = @(a,t,vx)-a+vx.*(t-(a.*3.0)./vx);
z3 = @()0;
x4 = @()0;
z4 = @(a,b,t,vx)(b.*t.*vx.*2.0)./a;
x5 = @(a,t,vx,x_c)x_c+a.*cos(pi./2.0+(vx.*(t-a./(vx.*2.0)).*(pi./2.0+acos((a+x_c)./a)).*2.0)./a);
z5 = @(a,b,t,vx,z_c)z_c+b.*sin(pi./2.0+(vx.*(pi./2.0+asin(z_c./b)).*(t-a./(vx.*2.0)).*2.0)./a);
x6 = @(a,t,vx)-a+vx.*(t-a./vx);
z6 = @()0;
%%
% phi = 0; % 0 for set of legs without advance, 1 for the otherwise. 
x_c = 0; % x coordinate of the origin.
z_c = 0; % z coordinate of the origin.
% ------------------------
a = 150/2; % Maximum horizontal displacement.
b = 55; % Maximum vertical displacement.
% ------------------------
% a = 90/2; % Maximum horizontal displacement.
% b = 60; % Maximum vertical displacement.
vx = 600; % Linear speed.
% ------------------------
tau = a/vx; % Cycle constant per section (4 sections).
flag_phi1 = false; % Flag of the advanced team.
x = zeros(1,length(T));
y = zeros(1,length(T));
z = zeros(1,length(T));
%% Main loop
for i = 1:length(T)
    t = ciclo(T(i),tau);
    if phi == 1 && T(i) <= tau/2
        x(i) = x4();
        z(i) = z4(a,b,t,vx);
    elseif phi == 1 && T(i) <= tau
        x(i) = x5(a,t,vx,x_c);
        z(i) = z5(a,b,t,vx,z_c);
    elseif phi == 1 && T(i) <= 2*tau
        x(i) = x6(a,t,vx);
        z(i) = z6();
    elseif phi == 1 
        t = t + 2*tau;    
        t = ciclo(t,tau);
        flag_phi1 = true;
    end
    if phi ~= 1 || flag_phi1
        if t <= tau
            x(i) = x1(vx,t);
            z(i) = z1();
        elseif t <= 3*tau
            x(i) = x2(a,t,vx,x_c);
            z(i) = z2(a,b,t,vx,z_c);
        elseif t <= 4*tau
            x(i) = x3(a,t,vx);
            z(i) = z3();
        end
    end
end
p = [x;y;z];
%% Functions
function t = ciclo(T,tau)
    n = 4;
    if T < n*tau
        t = T;
    else
        t = T - fix(T/(n*tau))*(n*tau);
    end
end
end



