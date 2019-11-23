#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define muito_urgent = 5
#define urgente = 4
#define medio = 3
#define pouco_urgente = 2
#define sem_urgencia = 1

struct Paciente
{
    char nome[10];
    char telefone[11];
    int prioridade;
    struct Paciente *proximo;
};

void imprime(struct Paciente *paciente, int imprimeTodos)
{
    struct Paciente *atual = paciente;
    while (atual != NULL)
    {
        printf("==============================================\n");
        printf("Paciente: %s\n", atual->nome);
        printf("Telefone: %s\n", atual->telefone);
        printf("Prioridade: %s\n", atual->nome);
        printf("==============================================\n");
        if (imprimeTodos)
        {
            atual = atual->proximo;
        }
        else
        {
            atual = NULL;
        }
    };
}

struct Paciente *cadastrarPaciente()
{
    struct Paciente *novoPaciente = (struct Paciente *)malloc(sizeof(struct Paciente));
    printf("Digite o nome do paciente\n");
    scanf("%s", novoPaciente->nome);
    printf("Digite o telefone do paciente\n");
    scanf("%s", novoPaciente->telefone);
    printf("Digite o nome do paciente\n");
    scanf("%s", novoPaciente->nome);
    printf("Cadastrado\n");
    return novoPaciente;
}
void buscarPaciente() {}
void proximoPacienteAOperar() {}
void tamanhoFila() {}
int menu()
{
    int option = -1;
    do
    {
        printf("==============================================\n");
        printf("MENU");
        printf("==============================================\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Buscar paciente\n");
        printf("3 - Proximo paciente a ser operado\n");
        printf("4 Verificar tamanho da fila\n");
        printf("5 - Sair\n");

        printf("Digite uma opção: ");

        scanf("%d", &option);
        printf("==============================================\n");

        switch (option)
        {
        case 1:
            imprime(cadastrarPaciente(), 0);
            break;
        case 2:
            buscarPaciente();
            break;
        case 3:
            proximoPacienteAOperar();
            break;
        case 4:
            tamanhoFila();
            break;
        default:
            break;
        }

    } while (option != 5 /* strncmp(option, "5", 1) != 0 */);
    printf("out of while");

    return 0;
}

int main()
{
    menu();
    return 0;
}
