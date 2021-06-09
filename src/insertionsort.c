/* 
    Ordenação de vetor utilizando Insertion Sort
    Luísa B. Lima - 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_VETOR 15

void insertionSort(int data[], int n) {
    int tmp, i, j;
    for(j=0; j<n; j++){
        i = j - 1; 
        tmp = data[j];
        while( (i >= 0) && (tmp < data[i]) ){
            data[i+1] = data[i];
            i--;
        }
        data[i+1] = tmp;
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
	
	insertionSort(vetor, TAM_VETOR);
    printf("Vetor ordenado:\n");
	for(int i = 0; i < TAM_VETOR; i++){
		printf("[%d] ", vetor[i]);
	}
	
	return 0;
}