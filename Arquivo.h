#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void FindHigherVertex (int *size, FILE *input);
int** makeMatrix (int size);
int** CompleteGraph (int **Graph, FILE *input);
int** makeGraph(int **Graph,int size, FILE *input);