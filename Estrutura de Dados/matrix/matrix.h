

#ifndef HEADER_MATRIX
#define HEADER_MATRIX
#include "../linkedList/linkedList.h"
#define operationSum = 0;
#define operationSubstration = 1;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void flushScanf()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

typedef struct
{
    char name[20];
    float **value;
    int row, column; //dimensão da matriz
} Matrix;

typedef struct
{
    Matrix *matrix;
    struct MatrixList *next;
} MatrixList;

typedef Matrix *listHeader;

void createMatrix();
void deleteMatrix(char matrixName[]);
void transpose(char matrixName[], char resultMatrixName[]);
void sum(char firstMatrix[], char secondMatrix[], char resultMatrixName[], int operation);
void multiplication(char firstMatrix[], char secondMatrix[], char resultMatrix[]);
void fillMatrix(float **matrix, int row, int column);
void printMatrix(char matrixName[]);
void printDiagonal(char matrixName[]);
void addElement(void *header);
void removeElement(void *header, char name[]);
void searchElement();
void listDispose();

#endif