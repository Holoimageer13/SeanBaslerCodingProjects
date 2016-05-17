%Sean Basler
%Lab4 Q1
%*****************
clear all; close all; clc;

freq = [-30 -25 -15 15 25 30];
amp_x = [3 2 5 5 2 3];
phase_x = [1 0.5 -1.5 1.5 -0.5 -1];

dt = 0.001;
t = -0.2:dt:0.2;

j = sqrt(-1);
xt = zeros(size(t));

for k = 1:length(freq)
    xt = amp_x(k)*exp(j*2*pi*freq(k)*t)*exp(j*phase_x(k)) + xt;
end

figure(1);
plot(t,xt);

%*****************

freq = [-30 -25 -15 15 25 30];
amp_y = [4 3 2 2 3 4];
phase_y = [1.6 -0.4 -0.8 0.8 0.4 -1.6];

dt = 0.001;
t = -0.2:dt:0.2;

j = sqrt(-1);
yt = zeros(size(t));

for k = 1:length(freq)
    yt = amp_y(k)*exp(j*2*pi*freq(k)*t)*exp(j*phase_y(k)) + yt;
end

figure(2);
plot(t,yt);

