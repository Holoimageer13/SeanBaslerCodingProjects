%Sean Basler
%Lab5 Q2
%*****************
clear all; close all; clc;

dt = 0.0005;
t = -0.75:dt:0.75;

xt = 10*cos(24*pi*t-1.2) ...
     -8*cos(28*pi*t+1.0)...
     +4*sin(36*pi*t+2.5);

 [Xn,f,ang,No,Fo] = ctfsc(t,xt);
 
 factor = 0.707;
 BW = abs(Xn) >= factor*max(abs(Xn));
 
 
 figure(1);
 stem(f(BW),abs(Xn(BW)));
 