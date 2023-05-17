clc;close all;
r_si = 15;            %required S/I
i0 = 6;               %co-channel interfering cells
for n = [4 3]       %pathloss exponent = n
    N = 7;            %cluster size
    Q = sqrt(3*N);    %frequency reuse factor
    fprintf('path loss exponent n : %d \n',n);
    fprintf('cluster size N: %d \n',N);
    disp(Q);
    fprintf('frequency reuse factor Q : %d \n', Q);
    si = 10*(log10((Q^n)/i0));       %signal to interference ratio
    fprintf('signal to interference ratio s/i: %d\n',si);
    if (si<r_si)
        i = 2; j = 2;
        N1 = (i*i)+(i*j)+(j*j);
        Q1 = sqrt(3*N1);
        disp('path loss exponent n:');
        disp(n);
        disp('cluster size N:');
        disp(N1);
        disp('frequency reuse factor Q:');
        disp(Q1);
        si1 = 10*(log10((Q1^n)/i0));
        disp('signal to interferance ratio s/i:');
        disp(si1);
    end
end