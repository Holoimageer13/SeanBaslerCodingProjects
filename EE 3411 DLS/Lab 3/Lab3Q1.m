%Sean Basler
%Lab3 Q1
%*****************
clear all; close all; clc; 

dt = 0.05;
t = -4:dt:4;

xt = -(t+0.25) .* (us(t+2)-us(t-1));
yt = 2*exp(-0.4*(t+0.5)) .* cos(0.5*pi*t-(pi/4))...
     .*(us(t+0.5)-us(t-2.5));

zt = dt*conv(xt,yt);
tz = -8:dt:8;

figure(1);
plot(t,xt,t,yt,tz,zt);
legend('xt','yt','zt');
xlim([-4 4]);
