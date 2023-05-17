clc;close all;
GOS = 0.5/100;      %blocking probablity (0.5%)
Au = 0.1;           %traffic intensity per user
A = [0.005 1.13 3.96 11.1 80.9];    %from erlang B chart
C = [1 5 10 20 100];           %channel
disp('Blocking probablity GOS:');
disp(GOS);
disp('traffic intensity per user Au:');
disp(Au);
disp('Traffic intensity A:');
disp(A);
disp('Channel C:');
disp(C);
U = (A/Au);
u=round(U);
disp('Number of user:');
disp(u);