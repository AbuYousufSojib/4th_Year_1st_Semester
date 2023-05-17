clc;
clear all;
close all;
t_r_distance = 5;         %t-r seperation distance
e_field = 10^-3;          % e-field
d = 5000;      
d0 = 1000;
f = 900;
lemda = 1/3;
a = lemda/4;
gain =(10^(2.55/10));
disp('length of antenna:');
disp(a);
disp('gain of antenna:');
disp(gain);
Er_d = (2*e_field*d0*2*3.1416*50*1.5)/(lemda*d^2);
disp('electric field:');
disp(Er_d);
Ae = (gain*lemda^2)/(4*3.1416);
Pr_d = (Er_d^2/(120*3.1416))/Ae;
b = 10*log10(Pr_d);
disp('receiveed power at 5km distance:');
disp(b);