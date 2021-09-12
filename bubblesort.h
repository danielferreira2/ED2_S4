void bubbleSort(long int vetor[], long int n)
{
    long int temp;

    for (long int i = 0; i < n; i++)
    {
        for (long int j = i + 1; j < n; j++)
        {

            if (vetor[i] > vetor[j])
            {

                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}
