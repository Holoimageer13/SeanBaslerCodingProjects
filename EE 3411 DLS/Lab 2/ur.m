function y = ur(t)
%unit ramp function

y = 0 .* (t < 0) + t .* (t >= 0);