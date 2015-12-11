/**
 * O Contornador
 * main.c
 * Arquivo Principal para a Resolucao
 * de Sistemas Lineares Esparsos
 * Ver relatorio para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 * @version 1.0
 * 
 */


#include <stdio.h>
#include <string.h>
#include <time.h>
#include "leitura.h"
#include "gauss.h"
#include "sor.h"
#include "contorno.h"


int main(int argc, char *argv[]) {
	
	int o, algo, divx, divy, tam, i;
	double a, b, c, xmin, xmax, ymin, ymax, toler, omega;
	double Elapsed_Time;
	struct timespec Start, End;
	
	printf("Prezado(a) senhor(a), e com imensa satisfacao que apresento o Contornador\nO Contornador esta aqui para ajuda-lo a discretizar uma equacao diferencial de duas dimensoes pelo metodo de diferencas finitas e resolver o sistema linear resultante.\n");
	
	while(1){
		
		printf("O(A) senhor(a) possui alguma preferencia para solucao do sistema linear resultante?\nHoje temos as seguintes opcoes no cardapio, digite o numero correspondente para escolhe-la:\n1\tGauss, por favor\n2\tSOR mal-passado\n3\tOnde fica o toilet?\n4\tSo estou aqui pela zueira\n");
		
		scanf("%o", &o);
		
		if(o==1){
			
			algo = 0;
			break;
			
		}
		else if(o==2){
			
			printf("Entre com a tolerancia e fator de relaxacao separados por espaco:\n");
			scanf("%lf %lf", &toler, &omega);
			
			algo = 1;
			break;
			
		}
		else if(o==3)
			printf("Onde vossa senhoria quiser.\n");
		else if(o==4)
			while(1)
				printf("HUE");
		
	}
	
	printf("Boa pedida, Sr(a).\n");
	
	while(1){
		
		printf("O(A) senhor(a) gostaria de entrar com os dados atraves do teclado (stdin) ou atraves de um arquivo de entrada?\nDigite:\n1\tPara entrada de dados atraves do teclado (stdin)\n2\tPara entrada de dados atraves de um arquivo\n3\tPara falar com um de nossos atendentes\n4\tPara sair do programa\n");
		
		scanf("%d", &o);
		
		if(o==1){
			
			printf("Por favor, entre com os valores de a, b e c separados por espaco:");
			scanf("%lf %lf %lf", &a, &b, &c);
			
			printf("Valeu lek, agora passa ae os valores minimos das abscissas e ordenadas e, em seguida, os maximos dos eixo, tudo respectivamente. Fecha com noix bro, paz e amor.\n");
			
			scanf("%lf %lf %lf %lf", &xmin, &ymin, &xmax, &ymax);
			
			printf("Com licenca, poderia eu te pedir mais uma coisa? Faltou quantas divisoes o(a) senhor(a) quer coisar a matriz nos eixos x e y. Digite aqui plz :) de preferencia que eles sejam iguais.\n");
			scanf("%d %d", &divx, &divy);
			
			divx -= 2;
			divy -= 2;
			
			double valores[2*(divx+divy)+4];
			
			tam = divx*divy;
			
			printf("Agradeco a paciencia. Por favor, entre com os valores de contorno:\n");
			
			for(i=0;i<2*(divx+divy)+4;i++)
				scanf("%lf", &valores[i]);
			
			clock_gettime(CLOCK_MONOTONIC, &Start);
			
			contorna(a, b, c, xmin, xmax, ymin, ymax, divx, divy, tam, valores);
			
			Coluna *matriz = le_matriz("intermidiate.txt", &tam, algo);
			
			if(matriz == NULL)
					return 2;
			
			clock_gettime(CLOCK_MONOTONIC, &End);
			Elapsed_Time = End.tv_sec - Start.tv_sec + 1e-9*(End.tv_nsec-Start.tv_nsec);
			printf("O tempo de construcao do sistema linear foi %lf segundos\n", Elapsed_Time);
			
			if(algo==0)
				resolve_gauss(matriz, tam);
			else
				resolve_sor2(matriz, tam, omega, toler);
			
			free_matriz(tam, matriz);
			
			break;
			
		}
		else if(o==2){
			
			char buf[100];
			FILE *f;
			
			printf("Vossa senhoria poderia informa-nos qual o nome de arquivo de entrada?\nObserve que o arquivo deve possuir estes valores nesta ordem e separados por espaco: a, b, c, valores minimos de x e y, valores maximos de x e y, quantidade de divisoes nas abscissas e ordenadas e os valores de contorno.\nLeia relatorio para mais informacoes\n");
			
			scanf("%s", buf);
			
			f = fopen(buf, "r");
			
			if(f == NULL) {
				
				printf("Xixiriri. Erro ao acessar %s\n", buf);
				return 37;
				
			}
			
			fscanf(f, "%lf %lf %lf", &a, &b, &c);
			fscanf(f, "%lf %lf %lf %lf", &xmin, &ymin, &xmax, &ymax);
			fscanf(f, "%d %d", &divx, &divy);
			
			divx -= 2;
			divy -= 2;
			
			double valores[2*(divx+divy)+4];
			
			for(i=0;i<2*(divx+divy)+4;i++)
				fscanf(f, "%lf", &valores[i]);
			
			clock_gettime(CLOCK_MONOTONIC, &Start);
			
			tam = divx*divy;
			
			fclose(f);
			
			contorna(a, b, c, xmin, xmax, ymin, ymax, divx, divy, tam, valores);
			
			Coluna *matriz = le_matriz("intermidiate.txt", &tam, algo);
			
			if(matriz == NULL)
				return 2;
			
			clock_gettime(CLOCK_MONOTONIC, &End);
			Elapsed_Time = End.tv_sec - Start.tv_sec + 1e-9*(End.tv_nsec-Start.tv_nsec);
			printf("O tempo de construcao do sistema linear foi %lf segundos\n", Elapsed_Time);
			
			if(algo==0)
				resolve_gauss(matriz, tam);
			else
				resolve_sor2(matriz, tam, omega, toler);
			
			free_matriz(tam, matriz);
			
			break;
			
		}
		else if(o==3)
			printf("Nenhum atendente disponivel no momento.\n");
		else if(o==4){
			
			printf("Tenha um bom dia.\n");
			return 0;
			
		}
		else
			printf("Pardon?");
		
	}
	
	return 0;
	
}

