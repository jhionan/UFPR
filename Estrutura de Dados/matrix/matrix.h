

#ifndef HEADER_MATRIX
#define HEADER_MATRIX
#define operationSum = 1;
#define operationSubstration = -1;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void flushScanf()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

typedef struct Matrix
{
    char name[20];
    float **value;
    int row, column;
} Matrix;

typedef struct MatrixList
{
    Matrix matrix;
    struct MatrixList *next;
} MatrixList;

void createMatrix();
void deleteMatrix(char matrixName[]);
void transpose();
void sum(int operation);
void multiplication();
void printMatrix(Matrix matrix);
void printDiagonal(Matrix matrix);
float **alocateResponseValues(int row, int column);

void insertElement(char name[], float **value, int row, int column);
void removeElement();
Matrix searchElement();
void listDispose();
void printAll();

#endif