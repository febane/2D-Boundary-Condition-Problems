function[M, coef] = montarMatriz(a, b, c, grade)
	xmin = grade(1);
	xmax = grade(2);
	ymin = grade(3);
	ymax = grade(4);
	n = grade(5);
	m = grade(6);

  	hx = (xmax - xmin)/(n-1);
 	hy = (ymax - ymin)/(m-1);
  
  	n = n-2;
  	m = m-2;
  
  	N = n*m;
  
  	A = c + 2*(1/(hx*hx) + 1/(hy*hy));
  	B = (-1/(hx*hx)) - a/(2*hx);
  	C = (-1/(hx*hx)) + a/(2*hx);
  	D = (-1/(hy*hy)) - b/(2*hy);
  	E = (-1/(hy*hy)) + b/(2*hy);
	
	coef = [A, B, C, D, E];
  
  	M = sparse(N, N);
  
  	for i = 1:N
    	M(i, i) = A;
  	end
  
  	for i = 2:N;
    	M(i, i-1) = B;
    	M(i-1, i) = C;
  	end
  
  	for i = n+1:N;
    	M(i, i-n) = D;
    	M(i-n, i) = E;
  	end
	
	# tratando o contorno
	for i = 1:m-1
		M(n*i, n*i + 1) = 0;
		M(n*i + 1, n*i) = 0;
	end
end

