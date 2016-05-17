%Sean Basler
%Lab3 Q2
%homework
%*****************
clear all; close all; clc; 

dt = 0.01;
t = -8:dt:8;

xt = exp(-0.5 .* t) .* us(t);
yt = 2*exp(0.75 .* t) .* us(-t);

zt = dt*conv(xt,yt);
tz = -16:dt:16;

mzt = 1.6*exp(0.75 .* tz) .* (tz<0) + 1.6*exp(-0.5 .* tz) .* (tz>=0); 

figure(1);
subplot(2,1,1);
plot(tz,zt,tz,mzt);
legend('zt','mzt');

subplot(2,1,2);
plot(t,xt,t,yt)
legend('xt','yt');

%******************

dt = 0.01;
t = -6:dt:6;

xt = exp(-0.5 .* t) .* us(t);
yt = 2*exp(0.75 .* t) .* us(-t);

zt = dt*conv(xt,yt);
tz = -12:dt:12;

mzt = 1.6*exp(0.75 .* tz) .* (tz<0) + 1.6*exp(-0.5 .* tz) .* (tz>=0); 

figure(2);
subplot(2,1,1);
plot(tz,zt,tz,mzt);
legend('zt','mzt');

subplot(2,1,2);
plot(t,xt,t,yt)
legend('xt','yt');

%********************
dt = 0.01;
t = -4:dt:4;

xt = exp(-0.5 .* t) .* us(t);
yt = 2*exp(0.75 .* t) .* us(-t);

zt = dt*conv(xt,yt);
tz = -8:dt:8;

mzt = 1.6*exp(0.75 .* tz) .* (tz<0) + 1.6*exp(-0.5 .* tz) .* (tz>=0); 

figure(3);
subplot(2,1,1);
plot(tz,zt,tz,mzt);
legend('zt','mzt');

subplot(2,1,2);
plot(t,xt,t,yt)
legend('xt','yt');

%********************
dt = 0.01;
t = -2:dt:2;

xt = exp(-0.5 .* t) .* us(t);
yt = 2*exp(0.75 .* t) .* us(-t);

zt = dt*conv(xt,yt);
tz = -4:dt:4;

mzt = 1.6*exp(0.75 .* tz) .* (tz<0) + 1.6*exp(-0.5 .* tz) .* (tz>=0); 

figure(4);
subplot(2,1,1);
plot(tz,zt,tz,mzt);
legend('zt','mzt');

subplot(2,1,2);
plot(t,xt,t,yt)
legend('xt','yt');