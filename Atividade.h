#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Summary(int *nodes, int *edge, float *density, int **Graph, int size);
int VertexDegree(int **Graph, int vertex, int size);
int Successors(int **Graph, int vertex, int size, int *vert);
int Predecessor(int **Graph, int vertex, int size, int *vert);
