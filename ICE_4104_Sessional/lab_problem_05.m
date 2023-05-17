clc;close all;
total_city_coverage_area = 1300;
radius = 4;
a = (2.591*radius^2);
disp('each cells covers:');
disp(a);
B = (total_city_coverage_area/a);
b = round(B);
disp('no of cells:');
disp(b);
C = (40000/(60*7));        %allocated spectrum=40MHz, full duplex channel BW = 60KHz
c = round(C);
disp('no of channel per cell:');
disp(c);
d = 84;                    %C=95, GOS=0.02 from erlang B chart
disp('traffic intensity per cell:');
disp(d);
e = floor(b*d);
disp('maximum carried traffic:');
disp(e);
f = e/0.03;                  %traffic per user = 0.03
disp('Total no of user:');
disp(f);
g = (f/(c*7));
disp('no of mobile per channel:');
disp(g);
h = floor(c*b);
disp('theoritical maximum no of user that could be served:');
disp(h);