#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void imprime_vetor(int vetor[], int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

void radixSort(int vet[], int tam){
    int base = 10, r;
    int digit = 3; 
    //int *B = new int[size], *C = new int[base];
    int *B = (int* )malloc(base * sizeof(int));
    int *C = (int* )malloc(base * sizeof(int));
    for(int m = 0; m < digit; m++){
        for(int i = 0; i < base; ++i) 
        C[i] = 0;
        for(int j = 0; j < tam; ++j){
        r = (vet[j] / (int)(pow(10.0,m))) % base;
        ++C[r];
        }
        for(int i = 1; i < base; ++i) 
            C[i] += C[i-1];
        for(int j = tam-1; j >= 0; --j){
            r = (vet[j] / (int)(pow(10.0,m))) % base;
            int i = --C[r];
            B[i] = vet[j];
        }    
        for(int j = 0; j < tam; ++j) 
            vet[j] = B[j];
    }   
}


#define tam  9
int main(){
    int vetor[tam] = {9, 6, 2, 4, 7, 1, 3, 5, 8};
    double tempo;
    clock_t inicio, fim;
    imprime_vetor(vetor, tam);
    inicio = clock();
    radixSort(vetor, tam);
    fim = clock();
    tempo = (double) (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %.7f\n", tempo);
    imprime_vetor(vetor, tam);

    return 0;
}
