/* LUÍSA BORGES LIMA
EXERCÍCIO 1 - AULA 6 - FILA */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO_LISTA 5

typedef struct
{
    char nome[128];
    int idade;
}PESSOA;

typedef struct {
    PESSOA fila[TAMANHO_LISTA];
    int totalPessoas;
} FILA;

void LimparBuffer();
void Pause();
void IniciarFila(FILA *pFila);
int TotalElementos(FILA *filaPessoa); 
int Inserir(FILA *filaPessoa, PESSOA pessoa);
void LeiaPessoa(PESSOA *pessoa);
void MantemInserir(FILA *filaPessoa);
void FilaAndar(FILA *listaPessoa);
int Retirar(FILA *listaPessoa);
void Limpar(FILA *listaPessoa);
void MantemRetirar(FILA *listaPessoa);
void ImprimirPessoa(PESSOA pessoa);
void Listar(FILA *listaPessoa);
void Menu(int *opcaoSelecionar);

int main() {
    int opcaoSelecionada = 0;
    FILA listaPessoas;
    IniciarFila(&listaPessoas);

    do {
        Menu(&opcaoSelecionada);

        switch (opcaoSelecionada) {
            case 0:
                MantemInserir(&listaPessoas);
                break;
            case 1:
                MantemRetirar(&listaPessoas);
                break;
            case 2:
                Listar(&listaPessoas);
                break;
			case 3:
                Limpar(&listaPessoas);
                break;
        }
    } while (opcaoSelecionada != 4);

    return 0;
}


void LimparBuffer() 
{
    while (getchar() != '\n');
}

void Pause() 
{
    printf("\nTecle <ENTER> para continuar...");
    getchar();
}

void IniciarFila(FILA *pFila)
{
    pFila->totalPessoas =0;
}

int TotalElementos(FILA *filaPessoa)
{
    return filaPessoa->totalPessoas;
}

int Inserir(FILA *filaPessoa, PESSOA pessoa)
{
	if (filaPessoa->totalPessoas < TAMANHO_LISTA) {
        filaPessoa->fila[filaPessoa->totalPessoas] = pessoa;
        filaPessoa->totalPessoas++;

        return filaPessoa->totalPessoas - 1;
    }

    return -1;
}

void LeiaPessoa(PESSOA *pessoa)
{
    printf("Digite o nome: ");
    scanf("%s", &pessoa->nome);
    LimparBuffer();

    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);
    LimparBuffer();
}

void MantemInserir(FILA *filaPessoa) 
{
    if (TotalElementos(filaPessoa) >= TAMANHO_LISTA) {
        printf("\nImpossivel inserir!");
        printf("\nA fila esta cheia.\n\n");

        Pause();
    } else {
        PESSOA pessoa;
        LeiaPessoa(&pessoa);
        Inserir(filaPessoa, pessoa);
        Pause();
    }
}

void FilaAndar(FILA *listaPessoa) 
{
    int i = 0;

    for (i = 0; i < listaPessoa->totalPessoas; i++)
        listaPessoa->fila[i] = listaPessoa->fila[i + 1];
}

int Retirar(FILA *listaPessoa) {
    if (listaPessoa->totalPessoas > 0) {
        FilaAndar(listaPessoa);
        listaPessoa->totalPessoas--;

        return listaPessoa->totalPessoas;
    }

    return -1;
}
void Limpar(FILA *listaPessoa){
	while(listaPessoa->totalPessoas != 0){
		Retirar(listaPessoa);
	}
	printf("Lista apagada!\n");
}
void MantemRetirar(FILA *listaPessoa) {

    int retirouPessoa = Retirar(listaPessoa);

    if (retirouPessoa >= 0)
        printf("\nRetirado com sucesso.\n");
    else {
        printf("\nImpossivel retirar!\n");
        printf("\nA fila esta vazia.\n");
    }

    Pause();
}
void ImprimirPessoa(PESSOA pessoa)
{
    printf("Nome: %s \n", pessoa.nome);
    printf("Idade: %d \n\n", pessoa.idade);
}

void Listar(FILA *listaPessoa) {
    printf("\n\nLista de Pessoas\n\n");

    if (listaPessoa->totalPessoas > 0) {
        int i = 0;
        for (i = 0; i < listaPessoa->totalPessoas; i++) {
            printf("Registro na posiçao [%d]\n", i);
            ImprimirPessoa(listaPessoa->fila[i]);
        }
    } else
        printf("\nLista vazia...\n\n");

    Pause();
}

void Menu(int *opcaoSelecionar) {
    printf("MENU   	\n");
    printf("----------------\n");
    printf("[0] - Inserir	\n");
    printf("[1] - Retirar	\n");
    printf("[2] - Listar	\n");
    printf("[3] - Limpar	\n"); 
	printf("[4] - Sair		\n");
    printf("----------------\n");
    printf("\n\n");
    printf("Opcao: ");
    scanf("%d", opcaoSelecionar);
    LimparBuffer();
}