%Sean Basler
%Lab2 Q5
%*****************
clc; clear all; close all;

dt = 0.001;
t = -0.1:dt:0.2;

xt = 0 .* t + (1/dt) .* (t == 0);

figure(1);
plot(t,xt);

R = 2e3; %2kohm
C = 10e-6; %10 uF
T = dt;

yt(1) = 0;

for n = 1:size(xt,2)
    yt(n+1) = (1/((R*C/T)+1)) * (xt(n) + R*C/T *yt(n));
end

%********************
ht = 1/(R*C) * exp(-t/(R*C)) .* us(t);

figure(2);
plot(t,yt(2:end),t,ht);
legend('yt','ht');