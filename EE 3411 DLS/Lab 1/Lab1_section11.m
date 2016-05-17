%Sean Basler
%Lab1 Section 11
%*****************
clc; clear all; close all; 

dt = 0.1;
t = 0:dt:10;
f1 = 0.2;
f2 = 0.425;

[s1 s2 s3] = sumsin(t,f1,f2);

figure(1);
hold on;
plot(t,s1);
plot(t,s2,'r');
plot(t,s3,'g');
hold off;
grid on;

legend('s1','s2','s3');
xlabel('time (sec) ');
ylabel('Amplitude (v) ');
title('2 sine waves and their sum');
text(1,-1.5,'description');
axis([3 6 -4 4]);

%******************************
figure(2);
plot(t,s1,t,s2,t,s3);
legend('s1','s2','s3');
xlabel('time (sec) ');
ylabel('Amplitude (v) ');
title('2 sine waves and their sum');
text(1,-1.5,'description');

%*******************************
figure(3);

subplot(3,1,1);
plot(t,s1);
xlabel('time (sec) ');
ylabel('Amplitude (v) ');

subplot(3,1,2);
plot(t,s2);
xlabel('time (sec) ');
ylabel('Amplitude (v) ');

subplot(3,1,3);
plot(t,s3);
xlabel('time (sec) ');
ylabel('Amplitude (v) ');
