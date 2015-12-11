function[valores] = aplicarContorno(grade)
	xmin = grade(1);
	xmax = grade(2);
	ymin = grade(3);
	ymax = grade(4);
	n = grade(5);
	m = grade(6);
	
	hx = (xmax - xmin)/(n-1);
	hy = (ymax - ymin)/(m-1);

	# Embaixo
	for i = 1:n
		x = xmin + (i-1)*hx;
		valores(i) = u(x, ymin);
	end
	
	# Nas laterais
	for i = 1:m-2
		y = ymin + i*hy;
		valores(n+i) = u(xmin, y);
		valores(n+(m-2)+i) = u(xmax, y);
	end
	
	# Em cima
	for i = 1:n
		x = xmin + (i-1)*hx;
		valores(n+2*(m-2)+i) = u(x, ymax);
	end
end

