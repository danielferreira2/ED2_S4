void reHeap(long int vetor[], long int n, long int i)
{

    //raiz começa em i
    long int maior = i;

    //filhos
    long int esquerda = 2 * i + 1;
    long int direita = 2 * i + 2;
    long int temp;

    //verifica filho a esquerda
    if (esquerda < n && vetor[i] < vetor[esquerda])
    {
        maior = esquerda;
    }

    //verifica filho a direita
    if (direita < n && vetor[maior] < vetor[direita])
    {
        maior = direita;
    }

    //troca
    if (maior != i)
    {
        temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        reHeap(vetor, n, maior);
    }
}

void heapSort(long int vetor[], long int n)
{

    long int pai = n / 2 - 1;
    long int temp;

    //inicia
    for (long int i = pai; i > -1; i--)
    {
        reHeap(vetor, n, i);
    }

    for (long int i = n - 1; i > 0; i--)
    {
        temp = vetor[i];
        vetor[i] = vetor[0];
        vetor[0] = temp;
        reHeap(vetor, i, 0);
    }
}