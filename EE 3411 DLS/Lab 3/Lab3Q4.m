%Sean Basler
%Lab3 Q3
%*****************
clear all; close all; clc; 

dt = 0.01;
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

xt = 2 - cos(0.2*pi*t) + 0.25*cos(2*pi*t);

yt = dt * conv(xt,ht);
ty = -2:dt:24;

figure(2);
subplot(2,1,1);
plot(t,xt);
subplot(2,1,2);
plot(ty,yt);
xlim([-2 12]);