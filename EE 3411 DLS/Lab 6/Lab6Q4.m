%Sean Basler
%Lab6 Q4
%***************************
clear all; close all; clc;
%***************************

load tyo.mat
fs = 1/T;

t = 0:T:(length(tyo)-1)*T;
figure(1);
plot(t,tyo);

dfm = 1;
[f,X,N,no] = ctft(t,tyo,dfm);

figure(2);
plot(f,abs(X));
xlim([0 fs/2]);

soundsc(tyo,fs);