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

int busca_binaria(int vetor[], int inicio, int fim, int chave, int *qnt_operacoes){
    *qnt_operacoes += 1;
    int meio = (inicio + fim) / 2;
    if((inicio == fim) && !(chave == vetor[meio]))
        return -1;
    else{
        if(chave == vetor[meio])
            return meio;
        else{
            if(chave > vetor[meio])
                return busca_binaria(vetor, meio+1, fim, chave, qnt_operacoes);
            else{
                return busca_binaria(vetor, inicio, meio-1, chave, qnt_operacoes);
            }                
        }
    }
}

int main(){
    //int vetor[9] = {9, 6, 2, 4, 7, 1, 3, 5, 8};
    int tam = 1000000;

    int *vetor = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i<tam; i++)
        vetor[i] = i+1;

    int indice;
    int qnt_operacoes = 0;
    indice = busca_binaria(vetor, 0, tam, 6, &qnt_operacoes);
    printf("Encontrado na posicao %d\n", indice);
    printf("Operacoes: %d\n", qnt_operacoes);

    return 0;
}
