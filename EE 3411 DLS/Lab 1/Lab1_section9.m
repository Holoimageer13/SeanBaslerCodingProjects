%Sean Basler
%Lab1 Section 9
%*****************
clc; clear all;

for i = 0:2:10
    if(i>5)
        i^2;
    else
        i;
    end
end

i = 0;
while(i <= 10)
     if(i>5)
        i^2;
    else
        i;
     end
    i = i + 2;
end

str = 'abc';

switch str
    case 'yes'
        disp('The answer is yes')
    case 'no'
        disp('The answer is no')
    otherwise
        disp('The answer is unknown')
end
%**********************

dt = 0.2;
t = 0:dt:0.8;

xt = 0;
for k = 1:3
    k;
    xt = t.^(sqrt(1.2*k)) * sqrt(k) + xt;
end

%***********************
for m = 1:3
    for n = 1:3
        y(m,n) = m+n;
    end
end

%***********************
%Q2
for f = 10:5:20
   for t = 0:0.1:0.4
       xt = 3*cos(2*pi*f*t+0.1);
   end
end

xt = 3*cos(2*pi*15*0.3+0.1);

%***********************
%Q3
t = 0;
for w = 35:5:45
    while((t^3 < 10) && (exp(1.2)*cos(w*t) < 10))
        t = t + 0.1;
    end
    disp(t);
end
%***********************
%Q4
for t = -1:0.2:1
    xt = exp(-abs(t));
end

t = -1:0.2:1;
xt = exp(-abs(t));

for t = -1:0.0002:1
    xt = exp(-abs(t));
end

t = -1:0.0002:1;
xt = exp(-abs(t));
