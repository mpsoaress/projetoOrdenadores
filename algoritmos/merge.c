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

void merge(int a[], int esq, int meio, int dir){
    int auxSize = dir - esq + 1;
    int aux[auxSize];
    //copie os elementos para o array auxiliar
    for (int i = esq; i <= dir; i++)
    {
        aux[i - esq] = a[i];
    }
    int i = esq; //indice inicial da primeira metade
    int j = meio + 1;  //indice inicial da segunda metade
    int k = esq;  //indice atual no array original a[]
    while(i <= meio && j <= dir){
        if(aux[i - esq] <= aux[j - esq]){
            a[k] = aux[i - esq];
            i++;
        }else{
            a[k] = aux[j - esq];
            j++;
        }
        k++;
    }
    //copie os elementos restantes da primeira metade, se houver
    while(i <= meio ){
        a[k] = aux[i - esq];
        i++;
        k++;
    }
    //copie os elementos restantes da segunda metade, se houver
    while (j <= dir)
    {
        a[k] = aux[j - esq];
        j++;
        k++;
    }
}

void mergesort(int a[], int esq, int dir){
    if (esq < dir){
        int meio = (esq + dir) / 2;
        mergesort(a, esq, meio);
        mergesort(a, meio + 1, dir);
        merge(a, esq, meio, dir);
    }
}

#define tam  9
int main(){
    int vetor[tam] = {9, 6, 2, 4, 7, 1, 3, 5, 8};
    double tempo;
    clock_t inicio, fim;
    imprime_vetor(vetor, tam);
    inicio = clock();
    mergesort(vetor, 0, tam-1);
    fim = clock();
    tempo = (double) (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %.7f\n", tempo);
    imprime_vetor(vetor, tam);

    return 0;
}
