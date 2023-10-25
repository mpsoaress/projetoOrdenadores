#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <sys/time.h>
#include "ordenadores.h"
#include "gerador.h"

int TAM;

FILE* selecionar_arquivo(){
    int opt;

    printf("Escolha um arquivo:\n");
    printf("1- Ordenado500000\n");
    printf("2- Ordenado750000\n");
    printf("3- Ordenado1000000\n");
    printf("4- Invertido500000\n");
    printf("5- Invertido750000\n");
    printf("6- Invertido1000000\n");
    printf("7- Aleatorio500000\n");
    printf("8- Aleatorio750000\n");
    printf("9- Aleatorio1000000\n");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        TAM = 500000;
        return fopen("../arquivos/Ordenado500000.txt", "r");

    case 2:
        TAM = 750000;
        return fopen("../arquivos/Ordenado750000.txt", "r");
    case 3:
        TAM = 1000000;
        return fopen("../arquivos/Ordenado1000000.txt", "r");
    case 4: 
        TAM = 500000;
        return fopen("../arquivos/Invertido500000.txt", "r");
    case 5:
        TAM = 750000;
        return fopen("../arquivos/Invertido750000.txt", "r");
    case 6: 
        TAM = 1000000;
        return fopen("../arquivos/Invertido1000000.txt", "r");
    case 7:
        TAM = 500000;
        return fopen("../arquivos/Aleatorio500000.txt", "r");
    case 8:
        TAM = 750000;
        return fopen("../arquivos/Aleatorio750000.txt", "r");
    case 9:
        TAM = 1000000;
        return fopen("../arquivos/Aleatorio1000000.txt", "r");
    default:
        printf("Nenhum arquivo selecionado\n");
        return NULL;
    }
}

int main(){
    //int vetor[9] = {9, 6, 2, 4, 7, 1, 3, 5, 8};
    // FILE* arquivo = fopen("../arquivos/Aleatorio500000.txt", "r");
    // int* vetor = construir_vetor(arquivo, 500000);
    // double tempo;
    // clock_t inicio, fim;
    // //imprime_vetor(vetor, 500000);
    // inicio = clock();
    // quickSortHoare(vetor, 500000);
    // fim = clock();
    // tempo = (double) (fim - inicio)/CLOCKS_PER_SEC;
    // printf("Tempo de ordenacao: %.7f", tempo);
    // //imprime_vetor(vetor, 500000);
    int opt;
    double tempo;
    FILE* arquivo;
    int* vetor;
    clock_t inicio, fim;
    printf("#############METODOS DE ORDENACAO#############");
    do{
        printf("Escolha uma opcao: \n");
        printf("1- Gerar arquivos\n");
        printf("2- Bubble sort\n");
        printf("3- Insert sort\n");
        printf("4- Selection sort\n");
        printf("5- Shell sort\n");        
        printf("6- Quick sort (Hoare)\n");
        printf("7- Quick sort (Lomuto)\n");
        printf("8- Merge sort\n");
        printf("9- Radix sort\n");
        printf("10- Heap sort\n");
        printf("0- Sair\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            gerador_de_arquivos();
            break;
        case 2:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            //gettimeofday(&inicio, NULL);
            bubble_sort(vetor, TAM);
            //gettimeofday(&fim, NULL);
            fim = clock();
            //tempo = ((fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec)) / 1000000;
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f", tempo);
            break;
        case 3:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            insert_sort(vetor, TAM);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        case 4:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            selection_sort(vetor, TAM);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        case 5:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            shell_sort(vetor, TAM);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        case 6:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            quickSortHoare(vetor, TAM);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        case 7:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            quickSortLomuto(vetor, 0, TAM - 1);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        case 8:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            mergesort(vetor, 0, TAM-1);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        case 9:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            radixSort(vetor, TAM);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        case 10:
            arquivo = selecionar_arquivo();
            vetor = construir_vetor(arquivo, TAM);
            inicio = clock();
            heap_sort(vetor, TAM);
            fim = clock();
            tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
            printf("Tempo para ordenacao: %.7f\n", tempo);
            break;
        default:
            break;
        }
        //fclose(arquivo);
    }while (opt != 0);

    return 0;
}