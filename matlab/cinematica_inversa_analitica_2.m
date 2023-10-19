    %% Inverse kinematics (Analytics) of a Hexapod robot ----------------------
% Dr. Jorge A. Lizarraga
% 12/09/2023
clc; close all; clear;
%% Main loop
q = zeros(4,6);
q(4,:) = (2*pi/6*(0:1:5));
q(5,:) = (pi/2)*ones(1,6);
T = 0:0.001:.5;
phi = [0 1 0 1 0 1];
q5 = linspace(0,2*pi,length(T));
for i = 1:length(T)
    t = T(i);
    for l = 1:1
    p = Trajectory(t,phi(l));
    q(1:3,l) = q(1:3,l) + delta_q(p,q(:,l));
    r0_5 = LegHexapod(q(:,l),'draw');
    hold on
    P(:,i,l) = r0_5;
    plot3(P(1,1:i,l),P(2,1:i,l),P(3,1:i,l),'b')
    Q(:,i) = q(1:3,l); 
    end
    %------------------------------------------------
    hold off
    axis equal
    axis(300*[-1 1 -1 1 -0.5 0.5])
    grid on
    view(60,20)
    figuresk(0,5,1,7)
    drawnow
end
%%
dQ1 = diff(Q(1,:))./diff(T);
dQ2 = diff(Q(2,:))./diff(T);
dQ3 = diff(Q(3,:))./diff(T);
ddQ1 = diff([0 dQ1])./diff(T);
ddQ2 = diff([0 dQ2])./diff(T);
ddQ3 = diff([0 dQ3])./diff(T);
figure
subplot(3,1,1)
plot(dQ1(4:end))
grid on
subplot(3,1,2)
plot(dQ2(4:end))
grid on
subplot(3,1,3)
plot(dQ3(4:end))
grid on

