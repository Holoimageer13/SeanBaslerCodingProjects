%Sean Basler
%Lab6 Q1
%***************************
clear all; close all; clc;
%***************************

dt = 0.01;
t = -1:dt:4;
xt = 2*sinc(3.2*(t-1.5));

figure(1);
plot(t,xt);

%***************************
dfm = 0.01;
[f,X,N,no] = ctft(t,xt,dfm);

j = sqrt(-1);
Xf = 2/3.2*rect_pulse(f/3.2) .* exp(-j*2*pi*1.5*f);

figure(2);
subplot(2,1,1);
plot(f,abs(X),f,abs(Xf));
xlim([-5 5]);

subplot(2,1,2);
plot(f,angle(X),f,angle(Xf));
xlim([-5 5]);

 