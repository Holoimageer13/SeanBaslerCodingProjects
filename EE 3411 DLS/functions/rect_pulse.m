function y = rect_pulse(t)
% rect_pulse => rectangular pulse

y = us(t+1/2) - us(t-1/2);