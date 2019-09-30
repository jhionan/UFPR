#include "menu.h"

void menu()
{
    int selection = -1;
    do
    {
        printf("\n\n***********************************************************\n");
        printf("Bem vindo à  calculadora de matrizes feita para você\n");
        printf("***********************************************************\n");
        printf("Digite 0 para Sair.\n");
        printf("Digite 1 para Criar uma Matriz.\n");
        printf("DIgite 2 para Excluir uma Matrix.\n");
        printf("Digite 3 para Transpor uma Matriz.\n");
        printf("Digite 4 para Somar duas Matrizes.\n");
        printf("Digite 5 para Subtrair duas Matrizes.\n");
        printf("Digite 6 para Multiplicar duas Matrizes.\n");
        printf("Digite 7 para Imprimir a diagonal principal.\n");
        printf("Digite 8 para Imprimir uma Matriz.\n");
        printf("***********************************************************\n");

        scanf("%d", &selection);
        fflush(stdin);
        switch (selection)
        {
        case CREATE:
            createMatrix();
            break;
        case DELETE:

            break;
        case TRANSPOSE:

            break;
        case SUM:
            sum(1);
            break;
        case SUBSTRACTION:
            sum(-1);
            break;
        case MULTIPLICATION:

            break;
        case PRINT_DIAGONAL:
            printDiagonal(searchElement());
            break;
        case PRINT_MATRIX:
            printMatrix(searchElement());
            break;
        case 9:
            printAll();
            break;
        }
    }

    while (selection != 0);
}