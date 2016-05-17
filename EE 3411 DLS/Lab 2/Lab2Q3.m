%Sean Basler
%Lab2 Q3
%*****************
clc; clear all; close all;

dt = 0.001;
t = 0.6:dt:1.6;

xt = t .* (us(t-0.8) - us(t-1.1));

figure(1);
plot(t,xt);

R = 2e3; %2kohm
C = 10e-6; %10 uF
T = dt;

yt(1) = 0;

for n = 1:size(xt,2)
    yt(n+1) = (1/((R*C/T)+1)) * (xt(n) + R*C/T *yt(n));
end

figure(2);
plot(t,yt(2:end));