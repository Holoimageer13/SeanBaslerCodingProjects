%Sean Basler
%Lab2 Q4
%*****************
clc; clear all; close all;

dt = 0.001;
t = 0.6:dt:1.6;

xt = t .* (us(t-0.8) - us(t-1.1));



R = 2e3; %2kohm
C = 10e-6; %10 uF
T = dt;

yt(1) = 0;

for n = 2:size(xt,2)
    yt(n) = (((T/2)*(xt(n)+xt(n-1)-yt(n-1))) + R*C*yt(n-1))/...
             (R*C+(T/2));
    %yt(n) = ((xt(n)+xt(n-1)+ yt(n-1))/(1+R*C));
    
    %yt(n+1) = 40*(xt(n)+xt(n-1)-yt(n)) * (T/(2*R*C))...
    %         * (1/(1+(T/(2*R*C)))); %changed to integral equation
end

figure(1);
hold on;
plot(t,xt,'b');
plot(t,yt(1:end),'r');