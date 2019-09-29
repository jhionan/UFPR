#include "../linkedList/linkedList.h"
#define operationSum = 0;
#define operationSubstration = 1;

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

float **
createMatrix(int row, int column, char matrixName[]);

int deleteMatrix(char matrixName[]);

float **transpose(char matrixName[], char resultMatrixName[]);

float **sum(char firstMatrix[], char secondMatrix[], char resultMatrixName[], int operation);

float **multiplication(char firstMatrix[], char secondMatrix[], char resultMatrix[]);

float **fillMatrix(float **matrix, int row, int column);

void printMatrix(char matrixName[]);

void printDiagonal(char matrixName[]);