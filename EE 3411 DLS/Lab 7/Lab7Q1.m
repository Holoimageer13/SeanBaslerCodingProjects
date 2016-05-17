%Sean Basler
%Lab7 Q1
%***************************
clear all; close all; clc;
%***************************
%a.

dt = 0.001;
t = -0.5:dt:2;
df = 1;

R = 2000;
C = 10e-6;


ht = (1/(R*C)).*exp(-t/(R*C)).*us(t);

[f,Hf,N,no] = ctft(t,ht,df);

j = sqrt(-1);
Hf_analytic = 1 ./ (1+j*2*pi*f*R*C);

figure(1);
subplot(3,1,1);
plot(t,ht);

subplot(3,1,2);
plot(f,abs(Hf),f,abs(Hf_analytic));

subplot(3,1,3)
plot(f,angle(Hf),f,angle(Hf_analytic));

%****************************
%b.

xt1 = -1.5*cos(8*pi*t); 
xt2 = 0.4*cos(40*pi*t);

yt1 = dt * conv(xt1,ht);
yt2 = dt * conv(xt2,ht);
ty = -1:dt:4;

figure(2);
subplot (2,1,1)
plot(t,xt1,ty,yt1);
xlim([-0.5 2]);

subplot (2,1,2)
plot(t,xt2,ty,yt2)
xlim([-0.5 2]);

%*****************************

interval = (t>0) & (t<0.25);
t_interval = t(interval);

[x1_max_value x1_max_loc] = max(xt1(interval));
[y1_max_value y1_max_loc] = max(yt1(interval));

gain2 = y1_max_value/x1_max_value
delay2 = t_interval(y1_max_loc) - t_interval(x1_max_loc)

%*****************************
%c.
interval = (t>-0.02) & (t<0.03);
t_interval = t(interval);

[x2_max_value x2_max_loc] = max(xt2(interval));
[y2_max_value y2_max_loc] = max(yt2(interval));

gain2 = y2_max_value/x2_max_value
delay2 = t_interval(y2_max_loc) - t_interval(x2_max_loc)

