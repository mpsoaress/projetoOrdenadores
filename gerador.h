#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_arquivo_ordenado(int tam){
    FILE *arquivo;
    char nomeArquivo[255];

    sprintf(nomeArquivo, "../arquivos/Ordenado%d.txt", tam);
    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("não foi possível criar o arquivo");
        return;
    }

    for (int cont = 1; cont <= tam; cont++)
        fprintf(arquivo, "%d\n", cont);

    fclose(arquivo);
}

void gerar_arquivo_invertido(int tam){
    FILE *arquivo;
    char nomeArquivo[255];

    sprintf(nomeArquivo, "../arquivos/Invertido%d.txt", tam);
    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("não foi possível criar o arquivo");
        return;
    }

    for (int cont = tam; cont >= 1; cont--)
        fprintf(arquivo, "%d\n", cont);

    fclose(arquivo);
}

void gerar_arquivo_aleatorio(int tam){
    FILE *arquivo;
    int num;
    char nome_arquivo[255];

    sprintf(nome_arquivo, "../arquivos/Aleatorio%d.txt", tam);
    arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL) {
        printf("não foi possível criar o arquivo");
        return;
    }

    srand(time(NULL));
    for (int cont = 1; cont <=tam; cont++){
        num = rand();
        fprintf(arquivo, "%d\n", num);
    }

    fclose(arquivo);
}

void gerador_de_arquivos(){
    int tam, opcao;
    do{
        printf("Insira o tamanho do arquivo a ser gerado: ");
        scanf("%d", &tam);

        printf("Escolha um tipo de arquivo: \n");
        printf("1- Ordenado\n");
        printf("2- Invertido\n");
        printf("3- Aleatorio\n");
        printf("4- Todos\n");
        printf("0- Cancelar\n");


        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            gerar_arquivo_ordenado(tam);
            break;
        case 2:
            gerar_arquivo_invertido(tam);
            break;
        case 3:
            gerar_arquivo_aleatorio(tam);
            break;
        case 4:
            gerar_arquivo_ordenado(tam);
            gerar_arquivo_invertido(tam);
            gerar_arquivo_aleatorio(tam);
            break;
        case 0:
            return;
        default:
            printf("Opcao invalida\n");
            //return;
    }
    } while (opcao != 0);
    
    printf("Arquivo gerado. Saindo...\n");
}