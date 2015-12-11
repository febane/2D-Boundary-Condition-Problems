/**
 * O Contornador
 * contorno.c
 * Tratamento de condicoes de contorno
 * Ver relatorio para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 * @version 1.0
 * 
 */


#include "contorno.h"


void contorna(double a, double b, double c, double xmin, double xmax, double ymin, double ymax, int divx, int divy, int tam, double valores[]){
	
	int i;
	double hx, hy, A, B, C, D, E, v[tam];
	FILE *arquivo;
	
	arquivo = fopen("intermidiate.txt", "w");
	
	if(arquivo == NULL) {
		
		printf("Oops. Erro ao acessar intermidiate.txt\n");
		return;
		
	}
	
	hx = (xmax-xmin)/(divx+1);
	hy = (ymax-ymin)/(divy+1);
	
	D = -1/(hy*hy)-b/(2*hy);
	B = -1/(hx*hx)-a/(2*hx);
	A = c+2*(1/(hx*hx)+1/(hy*hy));
	C = -1/(hx*hx)+a/(2*hx);
	E = -1/(hy*hy)+b/(2*hy);
	
	fprintf(arquivo, "%d %d %d\n", tam, tam, 5*tam-2*(divx+1));
	
	fprintf(arquivo, "%d %d %g\n", 1, 1, A);
	fprintf(arquivo, "%d %d %g\n", 1, 2, C);
	fprintf(arquivo, "%d %d %g\n", 1, 1+divx, E);
	
	for(i=2;i<=divx;i++){
		
		if(i<divy*divx && (i-1)%(int)divx==0)
			fprintf(arquivo, "%d %d %g\n", i, i-1, 0.0);
		else
			fprintf(arquivo, "%d %d %g\n", i, i-1, B);
		
		fprintf(arquivo, "%d %d %g\n", i, i, A);
		
		if(i<divy*divx && i%(int)divx==0)
			fprintf(arquivo, "%d %d %g\n", i, i+1, 0.0);
		else
			fprintf(arquivo, "%d %d %g\n", i, i+1, C);
		
		fprintf(arquivo, "%d %d %g\n", i, i+divx, E);
		
	}
	
	for(i=divx+1;i<=tam-divx;i++){
		
		fprintf(arquivo, "%d %d %g\n", i, i-divx, D);
		
		if(i<divy*divx && (i-1)%(int)divx==0)
			fprintf(arquivo, "%d %d %g\n", i, i-1, 0.0);
		else
			fprintf(arquivo, "%d %d %g\n", i, i-1, B);
		
		fprintf(arquivo, "%d %d %g\n", i, i, A);
		
		if(i<divy*divx && i%(int)divx==0)
			fprintf(arquivo, "%d %d %g\n", i, i+1, 0.0);
		else
			fprintf(arquivo, "%d %d %g\n", i, i+1, C);
		
		fprintf(arquivo, "%d %d %g\n", i, i+divx, E);
		
	}
	
	for(i=tam-divx+1;i<=tam-1;i++){
		
		fprintf(arquivo, "%d %d %g\n", i, i-divx, D);
		
		if(i<divy*divx && (i-1)%(int)divx==0)
			fprintf(arquivo, "%d %d %g\n", i, i-1, 0.0);
		else
			fprintf(arquivo, "%d %d %g\n", i, i-1, B);
		
		fprintf(arquivo, "%d %d %g\n", i, i, A);
		
		if(i<divy*divx && i%(int)divx==0)
			fprintf(arquivo, "%d %d %g\n", i, i+1, 0.0);
		else
			fprintf(arquivo, "%d %d %g\n", i, i+1, C);
		
	}
	
	fprintf(arquivo, "%d %d %g\n", tam, tam-divx, D);
	fprintf(arquivo, "%d %d %g\n", tam, tam-1, B);
	fprintf(arquivo, "%d %d %g\n", tam, tam, A);
	
	for(i=0;i<tam;i++){
		
		//v[i]=0.0;
		
		v[i] = f(xmin+hx*(i%divx),ymin+hy*(i/divx));
		
	}
	
	for(i=1;i<=divx;i++){
		
		v[i-1] -= D*valores[i];
		v[(divy-1)*divx+i-1] -= E*valores[divx+2+2*divy+i];
		
	}
	
	for(i=1;i<=divy;i++){
		
		v[divx*(i-1)] -= B*valores[divx+i+1];
		v[divx*i-1] -= C*valores[divx+divy+i+1];
		
	}
	
	for(i=0;i<tam;i++)
		fprintf(arquivo, "%g\n", v[i]);
	
	fclose(arquivo);
	
}

double f(double x, double y){
	
	return -(exp(x*y)*x*sin(M_PI*x)*((x*x-M_PI*M_PI)*cos(M_PI*y)-2*M_PI*x*sin(M_PI*y)) - exp(x*y)*cos(M_PI*y)*((x*(M_PI*M_PI-y*y)-2*y)*sin(M_PI*x)-2*M_PI*(x*y+1)*cos(M_PI*x))) + 60*exp(x*y)*cos(M_PI*y)*((x*y+1)*sin(M_PI*x)+M_PI*x*cos(M_PI*x)) + 80*exp(x*y)*x*sin(M_PI*x)*(x*cos(M_PI*y)-M_PI*sin(M_PI*y)) - 40*x*exp(x*y)*sin(M_PI*x)*cos(M_PI*y);
	
}
