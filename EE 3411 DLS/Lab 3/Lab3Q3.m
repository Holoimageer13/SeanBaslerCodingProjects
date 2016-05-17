%Sean Basler
%Lab3 Q3
%*****************
clear all; close all; clc; 

dt = 0.005;
t = -2:dt:3;

xt = 3*rect_pulse((t-0.875)/1.75);
yt = 1.5*sin(4*pi*t);

zt = dt*conv(xt,yt);
tz = -4:dt:6;

figure(1);
subplot(3,1,1);
plot(t,xt);

subplot(3,1,2)
plot(t,yt);

subplot(3,1,3);
plot(tz,zt);
