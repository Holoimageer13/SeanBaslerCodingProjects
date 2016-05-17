%Sean Basler
%Lab1 Section 10
%*****************
clc; clear all;

a = [1 0 2.5 -6 7 0 9.2 -1];
b = find(a);
c = find(a > 1);

d = size(a);
e = size(a');
f = size(a,2);

max_value = max(a);
[max_value max_loc] = max(a);
[min_value min_loc] = min(a);

g = mean(a);
h = var(a);

z = zeros(5,3);
o = ones(5,3);

s1 = sum(a);
s2 = sum(o);
s3 = sum(sum(o));

x = 0:5;
y = meshgrid(x,1:4);

%*********************
%Q2
dt = 1/11;
t = 0:dt:1;
xt = 4*cos(2*pi .*t +0.2) + 3*sin(pi^(2).*t);

max_val = max(xt);
min_val = min(xt);
avg = mean(xt);
find(xt > 4);
%********************
%Q3
A = [1,4,3,2;4,1,2,5;3,3,5,1];
%a.
r = size(A,1);
c = size(A,2);
%b.
max_value = max(max(A));
min_value = min(min(A));
%c. 
max_1 = max(A(1,1:4));
max_2 = max(A(2,1:4));
max_3 = max(A(3,1:4));
min_1 = min(A(1,1:4));
min_2 = min(A(2,1:4));
min_3 = min(A(3,1:4));
%d.
avg_1 = mean(A(1:3,1));
avg_2 = mean(A(1:3,2));
avg_3 = mean(A(1:3,3));
%e.
avg = mean(mean(A));







