clc;
clear all;
close all;
fc = 1.8;        %frequency in MHz
hte = 20;         %hte and hre in meter
d = (sqrt(20^2+30^2))/1000;        % d in km
disp('distance of base station from mobile station:');
disp(d);
Lp = 135.41+(12.49*log10(fc))-(4.99*log10(hte))+((46.84-2.34*log10(hte))*log10(d));
disp('path loss:');
disp(Lp);