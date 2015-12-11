function[valor] = f(x, y)
	valor = -(exp(x*y)*x*sin(pi*x)*((x*x-pi*pi)*cos(pi*y)-2*pi*x*sin(pi*y)) - exp(x*y)*cos(pi*y)*((x*(pi*pi-y*y)-2*y)*sin(pi*x)-2*pi*(x*y+1)*cos(pi*x))) + 60*exp(x*y)*cos(pi*y)*((x*y+1)*sin(pi*x)+pi*x*cos(pi*x)) + 80*exp(x*y)*x*sin(pi*x)*(x*cos(pi*y)-pi*sin(pi*y)) - 40*x*exp(x*y)*sin(pi*x)*cos(pi*y);
end
