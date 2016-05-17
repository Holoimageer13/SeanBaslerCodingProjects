%Sean Basler
%Lab6 Q2
%***************************
clear all; close all; clc;
%***************************
%a.
dt = 0.05;
t = -15:dt:15;

df = 0.01;
f = -10:dt:10;

xt = 0.6*(sinc(0.3*t)).^2;
Xf = 2*tri(f/0.3);

figure(1);
subplot(2,1,1);
plot(t,xt);

subplot(2,1,2);
plot(f,abs(Xf));

%****************************
%b.
trunc = abs(t) <= 10;
t_trunc = t(trunc);
xt_trunc = xt(trunc);

[f_trunc,X_trunc,N,no] = ctft(t_trunc,xt_trunc,df);

figure(2);
subplot(2,1,1);
plot(t,xt,t_trunc,xt_trunc);

subplot(2,1,2);
plot(f,abs(Xf),f_trunc,abs(X_trunc));
xlim([-1 1]);

%****************************
%c.
trunc = abs(t) <= 6;
t_trunc = t(trunc);
xt_trunc = xt(trunc);

[f_trunc,X_trunc,N,no] = ctft(t_trunc,xt_trunc,df);

figure(3);
subplot(2,1,1);
plot(t,xt,t_trunc,xt_trunc);

subplot(2,1,2);
plot(f,abs(Xf),f_trunc,abs(X_trunc));
xlim([-1 1]);

%****************************
%d.
trunc = abs(t) <= 4;
t_trunc = t(trunc);
xt_trunc = xt(trunc);

[f_trunc,X_trunc,N,no] = ctft(t_trunc,xt_trunc,df);

figure(4);
subplot(2,1,1);
plot(t,xt,t_trunc,xt_trunc);

subplot(2,1,2);
plot(f,abs(Xf),f_trunc,abs(X_trunc));
xlim([-1 1]);

%****************************
%e. truncation increases, the accuracy of the matching signals decrease

