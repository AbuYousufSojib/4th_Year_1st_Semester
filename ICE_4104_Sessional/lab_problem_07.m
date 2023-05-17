clc;
clear all;
close all;
pt = 50;        %transmitted power
fc = 900;        % carrier frequency
gt = 1;          %transmitter antenna gain
gr = 1;           %receiever antenna gain
d = 100;          %free space distance
a = ceil(10*log10(50*1000));
disp('transmitter power in dBm:');
disp(a);
b = ceil(10*log10(50*1));
disp('transmitter power in dBW:');
disp(b);
c = ((pt*gt*gr*(1/3)^2)/((4*3.1416)^2*d^2*1))*1000;    %lemda=c/f=1/3
d = 10*log10(c);
disp('received power in dBm:');
disp(d);
e = d + (20*log10(100/10000));
disp('received power at 10km:');
disp(e);