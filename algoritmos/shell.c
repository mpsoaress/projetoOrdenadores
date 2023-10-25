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

void shell_sort(int vetor[], int tam){
    int i, j, h, aux;
    for(h = 1; h < tam; h = 3 * h + 1);//calcula h inicial

    while (h > 0)
    {
        h = (h - 1) / 3;
        for (i = h; i < tam; i++)
        {
            aux = vetor[i];
            j = i;
            while (vetor[j-h] > aux)
            {
                vetor[j] = vetor[j - h];
                j -= h;
                if (j < h)
                {
                    break;
                }  
            }
            vetor[j] = aux;      
        }   
    }  
}

int main(){
    int vetor[9] = {9, 6, 2, 4, 7, 1, 3, 5, 8};
    double tempo;
    clock_t inicio, fim;
    imprime_vetor(vetor, 9);
    inicio = clock();
    shell_sort(vetor, 9);
    fim = clock();
    tempo = (double) (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %.7f\n", tempo);
    imprime_vetor(vetor, 9);

    return 0;
}
