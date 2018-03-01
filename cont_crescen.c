#include <stdio.h>
#include <string.h>
#include <locale.h>
#define tam 10


int main (){

    setlocale(LC_ALL, "Portuguese");
    int vet[tam], i, x, y, aux;

    printf("\nEntre com %i numeros para o Vetor\n", tam);
    for(i=0;i<tam;i++){
            printf("\tNumero %i: ", i+1);
            scanf("%i", &vet[i]);
    }
    for(x=0;x<tam;x++){
     for(y=x+1;y<tam;y++){
        if (vet[x]>vet[y])
        {
            aux = vet[x];
            vet[x] = vet[y];
            vet[y] = aux;
        }
     }
    }

    printf("\nElementos na ordem Crescente:");
     for(x=0;x<tam;x++)
     {
         printf(" %i", vet[x]);
     }

    printf("\n\n");
    system ("pause");
    return 0;

}
