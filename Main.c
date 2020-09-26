#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Arquivo.h"
#include "Atividade.h"

int main(int argc, char *argv[]){
    FILE *input = NULL;
    input = fopen (argv[1], "r");
    if (input == NULL){
        printf ("Erro! Arquivo não encontrado.\n");
        return 1;
    }
    int **Graph,size = 0,choice=-1;
    int nodes = 0, edge = 0;
    float density = 0;
    int vertex, *vert, index;
    FindHigherVertex(&size, input);
    fclose (input);
    input = fopen (argv[1], "r");
    Graph = makeGraph(Graph, size, input);
    fclose (input);
    vert = (int*) calloc (size,sizeof(int));
    while (true){
        printf ("\n0 - Sair\n1 - Sumario\n2 - Grau do Vertice\n3 - Sucessores\n4 - Antecessores\nEscolha: ");
        scanf ("%i",&choice);
        switch (choice){
            case 0:
                free (vert);
                for (int i = 0; i < size; i++){
                    free(Graph[i]);
                }
                free(Graph);
                return false;
                break;
            case 1:
                nodes = 0; edge = 0; density = 0;
                Summary(&nodes,&edge,&density,Graph,size);
                system("clear");
                printf ("Informacoes do Grafo \nVertices = %i\nArestas = %i\nDensidade = %.3f%%\n",nodes,edge,density*100);
                break;
            case 2:
                printf ("\nQual Vertice Deseja Verificar: ");
                scanf ("%i",&vertex);
                system("clear");
                printf("Grau do vertice %i = %i.\n\n",vertex,VertexDegree(Graph,vertex,size ));
                break;
            case 3:
                printf ("\nQual Vertice Deseja Verificar: ");
                scanf ("%i",&vertex);
                system("clear");
                index = Successors(Graph,vertex,size,vert);
                if (index > 0){
                    printf ("O vertice %i possui %i sucessores, sao eles: ",vertex, index);
                    for (int i = 0; i < index; i++){
                        printf ("%i  ",vert[i]);
                    }
                }else{
                    printf ("O vertice %i nao possui sucessores.",vertex);
                }
                break;
            case 4:
                printf ("\nQual Vertice Deseja Verificar: ");
                scanf ("%i",&vertex);
                system("clear");
                index = Predecessor(Graph,vertex,size,vert);
                if (index > 0){
                    printf ("O vertice %i possui %i antecessores, sao eles: ",vertex, index);
                    for (int i = 0; i < index; i++){
                        printf ("%i  ",vert[i]);
                    }
                    printf ("\n");
                }else{
                    printf ("O vertice %i nao possui antecessores.\n",vertex);
                }
                break;    
            default:
                printf ("\nComando invalido!\n");
        }
    }    
    return 0;    
}
