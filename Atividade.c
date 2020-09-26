#include "Atividade.h"

void Summary(int *nodes, int *edge, float *density, int **Graph, int size){
    char seeNodes;
    for (int i = 0; i < size; i++){
        seeNodes = 'F';
        for (int j = 0; j < size; j++){
            if ((Graph[i][j] != 0)){
                *edge+=1;
            }
            if ((Graph[j][i] != 0 || Graph[i][j] != 0) && seeNodes == 'F'){
                *nodes+=1;
                seeNodes = 'T';
            }                
        }
    }
    *density = (2*(*edge));
    *density /= (*nodes * (*nodes-1));
}

int VertexDegree(int **Graph, int vertex, int size){
    int degree = 0;
    for (int i = 0; i < size; i++){
        if (Graph[i][vertex] != 0 || Graph[vertex][i] != 0){
            degree++;
        }
    }
    if (Graph[vertex][vertex] != 0){
        degree++;
    }
    return degree;
}

int Successors(int **Graph, int vertex, int size, int *vert){
    int index = 0;
    for (int i = 0; i < size; i++){
        if (Graph[vertex][i] !=0){
            vert[index] = i;
            index++;
        }
    }
    return index;
}

int Predecessor(int **Graph, int vertex, int size, int *vert){
    int index = 0;
    for (int i = 0; i < size; i++){
        if (Graph[i][vertex] !=0){
            vert[index] = i;
            index++;
        }
    }
    return index;
}