function main
	printf("Bem-vindo ao programa de Solucao de Problemas de\nValor de Contorno Bidimensionais!\n\n");
	printf("Como gostaria de inserir os dados de entrada?\n\n");
	printf("1 - Via teclado\n");
	printf("2 - Via arquivo de entrada\n\n");
	
	option = input("");
	
	switch(option)
		case 1
			a = input("\nInsira o coeficiente a: ");
			b = input("Insira o coeficiente b: ");
			c = input("Insira o coeficiente c: ");
			
			printf("\nInsira a grade do dominio, no seguinte formato:\n");
			printf("[xmin xmax ymin ymax n m] (onde n e m sao as dimensoes da grade)\n");
			grade = input("Os colchetes sao necessarios.\n");
			
			xmin = grade(1);
			xmax = grade(2);
			ymin = grade(3);
			ymax = grade(4);
			
			n = grade(5);
			m = grade(6);
			
			hx = (xmax - xmin)/(n-1);
			hy = (ymax - ymin)/(m-1);
			
			N = (n-2)*(m-2);
			contorno = n*m - (n-2)*(m-2);
			
			printf("\nAgora nos informe sua f(x,y):\n");
			printf("1 - f(x, y) = 0\n");
			printf("2 - f(x, y) tal que u(x, y) = x*exp(x*y)*sin(pi*x)*cos(pi*y)\n");
			f = input("");
			
			printf("\nComo deseja inserir os valores de contorno?\n");
			printf("1 - Todos os valores, num vetor, no formato da grade de dominio.\n");
			printf("2 - Apenas um valor, que vai ser constante em todo o contorno\n");
			printf("3 - Aplicar a u(x, y) = x*exp(x*y)*sin(pi*x)*cos(pi*y) no contorno.\n");
			formato = input("");
			
			switch(formato)
				case 1
					printf("\nInsira os %d valores de contorno:\n", contorno);
					valores = input("");
					valores = valores';
					
				case 2
					num = input("\nInsira o valor que gostaria de ter em todo o contorno:\n");
					valores = zeros(contorno, 1) .+ num;
					valores
			
				case 3
					valores = aplicarContorno(grade);
			end
			
			printf("\nComo deseja que o sistema linear seja solucionado?\n");
			printf("1 - Pelo metodo iterativo SOR (Succesive Over-Relaxation)\n");
			printf("2 - Pelo metodo exato de eliminacao de Gauss\n\n");
			metodo = input("");
			
			printf("\nComo deseja a solucao do sistema:\n");
			printf("1 - Impresso na tela\n");
			printf("2 - No arquivo de saida: saida.txt\n\n");
			output = input("");
			
			if(metodo == 1)
				tol = input("\nInforme a tolerancia desejada na funcao sor.\n");
				kmax = input("Informe o numero maximo de iteracoes.\n");
				w = input("Informe o fator de relaxacao.\n");
			endif
			
		case 2
			printf("\nPara informacoes sobre o formato do arquivo de entrada, veja a secao 2.2.1 da documentacao.\n");
			arquivo = input("Insira o nome do arquivo de entrada:\n", "s");
			entrada = fopen(arquivo, "r");
			a = fscanf(entrada, "%f", 1);
			b = fscanf(entrada, "%f", 1);
			c = fscanf(entrada, "%f", 1);
			
			grade = fscanf(entrada, "%f", 6);
			
			xmin = grade(1);
			xmax = grade(2);
			ymin = grade(3);
			ymax = grade(4);
			
			n = grade(5);
			m = grade(6);
			
			hx = (xmax - xmin)/(n-1);
			hy = (ymax - ymin)/(m-1);
			
			N = (n-2)*(m-2);
			contorno = n*m - (n-2)*(m-2);
			
			f = fscanf(entrada, "%d", 1);
			formato = fscanf(entrada, "%d", 1);
			
			switch(formato)
				case 1
					valores = fscanf(entrada, "%f", contorno);
					
				case 2
					num = fscanf(entrada, "%f", 1);
					valores = zeros(contorno, 1) .+ num;
			
				case 3
					valores = aplicarContorno(grade);
			end
			
			metodo = fscanf(entrada, "%d", 1);
			output = fscanf(entrada, "%d", 1);
			
			if(metodo == 1)
				tol = fscanf(entrada, "%f", 1);
				kmax = fscanf(entrada, "%d", 1);
				w = fscanf(entrada, "%f", 1);
			endif
			
			fclose(entrada);
	end
	
	[S, coef] = montarMatriz(a, b, c, grade);
			
	vetor = vetorIndependente(f, grade);
	vetor = tratarContorno(vetor, valores, coef, n, m);
	
	switch(metodo)
		case 1
			# Resolvendo por SOR
			
			[solucao, iter, erro, tempo] = sor(S, vetor, N, tol, kmax, w);
			
			iter
			erro
			tempo
			
		case 2
			# Resolvendo pela elimGauss (built-in)
			tic;
			solucao = S\vetor;
			tempo = toc;
			tempo
	end
	
	switch(output)
		case 1
			solucao
		case 2
			saida = fopen("saida.txt", "w");
			for i = 1:N
				fprintf(saida, "%f\n", solucao(i));
			end
			fclose(saida);
	end
	
	for i = 1:m-2
		for j = 1:n-2
			matriz(i, j) = solucao((i-1)*(n-2) + j);
		end
	end
	
	gridX = xmin+hx:hx:xmax-hx;
	gridY = ymin+hy:hy:ymax-hy;
	
	for i = 1:m-2
		for j = 1:n-2
			matrizSol(i, j) = u(gridX(j), gridY(i));
		end
	end
	
	surf(gridX, gridY, matriz);
	# surf(gridX, gridY, matrizSol);
end

