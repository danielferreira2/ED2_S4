void countingSort(long int vetor[], long int n)
{
    long int vetorFinal[n], i;

    long int maiorValor = vetor[0];
    for (i = 1; i < n; i++)
    {
        if (vetor[i] > maiorValor)
            maiorValor = vetor[i];
    }

    long int count[n];

    for (i = 0; i <= maiorValor; ++i)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[vetor[i]]++;
    }

    for (i = 1; i <= maiorValor; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        vetorFinal[count[vetor[i]] - 1] = vetor[i];
        count[vetor[i]]--;
    }

    for (i = 0; i < n; i++)
    {
        vetor[i] = vetorFinal[i];
    }
}