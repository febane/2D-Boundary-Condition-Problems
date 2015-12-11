/**
 * O Contornador
 * saida.c
 * Escrita do resultado em arquivo de saída
 * Ver relatorio para mais informacoes
 * 
 * @author Fernando Barbosa Neto
 * @author Jeferson de Oliveira Batista
 * 
 * @version 1.0
 * 
 */


#include "saida.h"

/**
 *  Escreve resposta em arquivo
 *
 *  @param n tamanho do vetor-resposta
 *  @param resp vetor que contem resposta
 *
 */
void saida_de_dados(int n, double resp[]){
	
	int i=0;
	
	while(i!=1||i!=2||i!=3){
		
		printf("Digite a opcao desejada:\n1\tPara imprimir o resultado em um arquivo de saida do tipo texto\n2\tPara imprimir o resultado na tela\n3\tSair do programa\n");
		
		scanf("%d", &i);
		
		if(i==1){
			
			FILE *f;
			char string[100];
			
			printf("Entre com o nome do arquivo: ");
			scanf("%s", string); 
	
			f = fopen(string, "w");
			
			if(f == NULL) {
				
				printf("Erro ao acessar %s\n", string);
				return;
				
			}
			
			fprintf(f, "%d\n", n);
			
			for(i=0;i<n;i++)
				fprintf(f, "%g\n", resp[i]);
			
			fclose(f);
			
			return;
			
		}
		else if(i==2){
			
			for(i=0;i<n;i++)
				printf("%g\n", resp[i]);
			
			return;
			
		}
		else if(i==3)
			return;
		else
			printf("Opcao invalida!\n");
		
	}
	
}
