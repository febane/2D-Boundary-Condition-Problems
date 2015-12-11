function[v] = tratarContorno(v, valores, coef, n, m);
	A = coef(1);
	B = coef(2);
	C = coef(3);
	D = coef(4);
	E = coef(5);
	
	n = n-2;
	m = m-2;
	
	for i = 1:n
		inic = 1;
		v(i) = v(i) - D*valores(inic+i);
		inic = n+2+2*m+1;
		v((m-1)*n + i) = v((m-1)*n + i) - E*valores(inic+i);
	end
	
	for j = 1:m
		inic = n+2;
		v(n*(j-1) + 1) = v(n*(j-1) + 1) - B*valores(inic+j);
		inic = n+m+2;
		v(n*j) = v(n*j) - C*valores(inic+j);
	end
end

