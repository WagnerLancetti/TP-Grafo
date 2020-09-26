all: main clean

main: Main.o Arquivo.o Atividade.o
	gcc -Wall Arquivo.o Atividade.o Main.o -o Tp

Main.o: Main.c Arquivo.h Atividade.h
	gcc -Wall -c Main.c

Arquivo.o: Arquivo.c Arquivo.h
	gcc -Wall -c Arquivo.c

Atividade.o: Atividade.c Atividade.h
	gcc -Wall -c Atividade.c

clean:
	rm *.o
