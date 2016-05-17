%Sean Basler
%Lab5 Q3
%*****************
clear all; close all; clc;

dt = 0.002;
t1 = -2:dt:2-dt;

x1t = 0*t1 + (0.1+2*cos(2*pi*t1)) .* (-1.2 <= t1 & t1 < 1.2);

figure(1);
plot(t1,x1t)

%**************************
%a

t = -6:dt:6-dt;
xt = [x1t x1t x1t];

figure(2);
plot(t,xt);

%***************************
%b

[Xn,f,ang,No,Fo] = ctfsc(t,xt);

N = 20;
BW = (f >= -N*Fo) & (f < N*Fo);

figure(3);
subplot(2,1,1);
stem(f(BW),abs(Xn(BW)));

subplot(2,1,2);
stem(f(BW),ang(BW));

actual_pwr = sum(xt .^ 2)/length(xt)
sim_pwr = sum(abs(Xn(BW)) .^ 2)
percentage = (sim_pwr/actual_pwr)*100
%***************************
%c
[Xn,f,ang,No,Fo] = ctfsc(t,xt);

factor = [.02 .1 .2];
for ii = 1:length(factor)
    BW = abs(Xn) >= factor(ii)*max(abs(Xn));

    figure;
    subplot(2,1,1);
    stem(f(BW),abs(Xn(BW)));

    subplot(2,1,2);
    stem(f(BW),ang(BW));

    actual_pwr = sum(xt .^ 2)/length(xt)
    sim_pwr = sum(abs(Xn(BW)) .^ 2)
    percentage = (sim_pwr/actual_pwr)*100
end

