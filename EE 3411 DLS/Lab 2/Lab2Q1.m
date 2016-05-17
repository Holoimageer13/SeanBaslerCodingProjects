%Sean Basler
%Lab2 Q1
%*****************
clc; clear all; close all;

dt = 0.001;
t = -0.1:dt:0.1;
it1 = 2.4*cos(15*pi*t-0.8);
it2 = 4.2*cos(15*pi*t-1.9);
it3 = it1 + it2;

figure(1);
plot(t,it1,t,it2,t,it3);
legend('it1','it2','it3');

%*****************
[m1, loc1] = max(it1(t>0));
[m2, loc2] = max(it2(t>0));
[m3, loc3] = max(it3(t>0));

dyl1 = loc1*m1;
dyl2 = loc2*m2;
dyl3 = loc3*m3;