figure
subplot(3,1,1)
plot(ddQ1(4:end))
grid on
subplot(3,1,2)
plot(ddQ2(4:end))
grid on
subplot(3,1,3)
plot(ddQ3(4:end))
grid on
%% ----------------Calculation of the joint variable q2 -------------------
function Delta_q = delta_q(p,q)
q1 = q(1);
q2 = q(2);
q3 = q(3);
q4 = q(4);
q5 = q(5);
px = p(1);
py = p(2);
pz = p(3); 
%desplazamiento horizontal
x1 = 81.5;  %% desde el centro del robot a el primer servo
x2 = 43; %% desde el primer servo al segundo
x3 = 77.04; %%desde el segundo servo al tercero
x4 = 52.87; %desde el tercer cervo a la punta
x5 = 254.41; %desde el origen (centro geometrico) a la punta de la pata
%dezplazamiento vertical
z1 = 0; %(no existe desplazamiento en z, porque el primer servo esta a nivel)
z2 = 0; %%dezplazamiento vertical del servo 1 al servo 2 
z3 = 21.56; %dezplazamiento vertical del servo 2 al servo 3
z4 = -123.53; %dezplazamiento vertical del servo 3 a la punta de la pata 
z5 = -101.97; %dezplazamiento vertical del origen (geometrico a la punta de la pata 
%% ----------------Calculation of the joint variable q1 -------------------
d1 = sign((py*cos(q1 + q4 - q5) - px*sin(q1 + q4 - q5) + x1*sin(q1) - ...
    x5*sin(q1))*(x2 + x4*cos(q2 + q3) + z4*sin(q2 + q3) + x3*cos(q2) + z3*sin(q2)));


delta_q1 = d1*abs(acos(((px*cos(q1 + q4 - q5) + py*sin(q1 + q4 - q5) - ...
    x1*cos(q1) + x5*cos(q1))*(x2 + x4*cos(q2 + q3) + z4*sin(q2 + q3) + ...
    x3*cos(q2) + z3*sin(q2)))/(abs(x2 + x4*cos(q2 + q3) + z4*sin(q2 + q3) ...
    + x3*cos(q2) + z3*sin(q2))*(px^2 - 2*cos(q4 - q5)*px*x1 + 2*cos(q4 - q5) ...
    *px*x5 + py^2 - 2*sin(q4 - q5)*py*x1 + 2*sin(q4 - q5)*py*x5 + ...
    x1^2 - 2*x1*x5 + x5^2)^(1/2))));

%% ----------------Calculation of the joint variable q3 -------------------
d3 = -1;
delta_q3 = d3*(acos((x3^2 - (x5 - x1 - x2*cos(q1) + px*cos(q4 - q5) + ...
    py*sin(q4 - q5))^2 - (pz - z2 + z5)^2 - (x2*sin(q1) - py*cos(q4 - q5) + ...
    px*sin(q4 - q5))^2 + x4^2 + z3^2 + z4^2)/(2*(x3^2 + z3^2)^(1/2)* ...
    (x4^2 + z4^2)^(1/2))) - pi + acos((x3*x4*cos(q3) + z3*z4*cos(q3) + ...
    x3*z4*sin(q3) - x4*z3*sin(q3))/((x3^2 + z3^2)^(1/2)*(x4^2 + z4^2)^(1/2))));

%% ----------------Calculation of the joint variable q2 -------------------
d2 = sign((z4*cos(q2 + q3) - x4*sin(q2 + q3) + z3*cos(q2) - x3*sin(q2))* ...
    (x5 - x1 - x2*cos(q1) + px*cos(q4 - q5) + py*sin(q4 - q5)) - cos(q1)* ...
    (pz - z2 + z5)*(x4*cos(q2 + q3) + z4*sin(q2 + q3) + x3*cos(q2) + z3*sin(q2)));


delta_q2 = d2*abs(acos(((pz - z2 + z5)*(z4*cos(q2 + q3) - x4*sin(q2 + q3) + z3*cos(q2) ...
    - x3*sin(q2)) + cos(q1)*(x4*cos(q2 + q3) + z4*sin(q2 + q3) + x3*cos(q2) + ...
    z3*sin(q2))*(x5 - x1 - x2*cos(q1) + px*cos(q4 - q5) + py*sin(q4 - q5)))/ ...
    (((x5 - x1 - x2*cos(q1) + px*cos(q4 - q5) + py*sin(q4 - q5))^2 + ...
    (pz - z2 + z5)^2)^(1/2)*((z4*cos(q2 + q3) - x4*sin(q2 + q3) + z3*cos(q2) ...
    - x3*sin(q2))^2 + cos(q1)^2*(x4*cos(q2 + q3) + z4*sin(q2 + q3) + x3*cos(q2) ...
    + z3*sin(q2))^2)^(1/2))));



%%
Delta_q = [delta_q1;delta_q2;delta_q3];
end
%% Virtual Bot Function ---------------------------------------------------
function r0_4 = LegHexapod(q,options)
% r0_0 = [0;0;0];
% r0_1 = [62.79;82.93;0];%x1 y1 z1
% r1_2 = [0;0;38.5];%x2 y z3
% r2_3 = [43;0;0];%x3 y z3
% r3_4 = [60.24;0;-97.49];%x4 y z4


r0_0 = [0;0;0];
r0_1 = [81.5;0;0];%x1 y1 z1
r1_2 = [43;0;0];%x2 y1 z2
r2_3 = [77.04;0;21.56];%x3 y3 z3
r3_4 = [52.87;0;-123.53];%x4 y4 z4



% r0_0=[0;0;0];
% r0_1=[81.5;0;0];
% r1_2=[0;0;38.5];
% r2_3=[43;0;0];
% r3_4=[77.04;0;21.56];
% r4_5=[52.87;0;-123.53];
%%
R0_0 = Rz(q(4));
R0_1 = R0_0*Rz(q(1));
R1_2 = Ry(q(2));
R2_3 = Ry(q(3));
%R3_4 = Ry(q(4));
R0_2 = R0_1*R1_2;
R0_3 = R0_2*R2_3;
%R0_4 = R0_3*R3_4;
r0_1 = r0_0 + R0_0*r0_1;
r0_2 = r0_1 + R0_1*r1_2;
r0_3 = r0_2 + R0_2*r2_3;
r0_4 = r0_3 + R0_3*r3_4;
%r0_5 = r0_4 + R0_4*r4_5;
%%
    if contains(options,'draw')
        % o0 = [R0_0 r0_0];
        o1 = [R0_1 r0_1];
        o2 = [R0_2 r0_2];
        o3 = [R0_3 r0_3];
        %o4 = [R0_4 r0_4];
        a = 20;
        % frame(o0,0,a)
        frame(o1,1,a)
        frame(o2,2,a)
        frame(o3,3,a)
        %frame(o4,4,a)
        vlink(r0_0,r0_1,'k')
        vlink(r0_1,r0_2,'k')
        vlink(r0_2,r0_3,'k')
        vlink(r0_3,r0_4,'k')
        %vlink(r0_4,r0_5,'k')
    end
end


                                                                                                 
                                                                                                           
                                      