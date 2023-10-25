#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime_vetor(int vetor[], int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

void heapify_down(int *array, int i, int tamanho){
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    
    if(esquerda < tamanho && array[esquerda] > array[maior])
        maior = esquerda;
    
    if(direita < tamanho && array[direita] > array[maior])
        maior = direita;
    
    if(maior != i){
        int temp = array[i];
        array[i] = array[maior];
        array[maior] = temp;
        heapify_down(array, maior, tamanho);
    }
}

void heap_sort(int *array, int tamanho){
    //contrução do heap máximo
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify_down(array, i, tamanho);
    
    //ordenação do array
    for(int i = tamanho - 1; i >= 0; i--){
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify_down(array, 0, i);
    }  
}

int main(){
    int vetor[9] = {9, 6, 2, 4, 7, 1, 3, 5, 8};
    double tempo;
    clock_t inicio, fim;
    imprime_vetor(vetor, 9);
    inicio = clock();
    heap_sort(vetor, 9);
    fim = clock();
    tempo = (double) (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %.7f\n", tempo);
    imprime_vetor(vetor, 9);

    return 0;
}
