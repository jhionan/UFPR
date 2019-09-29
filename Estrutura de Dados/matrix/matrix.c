#include "matrix.h"

void createMatrix()
{
    char name[20];
    int row = 0;
    int column = 0;
    float **matrixValue;

    printf("\nDigite a quantidade de linhas\n");
    scanf("%d", &row);
    flushScanf();
    printf("\nDigite a quantidade de colunas\n");
    scanf("%d", &column);
    flushScanf();
    printf("Digite o nome da matrix \n");
    scanf("%20[^\n]", name);
    flushScanf();
    printf("row %d, %d, %s\n", row, column, name);

    if (row > 0 && column > 0 && name != NULL)
    {
        for (int r = 0; r < row; r++)
        {
            matrixValue[r] = (float *)malloc(column * sizeof(float));
            if (!matrixValue[r])
            {
                for (int i = 0; i < row; i++)
                {
                    free(matrixValue[i]);
                    exit(1);
                }
            }
        }
        for (int r = 0; r < row; r++)
            for (int c = 0; c < column; c++)
            {
                printf(" Digite o elemento %d,%d", r, c);
                scanf("%d", matrixValue[r][c]);
                flushScanf();
            }
    }
    else
    {
        createMatrix();
    }
}

void deleteMatrix(char matrixName[]) {}

void transpose(char matrixName[], char resultMatrixName[]) {}
void sum(char firstMatrix[], char secondMatrix[], char resultMatrixName[], int operation) {}

void multiplication(char firstMatrix[], char secondMatrix[], char resultMatrix[]) {}

void fillMatrix(float **matrix, int row, int column) {}

void printMatrix(char matrixName[]) {}

void printDiagonal(char matrixName[]) {}