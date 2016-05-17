%Sean Basler
%Lab4 Q3
%*****************
clear all; close all; clc;

dt = 0.01;
T = dt;
t = -22:dt:10;

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

x1t = -3.9*cos(0.2*pi*t-1.5);
x2t = 3.75*cos(0.5*pi*t-0.6);
x3t = 0.5*cos(1.2*pi*t+0.2);

y1t = dt *conv(x1t,ht);
y2t = dt *conv(x2t,ht);
y3t = dt *conv(x3t,ht);
ty = -44:dt:20;

figure(2);
subplot(3,1,1);
plot(t,x1t,ty,y1t);
legend('x1t','y1t');
xlim([-10 10]);

subplot(3,1,2);
plot(t,x2t,ty,y2t);
legend('x2t','y2t');
xlim([-10 10]);

subplot(3,1,3);
plot(t,x3t,ty,y3t);
legend('x3t','y3t');
xlim([-10 10]);

%********************

max_x1 = max(x1t);
max_x2 = max(x2t);
max_x3 = max(x3t);

max_y1 = max(y1t);
max_y2 = max(y2t);
max_y3 = max(y3t);

freq = [-0.6 -0.25 -0.1 0.1 0.25 0.6];
amp_x = [max_x3/2 max_x2/2 max_x1/2 max_x1/2 max_x2/2 max_x3/2];
amp_y = [max_y3/2 max_y2/2 max_y1/2 max_y1/2 max_y2/2 max_y3/2];

figure(3);

subplot(2,1,1);
stem(freq,amp_x);
xlim([-1 1]);

subplot(2,1,2);
stem(freq,amp_y);
xlim([-1 1]);

%********************
factor = 0.2;
BW = freq(amp_y > max(amp_y)*factor)


