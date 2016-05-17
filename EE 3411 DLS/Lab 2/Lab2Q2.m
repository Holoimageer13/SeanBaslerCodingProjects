%Sean Basler
%Lab2 Q2
%*****************
clc; clear all; close all;

dt = 0.1;
t = -4:dt:8;

xt = 2*us(t+2.5) + 2*ur(t+2) - 10*us(t+1) - ur(t) - ur(t-1)...
     + us(t-1) + 0.5*ur(t-2.5) - 0.5*ur(t-6.6);
 
 figure(1);
 plot(t,xt);