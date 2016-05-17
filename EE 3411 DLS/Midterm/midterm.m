%Sean Basler Midterm Exam
close all; clear all; clc;

%%part-a
dt = 0.001;
t = -0.1:dt:0.1;

x1 = 2*cos(40*pi*t+0.4);
x2 = 3*sin(30*pi*t-0.3);
mx = x1 .* x2;

figure(1);
hold on;
plot(t,x1,t,x2,t,mx);
title('Part-a');
legend('x1','x2','x1*x2');
xlim([-0.1 0.1]);
xlabel('t')
ylabel('function output');

%%part-b and part-c
dt = 0.001;
t = -0.1:dt:0.1;
T = dt;

a = 0.0011;

xt = (t == 0) .* 1; 

yt = zeros(size(xt));

for n = 2:size(xt,2)
    yt(1,n) = (1/((a/T)+1)) * ((a/T)*(xt(n)-xt(n-1)+yt(n-1)));
end

x1 = sin(10*pi*t);
x2 = sin(100*pi*t);
x3 = sin(200*pi*t);
x4 = sin(300*pi*t);
x5 = sin(400*pi*t);
x6 = sin(500*pi*t);
x7 = sin(600*pi*t);
ty = -0.2:dt:0.2;
figure(2);

subplot(7,1,1);
plot(ty,conv(yt, x1)); 
title('part-c: sin(10*pi*t)');
xlabel('t');
ylabel('response');

subplot(7,1,2);
plot(ty,conv(yt, x2));
title('sin(100*pi*t)');
xlabel('t');
ylabel('response');

subplot(7,1,3);
plot(ty,conv(yt, x3));
title('sin(200*pi*t)');
xlabel('t');
ylabel('response');

subplot(7,1,4);
plot(ty,conv(yt, x4));
title('sin(300*pi*t)');
xlabel('t');
ylabel('response');

subplot(7,1,5);
plot(ty,conv(yt, x5));
title('sin(400*pi*t)');
xlabel('t');
ylabel('response');

subplot(7,1,6);
plot(ty,conv(yt, x6));
title('sin(500*pi*t)');
xlabel('t');
ylabel('response');

subplot(7,1,7);
plot(ty,conv(yt, x7));
title('sin(600*pi*t)');
xlabel('t');
ylabel('response');


%%part-d
freq = [ 5 50 100 150 200 250 300];
amp = [ 0.5 0.5 0.5 0.5 0.5 0.5 0.5];

figure(3);
stem(freq,amp);
title('part-d');
xlabel('freq');
ylabel('amp');

%%part-e and part-f
freq = [ 10 50 83 125 166 250 333 ];
amp = [ .035 .3 .48 .58 .63 .64 .66 ];

figure(4);
stem(freq,amp);
title('part-e');
xlabel('freq');
ylabel('amp');

