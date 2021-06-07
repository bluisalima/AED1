/* 
    Ordenação de vetor utilizando Quick Sort
    Luísa B. Lima - 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_VETOR 15

void quickSort(int vetor[], int left, int right) {
    int mid, tmp, i, j;
    i = left;
    j = right;
    mid = vetor[(left+right)/2];
    do{
        while(vetor[i] < mid)
            i++;
        while(mid < vetor[j])
            j--;

        if(i <= j){
            tmp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = tmp;
            i++;
            j--;
        }
    } while(i<=j);
    if(left < j)
        quickSort(vetor, left, j);
    if(i < right)
        quickSort(vetor, i, right);
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
	
	quickSort(vetor, 0, TAM_VETOR-1);
    printf("Vetor ordenado:\n");
	for(int i = 0; i < TAM_VETOR; i++){
		printf("[%d] ", vetor[i]);
	}
	
	return 0;
}