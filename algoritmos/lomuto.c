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

int main(){
    // int vetor[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int tam = 10000000;
	int *vetor = (int*)malloc(tam * sizeof(int));
	for(int i=0; i<tam; i++){
		vetor[i] = i+1;
	}

    double tempo;
    clock_t inicio, fim;
    //imprime_vetor(vetor, tam);
    inicio = clock();
    quickSortLomuto(vetor, 0, tam-1);
    fim = clock();
    tempo = (double) (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %.7f\n", tempo);
    // imprime_vetor(vetor, 9);

    return 0;
}
