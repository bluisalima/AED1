/* 
    Ordenação de vetor utilizando Selection Sort
    Luísa B. Lima - 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_VETOR 15

void selectionSort(int data[], int n)
{
    int menor, troca, i, j, menor_id;

    for(i=0; i<n-1; i++){
        menor = data[i];

        for(j=i+1; j<n; j++)
            if(data[j] < menor){
                menor = data[j];
                menor_id = j;
            }

            troca = data[i];
            data[i] = data[menor_id];
            data[menor_id] = troca;
        
    }
}

int main(){

    int vetor[TAM_VETOR];
    
	printf("Vetor gerado randomicamente:\n");
	// Preenche o vetor com valores aleatórios 0-1000
	srand(time(NULL));
	for(int i = 0; i < TAM_VETOR; i++){
		vetor[i] = rand()%1000;
		printf("[%d] ", vetor[i]);
	}
	
	printf("\n\n");
	
	selectionSort(vetor, TAM_VETOR);
    printf("Vetor ordenado:\n");
	for(int i = 0; i < TAM_VETOR; i++){
		printf("[%d] ", vetor[i]);
	}
	
	return 0;
}