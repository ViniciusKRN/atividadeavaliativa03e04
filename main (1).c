
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vet[15], i, n;
    
    srand(time(NULL)); // o "srand" é para para que toda vez que o vetor for gerar um numero aleatorio 
    //pelo "rand" ele vai ser difernete do anterior.

    
    for(i = 0; i <15; i++)
    vet[i] = rand() % 1001; //o rand sem o S é para gerar um outro número aleatório,
    //mas limitado para até 100 no maximo, já que eu coloquei a operação de resto para até 100
    printf("Vetor aleatoriamente gerado:\n");
    for(i = 0; i < 15; i++)
        printf("%d ", vet[i]);
        printf("\n");
        
        printf("\n\nQual valor deseja buscar? ");
        scanf("%d", &n);
        
        for(i = 0; i < 15; i++) 
            if(vet[i] == n)
                printf(" %d esta na posição %d do vetor. \n", n, i); //busca se o digitor que você digitou 
                //está entre valores gerados aleatoriamente anteriormente.
        

    return 0;
}
