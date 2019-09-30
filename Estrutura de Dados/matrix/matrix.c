#include "matrix.h"

struct MatrixList *head;

void createMatrix()
{
    char name[20];
    int row = 0;
    int column = 0;
    float **matrixValue = NULL;

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

    if (row > 0 && column > 0 && strncmp(name, "\n", strlen(name)))
    {
        matrixValue = (float **)malloc(row * sizeof(float *));
        for (int r = 0; r < row; r++)
        {
            matrixValue[r] = (float *)malloc(column * sizeof(float));
            if (!matrixValue[r])
            {
                printf("deu ruim");
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
                printf(" Digite o elemento %d,%d: ", r + 1, c + 1);
                scanf("%f", &matrixValue[r][c]);
                flushScanf();
            }
        insertElement(name, matrixValue, row, column);
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

void printMatrix(Matrix matrix)
{
    if (matrix.row != NULL)
    {
        printf("\nMatriz %s \n", matrix.name);
        for (int r = 0; r < matrix.row; r++)
        {
            for (int c = 0; c < matrix.column; c++)
            {
                printf(" %.2f ", matrix.value[r][c]);
            }
            printf("\n");
        }
    }
}

void printDiagonal(char matrixName[]) {}

void insertElement(char name[], float **value, int row, int column)
{

    if (!head)
    {

        head = (MatrixList *)malloc(sizeof(MatrixList));
        strcpy(head->matrix.name, name);
        head->matrix.value = value;
        head->matrix.row = row;
        head->matrix.column = column;
        head->next = NULL;
        printf("Matriz %s adicionada \n", head->matrix.name);
        printMatrix(head->matrix);
    }
    else
    {

        MatrixList *interator = head;

        while (interator->next != NULL)
        {

            interator = interator->next;
        }

        interator->next = (MatrixList *)malloc(sizeof(MatrixList));
        strcpy(interator->matrix.name, name);
        interator->next->matrix.value = value;
        interator->next->matrix.row = row;
        interator->next->matrix.column = column;
        interator->next->next = NULL;
        printf("Matriz %s adicionada \n", interator->matrix.name);
        printMatrix(interator->next->matrix);
    }
}

Matrix searchElement()
{
    char name[20];
    printf("Digite o nome da matrix \n");
    flushScanf();
    scanf("%20[^\n]", name);
    flushScanf();
    MatrixList *aux = head;
    while (aux)
    {
        if (strcmp(name, aux->matrix.name) == 0)
        {
            return aux->matrix;
        }
        aux = aux->next;
    }
    printf("Matriz não encontrada");
}

void printAll()
{
    MatrixList *interator = head;
    while (interator)
    {
    }
}