clc; close all; clear;
x = sym('x',[1;5]); %% crear 6 r0_1
z = sym('z',[1;5]);
y = sym('y',[1;5]);
q = sym('q',[1;5]);
assume([x z q],'real')
r0_0 = [0;0;0];
r0_1 = [x(1);y(1);z(1)];
r1_2 = [x(2);y(2);z(2)];
r2_3 = [x(3);y(3);z(3)];
r3_4 = [x(4);y(4);z(4)];
%%
R0_0 = Rz(0);
R0_1 = R0_0*Rz(q(1));
R1_2 = Ry(q(2));
R2_3 = Ry(q(3));
R0_2 = R0_1*R1_2;
R0_3 = R0_2*R2_3;
%%
r0_1 = r0_0 + R0_0*r0_1; % ---------> 
r0_2 = r0_1 + R0_1*r1_2; %
r0_3 = r0_2 + R0_2*r2_3; %
r0_4 = r0_3 + R0_3*r3_4; %
%%
r0_2 = simplify(r0_2);
r0_4 = simplify(r0_4);
%%
syms px py pz 
assume([px py pz],'real')
r5_p = [px;py;pz];
R5_p = Rz(q(5)-q(4));
R0_5 = R0_0*R5_p;
r0_5 = [x(5);0;z(5)];
r0_5 = r0_0 + R0_0*r0_5;
r0_p = r0_5+R0_5*r5_p;
%%
f = @(ri_a,ri_b)acos((ri_a(1)*ri_b(1)+ri_a(2)*ri_b(2))/(norm([ri_a(1),ri_a(2)])*norm([ri_b(1),ri_b(2)])));
r1_4 = (r0_4-r0_1);
r1_p = (r0_p-r0_1);
d_z = @(ri_a,ri_b)sign(ri_a(1)*ri_b(2)-ri_b(1)*ri_a(2)); 
d1 = simplify(d_z(r1_4,r1_p));
delta_q1 = simplify(abs(f(r1_4,r1_p)));
%%
syms d
assume(d,'real')
r2_4 = r0_4-r0_2;
r2_p = r0_p-r0_2;
b_i = acos((norm(r3_4)^2+norm(r2_3)^2-norm(r2_4)^2)/(2*norm(r3_4)*norm(r2_3)));
b_f = acos((norm(r3_4)^2+norm(r2_3)^2-norm(r2_p)^2)/(2*norm(r3_4)*norm(r2_3)));
delta_q3 = d*(b_f-b_i);
delta_q3 = simplify(delta_q3);
%%
f = @(ri_a,ri_b)acos((ri_a(1)*ri_b(1)+ri_a(3)*ri_b(3))/(norm([ri_a(1),ri_a(3)])*norm([ri_b(1),ri_b(3)])));
r2_4 = r0_4-r0_2;
r2_p = r0_p-r0_2;
d_y = @(ri_a,ri_b)sign(ri_b(1)*ri_a(3)-ri_a(1)*ri_b(3));
d2 = simplify(d_y(r2_4,r2_p));
delta_q2 = simplify(abs(f(r2_4,r2_p)));
