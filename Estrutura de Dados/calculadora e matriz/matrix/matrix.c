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

void transpose()
{
    Matrix matrixA = searchElement();
    float **transpose = alocateResponseValues(matrixA.column, matrixA.row);
    char name[20];
    printf("Digite o nome da matrix resposta \n");
    flushScanf();
    scanf("%20[^\n]", name);
    flushScanf();

    for (int r = 0; r < matrixA.row; r++)
        for (int c = 0; c < matrixA.column; c++)
        {
            transpose[c][r] = matrixA.value[r][c];
        }
    insertElement(name, transpose, matrixA.column, matrixA.row);
}
void sum(int operation)
{

    Matrix matrixA;
    Matrix matrixB;
    Matrix MatrixResponse;
    char resultName[20];
    float **resultValue;

    printf("Primeira matriz - ");
    matrixA = searchElement();
    printf("Segunda matriz - ");
    matrixB = searchElement();

    printf("Digite o nome da matrix resposta \n");
    flushScanf();
    scanf("%20[^\n]", resultName);
    flushScanf();
    if (matrixA.row != matrixB.row || matrixA.column != matrixB.column)
    {
        printf("Operação inválida para matrizes de tamanho diferente\n");
    }
    else
    {
        resultValue = alocateResponseValues(matrixA.row, matrixA.column);

        for (int r = 0; r < matrixA.row; r++)
            for (int c = 0; c < matrixA.column; c++)
            {
                resultValue[r][c] = matrixA.value[r][c] + (matrixB.value[r][c] * operation);
            }
        insertElement(resultName, resultValue, matrixA.row, matrixA.column);
    }
}

void printMatrix(Matrix matrix)
{
    if (matrix.row != 0)
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

void printDiagonal(Matrix matrix)
{
    if (matrix.row != 0)
    {
        printf("\nMatriz %s \n", matrix.name);
        for (int r = 0; r < matrix.row; r++)
        {
            for (int c = 0; c < matrix.column; c++)
            {
                if (r == c)
                    printf(" %.2f ", matrix.value[r][c]);
                else
                    printf(" - ");
            }
            printf("\n");
        }
    }
}

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
        strcpy(interator->next->matrix.name, name);
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
    //flushScanf();
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
    MatrixList *temp = head;
    while (temp)
    {
        printMatrix(temp->matrix);
        temp = temp->next;
    }
}

float **alocateResponseValues(int row, int column)
{
    float **matrixValue;
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
    return matrixValue;
}

void multiplication()
{
    Matrix matrixA;
    Matrix matrixB;
    Matrix MatrixResponse;
    char resultName[20];
    float **resultValue;

    printf("Primeira matriz - ");
    matrixA = searchElement();
    printf("Segunda matriz - ");
    matrixB = searchElement();

    printf("Digite o nome da matrix resposta \n");
    flushScanf();
    scanf("%20[^\n]", resultName);
    flushScanf();
    if (matrixA.column != matrixB.row)
    {
        printf("Operação inválida para matrizes com tamanhos não compatíveis\n");
    }
    else
    {
        resultValue = alocateResponseValues(matrixA.row, matrixB.column);
        float multiplication;

        for (int j = 0; j < matrixB.column; j++)
            for (int r = 0; r < matrixB.row; r++)
            {
                multiplication = 0;
                for (int c = 0; c < matrixA.column; c++)
                {
                    multiplication += matrixA.value[r][c] * (matrixB.value[c][r]);
                }
                resultValue[r][j] = multiplication;
            }
        insertElement(resultName, resultValue, matrixA.row, matrixB.column);
    }
}

void removeElement()
{
    char name[20];
    printf("Digite o nome da matrix \n");
    flushScanf();
    scanf("%20[^\n]", name);
    //flushScanf();
    MatrixList *aux = head;
    if (strcmp(name, aux->matrix.name) == 0)
    {
        head = head->next;
        printf("matriz %s excluida", aux->matrix.name);
        free(aux);
        return;
    }
    else
    {
        while (aux)
        {
            if (strcmp(name, aux->next->matrix.name) == 0)
            {
                MatrixList *exclude;
                exclude = aux->next;
                aux->next = aux->next->next;
                printf("matriz %s excluida", exclude->matrix.name);
                free(exclude);
                return;
            }
            aux = aux->next;
        }
    }
    printf("Matriz não encontrada");
}