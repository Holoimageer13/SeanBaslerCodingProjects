%Sean Basler
%Lab7 Q2
%***************************
clear all; close all; clc;
%***************************
%a.

dt = 0.002;
T = dt;
t = -1:dt:12;

xt = 0*t + (1/dt) * (t == 0);

a =  0.3/T^2 + 0.4/T + 0.8;
b = -0.6/T^2 - 0.4/T;
c =  0.3/T^2;
d =  0.2/T + 0.9;
e = -0.2/T;

ht(1) = 0;
ht(2) = 0;
for n = 3:size(xt,2)
    ht(n) = (d*xt(n) + e*xt(n-1) - b*ht(n-1) - c*ht(n-2))/a;
end

    
figure(1);
plot(t,ht);

%******************************
%b.
df = 0.001;
[f,Hf,N,no] = ctft(t,ht,df);

figure(2);

subplot(2,1,1);
plot(f,abs(Hf));
xlim([-10 10]);

subplot(2,1,2);
plot(f,angle(Hf));
xlim([-10 10]);

%******************************
%c.

x1t = -3.9*cos(0.2*pi*t-1.5);
x2t = 3.75*cos(0.5*pi*t - 0.6);
x3t = 0.5*cos(1.2*pi*t+ 0.2);

y1t = 4.87*cos(0.2*pi*t -1.5+pi-0.2);
y2t = 5.62*cos(0.5*pi*t - 0.6-1.14);
y3t = 0.15*cos(1.2*pi*t+0.2-2);

figure(3);
subplot(3,1,1);
plot(t,x1t,t,y1t);
xlim([0 10]);

subplot(3,1,2);
plot(t,x2t,t,y2t);
xlim([0 10]);

subplot(3,1,3);
plot(t,x3t,t,y3t);
xlim([0 10]);

%*******************************
%d.
xt = x1t+x2t+x3t;
yt = y1t+y2t+y3t;

figure(4);
plot(t,xt,t,yt);
xlim([0 10]);




