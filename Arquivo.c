#include "Arquivo.h"

void FindHigherVertex (int *size, FILE *input){
    int node1 = 0, node2 = 0, value = 0;
    while (!feof(input)){
        fscanf (input, "%i %i %i", &node1, &node2, &value);
        if (*size < node1){
            *size = node1;
        }
        if (*size < node2){
            *size = node2;
        }
    }
    *size+=1;
}

int** makeMatrix (int size){
    int **Matrix;
    Matrix = (int**) calloc (size,sizeof (int*));
    for (int i = 0; i < size; i ++){
        Matrix[i] = (int*) calloc (size,sizeof(int));
    }
    return Matrix;
}

int** CompleteGraph (int **Graph, FILE *input) {
    int nodes[2], value;
    while (!feof(input)){
        fscanf (input, "%i %i %i",&nodes[0], &nodes[1], &value);
        Graph[nodes[0]][nodes[1]] = value;
    }
    return Graph;
}

int** makeGraph(int **Graph,int size, FILE *input){
    Graph = makeMatrix (size);
    Graph = CompleteGraph(Graph,input);
    return Graph;
}