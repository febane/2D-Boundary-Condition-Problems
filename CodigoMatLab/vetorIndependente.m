function[v] = vetorIndependente(funcao, grade)
	n = grade(5);
	m = grade(6);
	
	N = (n-2)*(m-2);
	
	switch(funcao)
		case 1
			v = zeros(N, 1);
		case 2
			xmin = grade(1);
			xmax = grade(2);
			ymin = grade(3);
			ymax = grade(4);
			
			hx = (xmax - xmin)/(n-1);
			hy = (ymax - ymin)/(m-1);

			y = ymin;
			
			n = n-2;
			m = m-2;
			
			v = zeros(N, 1);
			
			for i = 1:m
				x = xmin;
				y = y + hy;
				for j = 1:n
					x = x + hx;
					v(n*(i-1) + j) = f(x, y);
				end
			end
	end
end

