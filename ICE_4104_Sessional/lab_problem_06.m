clc;
clear all;
close all;
R = 1.387;       %radius
n = 4;           %no of cell
N = 60;          %total no of channel
A = 2.5981*R^2;        %area covers per cell
C = N/4;                %no of channel per cell
A1 = 9;                        %traffic intensity at c=15, GOS=0.05, Au=0.029  from erlang C chart
A2 = floor(A1/(0.029*A));         %Au=0.029
disp('no of user:');
disp(A2);
lemda = 1 ;                   % lamda = 1 hour
H = (0.029/lemda)*3600;        % hour to second
A3 = (exp((-(C-A1)*10)/H))*100;         % t=10s,   C=15, A1=9, H=104.4
disp('probability to wait:');
disp(A3);
A4 = 0.05*A3;                             % 5% probability of delayed call
disp('probability to delay:');
disp(A4);