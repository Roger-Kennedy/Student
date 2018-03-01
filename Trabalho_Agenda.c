/*
Aluno: Roger Kennedy
Turma: Sistemas de Informação 3° Período
Disciplina: Estrutura de Dados
*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>


#define num 1 //define o numero de contatos para agenda

typedef struct Agenda{
	    char nome[30];
	    char fone[15];
	    int idade;
	}agenda;

agenda pesquisa (int op, agenda a[num]);
agenda nome (agenda a[num]); //pesquisa por nome
agenda fone (agenda a[num]); //pesquisa por telefone
agenda media (agenda a[num]); //media das idades
agenda imp (agenda a[num]); //imprimir agenda

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

        printf("Telefone: ");
        fflush (stdin);
        gets(a[x].fone);

        printf("Idade: ");
        scanf("%d", &a[x].idade);
        getchar ();
    }

    do {
    system("cls");
    printf(" ====== Menu de Opções ======\n\n\n");
    printf("1 - Pesquisa por Nome\n");
    printf("2 - Pesquisa por Telefone\n");
    printf("3 - Média das Idades\n");
    printf("4 - Imprimir Agenda\n");
    printf("5 - Sair\n");
    printf("\n\nSelecione uma das Opções: ");
    scanf("%d", &op);
    if (op<=4 && op>0)
    pesquisa (op, a);
    else if (op<0 || op>5)
    printf("\n== Opção Inválida ==\n");
    system ("pause");
        } while (op!=5);

	return 0;

}

agenda pesquisa (int op, agenda a[num]){

    switch (op)
    {
        case 1:
            nome(a);
            break;
        case 2:
            fone(a);
            break;
        case 3:
            media(a);
            break;
        case 4:
            imp(a);
            break;
    }
}

agenda nome (agenda a[num]){

    char nomep[30];
    int i;

    system ("cls");
    printf("==== Pesquisa Por Nome ====\n\n\n");
    printf("Digite o nome para pesquisa: ");
    fflush(stdin);
    gets(nomep);

    for(i=0;i<num;i++)
    {
        if (strcmpi(nomep,a[i].nome) == 0)
            printf("\nNome: %s\nTelefone: %s\nIdade: %i\n\n", a[i].nome, a[i].fone, a[i].idade);
        else if (strcmpi(nomep,a[i].nome) == 1)
            printf("\n## Nome não encontrado na agenda ##\n\n");
    }


}



agenda fone (agenda a[num]){

    int i;
    char fonep[15];

    system ("cls");
    printf("==== Pesquisa Por Telefone ====\n\n\n");
    printf("Informe o Telefone para pesquisa: ");
    fflush(stdin);
    gets(fonep);

    for(i=0;i<num;i++)
    {
        if (strcmp(fonep,a[i].fone) == 0)
            printf("\nNome: %s\nTelefone: %s\nIdade: %i\n\n", a[i].nome, a[i].fone, a[i].idade);
        else if (strcmp(fonep,a[i].fone) == 1)
            printf("\n## Telefone não encontrado na agenda ##\n\n");

    }
}



agenda media (agenda a[num]){ //calcula a média das idades dos contatos

    int i;
    fflush(stdin);
    int mediai=0;


   for(i=0;i<num;i++)
        mediai+=a[i].idade;
    mediai=mediai/num;

    system("cls");
    printf("A Média das idades é: %i\n\n", mediai);

}


agenda imp (agenda a[num]){ //imprime os dados de todos os contatos

    int i;

    system("cls");
    printf("==== Lista de Contatos ====\n\n");

    for (i=0;i<num;i++){
        printf("Nome: %s\n", a[i].nome);
        printf("Telefone: %s\n", a[i].fone);
        printf("Idade: %i\n\n", a[i].idade);

    }


}
