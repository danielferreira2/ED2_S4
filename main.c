#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "tempos.h"

void iniciaVetor(long int vetor[], long int n)
{
    for (long int i = 0; i < n; i++)
    {
        vetor[i] = 1 + rand() % n;
        vetor[i] += 1 + rand() % n;
    }
}
void copiaVetor(long int vetor[], long int vetorCopia[], long int n)
{
    for (long int i = 0; i < n; i++)
    {
        vetorCopia[i] = vetor[i];
    }
}

void imprimeVetor(long int vetor[], long int n)
{
    for (long int i = 0; i < n; i++)
    {
        printf("%ld ", vetor[i]);
    }
    printf("\n");
}
void imprimeArquivo(FILE *arquivo, long int vetor[], long int n, char *string)
{
    fprintf(arquivo, "%s de %ld elementos.\n", string, n);
    for (long int i = 0; i < n; i++)
    {
        fprintf(arquivo, "elemento %ld = [%ld]\n", i, vetor[i]);
    }
}

int main()
{
    srand(time(NULL));
    mkdir("Saida"); //criar pasta de saida

    FILE *tabela, *arquivoVetor, *arquivoVetorBubble, *arquivoVetorHeap, *arquivoVetorCounting;

    printf("Aguarde ate o final da execucao do programa(pode demorar)!\n");
    char *linha1 = "        ,             , BubbleSort, HeapSort, CoutingSort ";
    char *linha2 = "Problema , Tamanho(n) , Tempo (ms) , Tempo (ms) , Tempo(ms) ";
    long int tamanho;

    printf("Escreva o tamanho do vetor aleatorio:\n");
    scanf("%ld", &tamanho);

    long int vetor[tamanho];
    long int vetor2[tamanho];
    long int vetor3[tamanho];

    iniciaVetor(vetor, tamanho);
    copiaVetor(vetor, vetor2, tamanho);
    copiaVetor(vetor, vetor3, tamanho);

    //imprimir no arquivo  vetor desordenado
    arquivoVetor = fopen("Saida//ArquivoVetor.txt", "w");
    imprimeArquivo(arquivoVetor, vetor, tamanho, "Vetor Aleatorio");
    fclose(arquivoVetor);
    
    double counting = tempoCountingSort(vetor3, tamanho);
    double heap = tempoHeapSort(vetor2, tamanho);
    double bubble = tempoBubbleSort(vetor, tamanho);

    //imprimir cada arquivo de cada vetor defidamente ordenado pelos seus respectivos algoritimos
    arquivoVetorBubble = fopen("Saida//ArquivoVetorBubble.txt", "w");
    imprimeArquivo(arquivoVetorBubble, vetor, tamanho, "Vetor ordenado pelo bubble sort");
    fclose(arquivoVetorBubble);

    arquivoVetorHeap = fopen("Saida//ArquivoVetorHeap.txt", "w");
    imprimeArquivo(arquivoVetorHeap, vetor, tamanho, "Vetor ordenado pelo heap sort");
    fclose(arquivoVetorHeap);

    arquivoVetorCounting = fopen("Saida//ArquivoVetorCounting.txt", "w");
    imprimeArquivo(arquivoVetorCounting, vetor, tamanho, "Vetor ordenado pelo counting sort");
    fclose(arquivoVetorCounting);

    tabela = fopen("Saida//Tabela.csv", "w");
    fprintf(tabela, linha1);
    fprintf(tabela, "\n");
    fprintf(tabela, linha2);
    fprintf(tabela, "\n");
    fprintf(tabela, "1,%ld, %.5lf ,%.5lf, %.5lf\n", tamanho, bubble, heap, counting);

    printf("Tabela.csv criada! utilize exel ou libreoffice pra abrir\n");
    fclose(tabela);

    printf("Tempo de execucao(ms):|| BubbleSort || HeapSort || CoutingSort||\n");
    printf("----------------------|| %.5lf||%.5lf||%.5lf||\n", bubble, heap, counting);

    return 0;
}
