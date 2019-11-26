#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Paciente
{
    char nome[10];
    char telefone[11];
    int prioridade;
    struct Paciente *proximo;
};
struct Paciente *cabeca;

int tamanhoFila(int imprime)
{
    int tamanho = 0;
    struct Paciente *interador = cabeca;
    while (interador != NULL)
    {
        tamanho++;
        interador = interador->proximo;
    }
    if (imprime)
        printf("TAMANHO DA FILA: %d\n", tamanho);
    return tamanho;
}

void imprime(struct Paciente *paciente, int imprimeTodos)
{
    int index = 0;
    int total = tamanhoFila(0);
    struct Paciente *atual = paciente;
    while (atual != NULL)
    {
        int posicaoAtual = total - index;
        printf("==============================================\n");
        printf("Paciente: %s\n", atual->nome);
        printf("Telefone: %s\n", atual->telefone);
        printf("Prioridade: %d\n", atual->prioridade);
        if (imprimeTodos)
        {
            printf("Ordem na fila: %d\n", posicaoAtual);
        }

        if (imprimeTodos)
        {
            atual = atual->proximo;
        }
        else
        {
            atual = NULL;
        }
        index++;
    };

    if (cabeca == NULL)
    {
        printf("LISTA VAZIA!!!\n");
    }
}

void adicionaPacienteOrdenadamente(struct Paciente *novoPaciente)
{
    if (novoPaciente != NULL)
    {
        if (cabeca == NULL)
        {
            cabeca = novoPaciente;
        }
        else
        {
            struct Paciente *interador = cabeca;
            struct Paciente *proximo = NULL;
            if (cabeca->prioridade >= novoPaciente->prioridade)
            {
                proximo = cabeca;
                novoPaciente->proximo = proximo;
                cabeca = novoPaciente;
            }
            else
            {
                while (interador->proximo != NULL)
                {
                    if (interador->proximo->prioridade >= novoPaciente->prioridade)
                    {
                        break;
                    }
                    interador = interador->proximo;
                }
                proximo = interador->proximo;
                novoPaciente->proximo = proximo;
                interador->proximo = novoPaciente;
            }
        }
    }
    else
    {
        printf("Erro ao inserir paciente\n");
    }
}

struct Paciente *cadastrarPaciente()
{
    struct Paciente *novoPaciente = (struct Paciente *)malloc(sizeof(struct Paciente));
    printf("Digite o nome do paciente\n");
    scanf("%s", novoPaciente->nome);
    printf("Digite o telefone do paciente\n");
    scanf("%s", novoPaciente->telefone);
    printf("Digite a prioridade do paciente\n");
    scanf("%d", &novoPaciente->prioridade);
    printf("Cadastrado\n");
    novoPaciente->proximo = NULL;
    adicionaPacienteOrdenadamente(novoPaciente);
    return novoPaciente;
}

void buscarPaciente()
{
    int tipoBusca = 0;
    printf("================================\n");
    printf("Busca de Paciente\n");
    printf("================================\n");
    printf("1 - Buscar por nome:\n");
    printf("2 - Buscar por telefone:\n");
    scanf("%d", &tipoBusca);
    char buscar[30];

    if (tipoBusca == 1)
    {
        printf("Digite o nome para buscar:\n");
    }
    if (tipoBusca == 2)
    {
        printf("Digite o telefone para buscar:\n");
    }
    scanf("%s", buscar);
    struct Paciente *interador = cabeca;
    while (interador != NULL)
    {
        if (strcmp(buscar, interador->nome) == 0)
            break;
        interador = interador->proximo;
    }
    if (interador != NULL && strcmp(buscar, interador->nome) == 0)
    {
        imprime(interador, 0);
    }
    else
    {
        printf("Paciente não encontrado!!!!!!!\n");
    }
}
void salvarNoArquivo(struct Paciente *atual)
{
    if (atual != NULL)
    {
        FILE *file = fopen("pacientes-operados.txt", "a");
        if (file == NULL)
        {
            printf("erro ao abrir aquivo");
        }
        fprintf(file, "==============================================\n");
        fprintf(file, "Paciente: %s\n", atual->nome);
        fprintf(file, "Telefone: %s\n", atual->telefone);
        fprintf(file, "Prioridade: %d\n", atual->prioridade);

        fclose(file);
    }
}

void proximoPacienteAOperar()
{
    struct Paciente *interador = cabeca;
    struct Paciente *interadorAnterior = cabeca;
    if (interador != NULL && interador->proximo != NULL)
        while (interador->proximo != NULL)
        {
            interadorAnterior = interador;
            interador = interador->proximo;
        }
    printf("PROXIMO PARA OPERAR!! \n");
    if (interador != cabeca)
    {
        salvarNoArquivo(interadorAnterior->proximo);
        imprime(interadorAnterior->proximo, 0);
        interadorAnterior->proximo = NULL;
    }
    else
    {
        salvarNoArquivo(interador);
        imprime(interador, 0);
        cabeca = NULL;
    }
}

int menu()
{
    int option = -1;
    do
    {
        printf("==============================================\n");
        printf("MENU\n");
        printf("==============================================\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Buscar paciente\n");
        printf("3 - Proximo paciente a ser operado\n");
        printf("4 - Verificar tamanho da fila\n");
        printf("5 - Sair\n");
        printf("6 - Imprime toda lista\n");

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
            tamanhoFila(1);
            break;
        case 6:
            imprime(cabeca, 1);
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
