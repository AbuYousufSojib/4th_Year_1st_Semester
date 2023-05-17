clc;close all;
bw = 30000;             %bandwidth
sim_ch_bw = 25;         %simplex channel bandwidth
dup_ch_bw = 2*sim_ch_bw;        %duplex channel bandwidth
fprintf("Channel Bandwidth: %d\n",dup_ch_bw);
t_ch = (bw/dup_ch_bw);         %total available channel
fprintf('Total Available Channel: %d\n',t_ch);
cc_bw = 1000;                  %control channel bandwidth
t_cc = cc_bw/dup_ch_bw;        %total control channel
fprintf('Total Control Channel: %d\n',t_cc);
for N = [4 7 12]
    ch = (t_ch/N);                                       
    fprintf('Cluster Size: %d\n',N);%cluster size
    ch_per_cell = round(ch);       %channel per cell 
    fprintf('Channel per cell: %d\n',ch_per_cell);
    c = (t_cc/N);
    cc = round(c);                  %control channel
    vc = (ch_per_cell - cc);          %voice channel
    fprintf('control and voice channel are : %d %d\n',cc,vc);
end
