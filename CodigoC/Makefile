all: listas leitura gauss sor saida contorno gerador programa

listas: listas.c
	gcc -Wall -c listas.c

leitura: leitura.c
	gcc -Wall -c leitura.c

gauss: gauss.c
	gcc -Wall -c gauss.c

sor: sor.c
	gcc -Wall -c sor.c

saida: saida.c
	gcc -Wall -c saida.c

contorno: contorno.c
	gcc -Wall -c contorno.c

gerador: gerador.c
	gcc -Wall -o gerador gerador.c -lm

programa: main.c listas.c leitura.c gauss.c sor.c saida.c contorno.c
	gcc -Wall -o programa main.c listas.o leitura.o gauss.o sor.o saida.o contorno.o -lrt -lm

clean: 
	rm *.o programa gerador

clean-gerador: 
	rm *.o gerador
