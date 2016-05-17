%Sean Basler
%Lab4 Q2
%*****************
clear all; close all; clc;

freq = [-11.5 -6 -0.75 0 0.75 6 11.5];
amp = [2.1 2.4 4.2 1.3 4.2 2.4 2.1];
phase = [((-pi/2)-2.8) (1.3-(pi/2)) (0.45) (pi) (-0.45) ((-pi/2)-1.3)...
        (2.8-(pi/2))];
    
figure(1);

subplot(2,1,1);
stem(freq, amp);

subplot(2,1,2);
stem(freq, phase);

%*****************

freq = [0 0.75 6 11.5];
amp = [1.3 8.4 4.8 4.2];
phase = [pi -0.85 -pi/2-1.3 2.8-pi/2];

figure(2);

subplot(2,1,1);
stem(freq, amp);

subplot(2,1,2);
stem(freq, phase);