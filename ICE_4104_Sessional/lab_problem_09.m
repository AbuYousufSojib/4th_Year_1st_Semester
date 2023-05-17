clc;
clear all;
close all;
hte = 100;       %effective transmitter (base station) antenna height in meter
hre = 2;         %effective receiver (base station) antenna height in meter
fc = 900;        %frequency in MHz
d = 4;           %T-R seperation distance   in kilometer
a_hre = (3.2*(log10(11.75*hre))^2)-4.97;               %correction factor(using okumura-hata model)
disp('correction factor for effective mobile antenna height:');
disp(a_hre);
Lp = 69.55 + 26.16*log10(fc)-13.82*log10(hte)-a_hre+((44.9-6.55*log10(hte))*log10(d));      %path loss in large city
disp('path loss Lp:');
disp(Lp);