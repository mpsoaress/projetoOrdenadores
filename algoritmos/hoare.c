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

int partitionHoare(int *vetor, int tam){
    int x = vetor[tam/2];
    int esq, dir;
    for (esq = 0, dir = tam - 1; ; esq++, dir--) {
        while (vetor[esq] < x){
            esq++;
        }
        while (vetor[dir] > x){
            dir--;
        }
        if (esq >= dir) {
            return esq;
        }
        int aux2 = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux2;
    }
}

void quickSortHoare(int *vetor, int tam) {
    if(tam<2){
        return;
    }
    int esq = partitionHoare(vetor, tam);
    if(tam>esq){
        quickSortHoare(vetor, esq);
        quickSortHoare(vetor + esq, tam - esq);
    }
}

int main(){
    int vetor[9] = {9, 6, 2, 4, 7, 1, 3, 5, 8};
    double tempo;
    clock_t inicio, fim;
    imprime_vetor(vetor, 9);
    inicio = clock();
    quickSortHoare(vetor, 9);
    fim = clock();
    tempo = (double) (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %.7f\n", tempo);
    imprime_vetor(vetor, 9);

    return 0;
}
