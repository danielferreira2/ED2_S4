#include <time.h>
#include "bubblesort.h"
#include "heapsort.h"
#include "countingsort.h"

double tempoBubbleSort(long int vetor[], long int n)
{
    clock_t inicio = clock();
    bubbleSort(vetor, n);
    clock_t fim = clock();
    return (double)(fim - inicio)/(CLOCKS_PER_SEC/1000);
}

double tempoHeapSort(long int vetor[], long int n)
{   
    clock_t inicio = clock();
    heapSort(vetor, n);
    clock_t fim = clock();
    return (double)(fim - inicio)/(CLOCKS_PER_SEC/1000);
}

double tempoCountingSort(long int vetor[], long int n)
{
    clock_t inicio = clock();
    countingSort(vetor, n);
    clock_t fim = clock();
    return (double)(fim - inicio)/(CLOCKS_PER_SEC/1000);
}