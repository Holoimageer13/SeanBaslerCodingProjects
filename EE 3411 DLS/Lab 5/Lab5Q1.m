%Sean Basler
%Lab5 Q1
%***************************
clear all; close all; clc;

%***************************
%a (b on paper)
dt = 0.0005;
t = -0.75:dt:0.75;

xt = 10*cos(24*pi*t-1.2) ...
     -8*cos(28*pi*t+1.0)...
     +4*sin(36*pi*t+2.5);
figure(1);
plot(t,xt);
 
%****************************
%c
dt = 0.0005;
t = -0.25:dt:0.25-dt;

xt = 10*cos(24*pi*t-1.2) ...
     -8*cos(28*pi*t+1.0)...
     +4*sin(36*pi*t+2.5);

[Xn,f,ang,No,Fo] = ctfsc(t,xt);
 
figure(2);
subplot(2,1,1);
stem(f,abs(Xn));
xlim([-30,30]);

subplot(2,1,2);
stem(f,ang);
xlim([-30,30]);

%****************************
%d
dt = 0.0005;
t = 0:dt:0.25-dt;

xt = 10*cos(24*pi*t-1.2) ...
     -8*cos(28*pi*t+1.0)...
     +4*sin(36*pi*t+2.5);

[Xn,f,ang,No,Fo] = ctfsc(t,xt);
 
figure(3);
subplot(2,1,1);
stem(f,abs(Xn));
xlim([-30,30]);

subplot(2,1,2);
stem(f,ang);
xlim([-30,30]);

%****************************
%e
dt = 0.0005;
t = -0.2:dt:0.1995;

xt = 10*cos(24*pi*t-1.2) ...
     -8*cos(28*pi*t+1.0)...
     +4*sin(36*pi*t+2.5);

[Xn,f,ang,No,Fo] = ctfsc(t,xt);
 
figure(4);
subplot(2,1,1);
stem(f,abs(Xn));
xlim([-30,30]);

subplot(2,1,2);
stem(f,ang);
xlim([-30,30]);

%****************************
%f

dt = 0.0005;
t = -0.25:dt:0.25-dt;

xt = 10*cos(24*pi*t-1.2) ...
     -8*cos(28*pi*t+1.0)...
     +4*sin(36*pi*t+2.5);

[Xn,f,ang,No,Fo] = ctfsc(t,xt);
N = 8;
[xfs,Xnn] = ctfs(t,Xn,No,Fo,N);

figure(5);
subplot(3,1,1);
stem(f(No-N:No+N),abs(Xnn));
xlim([-30,30]);

subplot(3,1,2);
plot(t,xfs);

subplot(3,1,3);
plot(t,xt);






 