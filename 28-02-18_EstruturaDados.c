#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


#define num 2
typedef struct Agenda{
	    char nome[30];
	    char fone[15];
	    int idade;
	}agenda;

void pesquisa (int op);

int main (){
setlocale(LC_ALL, "Portuguese");

	agenda a[num];
	int x, op;
	printf("==== Informe os Dados para Agenda ====\n\n");

	for(x=0;x<num;x++)
    {
        printf("\nNome: ");
        fflush (stdin);
        gets(a[x].nome);
        fflush (stdin);
        printf("Telefone: ");
        fflush (stdin);
        gets(a[x].fone);
        fflush (stdin);
        printf("Idade: ");
        fflush (stdin);
        scanf("%d", &a[x].idade);
    }
    system("cls");
    printf(" ====== Menu de Opções ======\n\n\n");
    printf("1 - Procurar Nome\n");
    printf("2 - Procurar Fone\n");
    printf("3 - Média das Idades\n");
    printf("4 - Imprimir Agenda\n");
    printf("5 - Sair\n");
    printf("\n\nSelecione uma das Opções: ");
    scanf("%d", &op);

    do(op>0 && op<5){
        if (op<=4 && op>0)
        pesquisa (op);
    else if (op<0 || op>5)
        printf("== Opção Inválida ==");
    }while (op==5)


	system ("pause");
	return 0;

}

void pesquisa (int op){
    system ("cls");
printf("\n\nTeste de Chamada %d\n\n", op);
}
