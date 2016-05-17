%Sean Basler
%Lab6 Q3
%***************************
clear all; close all; clc;
%***************************
%a.

dt = 0.01;
t = -1:dt:5;

xt = 3.6*t .* exp(-2.4*t) .*us(t);

df = 0.02;

[f,X,N,no] = ctft(t,xt,df);

figure(1);
subplot(3,1,1);
plot(t,xt);

subplot(3,1,2);
plot(f,abs(X));
xlim([-2 2]);

subplot(3,1,3);
plot(f,angle(X));
xlim([-2 2]);

%***************************
%b.

xt = 3.6*(t-0.1) .* exp(-2.4*(t-0.1)) .*us((t-0.1));

df = 0.02;

[f,X,N,no] = ctft(t,xt,df);

figure(2);
subplot(3,1,1);
plot(t,xt);

subplot(3,1,2);
plot(f,abs(X));
xlim([-2 2]);

subplot(3,1,3);
plot(f,angle(X));
xlim([-2 2]);
