clc;close all;
blocking_probability = 2/100;   %GOS
Au = (2/60)*3;                  %traffic intensity per user
disp('For system A:');
%no_of_channel_per_cell = 19;     %channel
A = 12;                          %total traffic intensity from erlang B chart, GOS=0.02, C=19
U = A/Au;                        %user
Aa = U*394;
disp('Total no of subscriber of A:');
disp(Aa);
percentage_A = (Aa/2000000)*100;
disp('percentage market penetration for A:');
disp(percentage_A);
disp('For system B:');
%no_of_channel_per_cell = 57;
A1 = 45;                             %GOS=0.02, C=57
U1 = A1/Au;
Bb = U1*98;
disp('Total no of subscriber of B:');
disp(Bb);
percentage_B = (Bb/2000000)*100;
disp('percentage market penetration for B:');
disp(percentage_B);
disp('For system C:');
no_of_channel_per_cell = 100;
A2 = 88;                               %GOS=0.02, C=100
U2 = A2/Au;
Cc = U2*49;
disp('Total no of subscriber of C:');
disp(Cc);
percentage_C = (Cc/2000000)*100;
disp('percentage market penetration for C:');
disp(percentage_C);
T = Aa+Bb+Cc;
disp('Total no of subscriber of all three system:');
disp(T);
percentage_T = (T/2000000)*100;
disp('market penetration for all three system:');
disp(percentage_T);