/* Exercício Arvore Binária
Luísa Lima  */
#include <stdlib.h>
#include <stdio.h>

typedef struct elemento{
	int numero;
}t_elemento;

typedef struct arvore {
	struct arvore * esq;
	t_elemento data;
	struct arvore * dir;
}node;

int menu();
int opcao;
void inserir(node ** tree, int val);
void imprimePre(node *tree);
void imprimeIn(node *tree);
void imprimePos(node *tree);
node* deletaNo(node **tree, int val);
node * minValor(node **node);

int main(){
	node *raiz = NULL;
    node *tmp;
    int n;
	 
	do{
		menu();
		
		switch(opcao){

			case 0://SAIR
				exit(0);

			case 1://INSERIR
				printf("Digite um numero:");
				scanf("%d",&n);
				inserir(&raiz,n);
				break;
				
			case 2://REMOVER APENAS UM NÓ
				printf("Digite um numero:");
				scanf("%d",&n);
				deletaNo(&raiz,n);
				break;

			case 3://EXIBIR ARVORE
				if(raiz!=NULL){
					printf("PRE-ORDEM:\n");
					imprimePre(raiz);
					printf("IN-ORDEM:\n");
					imprimeIn(raiz);
					printf("POS-ORDEM:\n");
					imprimePre(raiz);				
				}
				else{
					printf("Nao existe dados na arvore\n\n");
				}
				break;
			default:
				printf("OPCAO INVALIDA!\n\n");
		}
	}while(opcao!=0);
}

int menu(){
    printf("0 - Sair\n");
	printf("1 - Adiciona elemento na arvore\n");
    printf("2 - Remove elemento \n");
    printf("3 - Imprime arvore\n");
	scanf("%d",&opcao);
	
	return opcao;
}

node* deletaNo(node **tree, int val)
{
	if ((*tree) == NULL) {
		printf("Elemento %d nao esta na arvore!\n\n",val);
		return (*tree);
	}
	
	if((*tree)!=NULL){
		if (val < (*tree)->data.numero)
			(*tree)->esq = deletaNo(&((*tree)->esq), val);
		
		else if (val > (*tree)->data.numero)
			(*tree)->dir = deletaNo(&((*tree)->dir), val);
		
		else
		{
			if((*tree)->esq == NULL && (*tree)->dir == NULL){
				free(*tree);
				(*tree)=NULL;
			}
			
			else if((*tree)->esq == NULL)
			{
				node *temp = (*tree)->dir;
				free((*tree));
				return temp;
			}
			
			else if ((*tree)->dir == NULL)
			{
				node *temp = (*tree)->esq;
				free((*tree));
				return temp;
			}
			
			else{
				node* temp = minValor(&((*tree)->dir));
			
				(*tree)->data.numero = temp->data.numero;
			
				(*tree)->dir = deletaNo(&((*tree)->dir), temp->data.numero);
			}
			
		}
	}
	return (*tree);
}

//PEGA O VALOR MINIMO
node * minValor(node **node)
{
	while ((*node)->esq != NULL)
		(*node)= (*node)->esq;

	return (*node);
}

//INSERIR
void inserir(node ** tree, int val)
{	
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->esq = temp->dir = NULL;

        temp->data.numero = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data.numero)
    {

        inserir(&(*tree)->esq, val);
    }
    else if(val > (*tree)->data.numero)
    {
        inserir(&(*tree)->dir, val);
    }
}

//IMPRIMIR EM PREORDEM
void imprimePre(node *tree)
{
    if (tree)
    {
        printf("%d\n",tree->data.numero);
        imprimePre(tree->esq);
        imprimePre(tree->dir);
    }

}

//IMPRIMIR INORDEM
void imprimeIn(node *tree)
{
    if (tree)
    {
        imprimeIn(tree->esq);
        printf("%d\n",tree->data.numero);
        imprimeIn(tree->dir);
    }
}

//IMPRIMIR EM POSORDEM
void imprimePos(node *tree)
{
    if (tree)
    {
        
        imprimePos(tree->esq);
        imprimePos(tree->dir);
        printf("%d\n",tree->data.numero);
    }
}