function y = us(t)
%unit step function

y = 0 .* (t < 0) + 1 .* (t >= 0);