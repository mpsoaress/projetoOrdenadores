#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime_vetor(int vetor[], int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

int* construir_vetor(FILE *arquivo, int tam){
  char linha[10];
  int *vetor = (int*)malloc(tam *sizeof(int));
  /*for(int i=0; i<tam; i++){
    vetor[i] = atoi(fgets(linha, 10, arquivo));
  }*/
  if (arquivo == NULL){
		printf("Erro ao abrir para leitura");
    return NULL;
  }
	else {
   	int x=0;
		while (!feof(arquivo)){
			fgets(linha, 10, arquivo);
			vetor[x]=atoi(linha);
			x++;
		}
    }
    free(arquivo);
  return vetor;
}

void bubble_sort(int vetor[], int tam){
    int i, j, aux;
    for(i=0; i<tam-1; i++){
        for(j=0; j<tam-1-i; j++){
            //printf("Iteracao %d\n ", j+1);
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
            //imprime_vetor(vetor, tam);
        }
    }
}

void insert_sort(int vetor[], int tam){
    int x = 1;
    int aux, y;
    for(x = 1; x < tam; x++){
        aux = vetor[x];
        y = x - 1;
        while (y >= 0 && aux < vetor[y]){
            vetor[y +1] = vetor[y];
            y--;
            vetor[y + 1] = aux;
        }  
    }
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

void selection_sort(int vetor[], int tam){
  int menor = 0;
  int aux;
  for(int i = 0; i < tam; i++){
    for(int j = i + 1; j < tam - 1; j++){
      if(vetor[j] < vetor[menor]){
        menor = j;
      }
    }
    aux = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
  }
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

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
	array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
// int partitionLomuto(int arr[], int low, int high) 
// { 
// 	int pivot = arr[high]; // pivot 
// 	int i = (low - 1); // Index of smaller element 
//     int aux;

// 	for (int j = low; j <= high- 1; j++) 
// 	{ 
// 		// If current element is smaller than or 
// 		// equal to pivot 
// 		if (arr[j] <= pivot) 
// 		{ 
// 			i++; // increment index of smaller element 
// 			aux = arr[i];
//             arr[i] = arr[j];
//             arr[j] = aux;
// 		} 
// 	} 
// 	//swap(arr[i + 1], arr[high]); 
//     aux = arr[i + 1];
//     arr[i + 1] = arr[high];
//     arr[high] = aux;
// 	return (i + 1); 
// } 

int partitionLomuto(int arr[], int low, int high){
	int pivot_index = (low + high) / 2; // Índice do elemento central como pivô
    int pivot = arr[pivot_index]; // Valor do pivô
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        // Troca os elementos arr[i] e arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSortLomuto(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partitionLomuto(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSortLomuto(arr, low, pi - 1); 
		quickSortLomuto(arr, pi + 1, high); 
	} 
}


void merge(int a[], int esq, int meio, int dir){
    int auxSize = dir - esq + 1;
    // int aux[auxSize];
    int *aux = (int*)malloc(auxSize * sizeof(int));
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
    free(aux);
}

void mergesort(int a[], int esq, int dir){
    if (esq < dir){
        int meio = (esq + dir) / 2;
        mergesort(a, esq, meio);
        mergesort(a, meio + 1, dir);
        merge(a, esq, meio, dir);
    }
}

void radixSort(int vet[], int tam){
    int base = 10, r;
    int digit = 3; 
    //int *B = new int[size], *C = new int[base];
    int *B = (int* )malloc(tam * sizeof(int));
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