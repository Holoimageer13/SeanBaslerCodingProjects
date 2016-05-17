function y = tri(t)
%tri => triangular function

y = 0*t + (1-abs(t)) .* (abs(t) < 1);