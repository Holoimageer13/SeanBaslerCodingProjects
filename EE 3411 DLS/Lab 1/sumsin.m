function [s1 s2 s3] = sumsin(t,f1,f2)

s1 = sin(2*pi*f1*t);
s2 = sin(2*pi*f2*t);
s3 = s1+s2;