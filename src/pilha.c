/* LUÍSA BORGES LIMA 
EXERCÍCIO 1 - AULA 5 - PILHA */
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    struct pessoa* prox;
}Pessoa;

typedef struct pilha{
    Pessoa *topo;
}Pilha;


Pilha* Criar();
void Listar(Pilha* pilha);
void Empilhar(Pilha** pilha);
void Desempilhar(Pilha** pilha);
void DesempilharTodos(Pilha** pilha);
void Topo(Pilha* pilha);
void ler_string(char palavra[50], int tamanho);


int main()
{
    int escolha;
    Pilha* pilha = Criar();   

    do
    {
        printf("----- MENU -----\n");
        printf("0) Insere pessoa\n");
        printf("1) Deleta pessoa do topo\n");
        printf("2) Lista pilha\n");
        printf("3) Limpa a pilha\n");
        printf("4) Sair do programa\n");
        printf("Entre com a opção desejada: ");
        scanf("%i", &escolha);
        getchar(); // limpar <enter>

        printf("\n");
        switch(escolha)
        {
            // Adiciona 
            case 0:
                Empilhar(&pilha);
                break;

            // Deleta
            case 1:
                Desempilhar(&pilha);
                break;
            // Lista
            case 2:
                Listar(pilha);
                break;
            // Limpa
            case 3:
                DesempilharTodos(&pilha);
                break;
            // Sair 
            case 4: 
                exit(0);
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (escolha!=4);

    return 0;

}

Pilha* Criar(){
	Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha));
	if(novaPilha == NULL){
		printf("Nao foi possivel alocar a memoria :(\n");
	}
	
	novaPilha->topo = NULL;
	
	return novaPilha;
}

void Empilhar(Pilha** pilha){	
	Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));
	if(pessoa == NULL){
		printf("Nao foi possivel alocar a memoria:(\n");
	}

    printf("Nome: ");
    ler_string(pessoa->nome, 50);
	
	if((*pilha)->topo == NULL){	
		pessoa->prox = NULL;		
	}
	else{
		pessoa->prox = (*pilha)->topo;		
	}
	
	(*pilha)->topo = pessoa;
}

void Desempilhar(Pilha** pilha){
    if((*pilha)->topo == NULL){
		printf("Nao eh possivel Desempilhar nada, pois o historico estah vazio!\n");
		exit(1);
	} else if((*pilha)->topo->prox == NULL){
		free((*pilha)->topo);	
		(*pilha)->topo = NULL;
	} else{
		Pessoa* aux = (Pessoa*) malloc(sizeof(Pessoa));
		if(aux == NULL){
			printf("Nao foi possivel alocar a memoria:(\n");
		}
		
		aux->prox = (*pilha)->topo;
		
		(*pilha)->topo = (*pilha)->topo->prox;
		
		free(aux->prox);
		free(aux);		
	}
}

void DesempilharTodos(Pilha** pilha){
	if((*pilha)->topo == NULL){
		printf("A pilha foi desempilhada totalmente, agora o historico estah vazio!\n");
	} else if((*pilha)->topo->prox == NULL){
		free((*pilha)->topo);	
		(*pilha)->topo = NULL;
	} else{
		Pessoa* aux = (Pessoa*) malloc(sizeof(Pessoa));
		if(aux == NULL){
			printf("Nao foi possivel alocar a memoria:(\n");
		}
		
		aux->prox = (*pilha)->topo;
		
		(*pilha)->topo = (*pilha)->topo->prox;
		
		free(aux->prox);
		free(aux);		
	}
	DesempilharTodos(pilha);
}

void Listar(Pilha* pilha)
{
    if(pilha->topo == NULL){
		printf("A pilha esta vazia!\n");
		exit(1);
	}
    
    Pessoa* atual = pilha->topo;
    printf("-------\n");
    while(atual != NULL)
    {
        printf("%s\n", atual->nome);
        atual = atual->prox;

    }
    printf("\n");

}

void ler_string(char palavra[50], int tamanho)
{
	int i = 0;
	char c;
	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';
	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}
}