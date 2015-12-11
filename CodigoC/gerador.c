#include <stdio.h>
#include <math.h>

double u(double x, double y){
	
	return x*exp(x*y)*sin(M_PI*x)*cos(M_PI*y);
	
}

int main(){
	
	char buf[100];
	double a, xmin, xmax, ymin, ymax, hx, hy;
	int divx, divy, i;
	
	printf("Gere entrada com contorno de uma função mucho loca!\n");
	
	printf("Entre com o nome do arquivo: ");
	
	scanf("%s", buf);
	
	FILE *arquivo;
	
	arquivo = fopen(buf, "w");
	
	printf("Entre com a, b, c, xmin, ymin, xmax, ymax, divx e divy nessa ordem separados por espaço: ");
	
	scanf("%lf", &a);
	
	fprintf(arquivo, "%g ", a);
	
	scanf("%lf", &a);
	
	fprintf(arquivo, "%g ", a);
	
	scanf("%lf", &a);
	
	fprintf(arquivo, "%g\n", a);
	
	scanf("%lf", &xmin);
	
	fprintf(arquivo, "%g ", xmin);
	
	scanf("%lf", &ymin);
	
	fprintf(arquivo, "%g ", ymin);
	
	scanf("%lf", &xmax);
	
	fprintf(arquivo, "%g ", xmax);
	
	scanf("%lf", &ymax);
	
	fprintf(arquivo, "%g\n", ymax);
	
	scanf("%d", &divx);
	
	fprintf(arquivo, "%d ", divx);
	
	scanf("%d", &divy);
	
	fprintf(arquivo, "%d\n", divy);
	
	hx = (xmax-xmin)/divx;
	hy = (ymax-ymin)/divy;
	
	for(i=0;i<divx;i++)
		fprintf(arquivo, "%g\n", u(xmin+i*hx, ymin));
	
	for(i=1;i<divy;i++)
		fprintf(arquivo, "%g\n", u(xmin, ymin+i*hy));
	
	for(i=1;i<divy;i++)
		fprintf(arquivo, "%g\n", u(xmax, ymin+i*hy));
	
	for(i=1;i<divx-1;i++)
		fprintf(arquivo, "%g\n", u(xmin+i*hx, ymax));
	
	return 0;
	
}
