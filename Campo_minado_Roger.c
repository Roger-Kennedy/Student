/* Campo Minado
 * Disciplina: Linguagem de Programação I
 * Equipe: Roger Kennedy Lopes dos Santos Oliveira;
 * Curso: Sistemas de Informacao 2 Periodo
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int status(int matriz[4][5],int linha, int coluna);//retorna status da matriz
void tela_inicio();//tela inicial do jogo
void gameover(void);//tela de Game Over
void winner(void); //tela de Winner
void imprimecampo(int campo[4][5], int i, int j);//funcao para imprimir campo apos o rand

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese");
    int campo[4][5];
    char campo2[4][5];
    int i,j, sair,n=2,b=0,c=0, b2=0;//i e j sao para os lacos de repeticao; n para o rand; sair para verificar opcao digitada; b sao os espacos em branco da matriz campo; c para numerar as linhas do campo;b2 sao espacos em branco da matriz campo2
    int erros=0;//contagem de erros
    int bomba=0;//numero de bombas no campo


    printf("\n\t\t\t\t\a JOGO DE CAMPO MINADO\n\n");
    printf("\n\t\t Precione 1 para Continuar e 2 para Sair\n\n");
    scanf("%i", &sair);
        if(sair==2){
            printf("\n\n\t\tOpção SAIR Selecionada.\n\n");
            system("pause");
            return 0;
                }
tela_inicio();//chama funcao de tela

    printf("\n0 1 2 3 4\n");
        //gera valores para o campo
        srand(time(NULL));
        for(i=0;i<4;i++){
                for(j=0;j<5;j++)
                campo[i][j]=rand()%n;
        }
        //contagem das bombas
        for(i=0;i<4;i++){
            for(j=0;j<5;j++){
                if(campo[i][j]==1)
                    bomba+=1;
            }
        }
b=(i*j)-bomba;//contagem  de campos em branco
//imprimecampo(campo,i,j);//caso queira verificar quantas bombas existem no campo


        for(i=0;i<4;i++){
            for(j=0;j<5;j++){
                campo2[i][j] = '#';
                printf("%c ",campo2[i][j]);
            }
            printf("%i     ", c);
            printf("\t\t\t\n");
            c++;
        }

    do{

    printf("Digite a linha: ");
    fflush(stdin);
    scanf("%d",&i);
    printf("Digite a coluna: ");
    fflush(stdin);
    scanf("%d",&j);


//executa a funcao status
    if(status(campo,i,j)==1){
        printf("\nBOMBA ENCONTRADA\n");
        campo2[i][j] = '@';
        erros++;
        printf("Você tem %i chances\n\n", 4-erros);

    }
    else{
        printf("\nLIVRE\n");
        campo2[i][j] = ' ';

    }

    c=0;
    printf("\n0 1 2 3 4\n");//imprimi numeracao de colunas
    for(i=0;i<4;i++){
        for(j=0;j<5;j++)
            printf("%c ", campo2[i][j]);
        printf("%i     ", c); //imprimi numeracao de linhas
        printf("\n");
        c++;
        if(campo2[i][j]==' ')
            b2+=1;
            if (b==b2){//calcula campos em brancos abertos em branco e compara com quantidade de campos em branco na matriz
                winner(); //caso a quantidade de campos abertos sem bombas sejam iguais a quantidade de campos em branco da matriz o usuario vence o jogo
                return 0;
            }
        }


    }while(erros<4);//gameover no 4º erro
gameover();
return 1;
}

int status(int matriz[4][5],int linha, int coluna){
    system("cls");
    if(matriz[linha][coluna]==1)
        return 1;
    else
        return 0;
}


void tela_inicio(){
system("cls");
printf("@@@@@@  @@@@@@  @@    @@  @@@@@@@  @@@@@@@    @@    @@  @@  @@    @@  @@@@@@  @@@@@@    @@@@@@@\n");
printf("@@      @@  @@  @@ @@ @@  @@   @@  @@   @@    @@ @@ @@  @@  @@@   @@  @@  @@  @@    @   @@   @@\n");
printf("@@      @@  @@  @@ @@ @@  @@@@@@@  @@   @@    @@ @@ @@  @@  @@ @  @@  @@  @@  @@     @  @@   @@\n");
printf("@@      @@@@@@  @@    @@  @@       @@   @@    @@    @@  @@  @@  @ @@  @@@@@@  @@    @   @@   @@\n");
printf("@@@@@@  @@  @@  @@    @@  @@       @@@@@@@    @@    @@  @@  @@   @@@  @@  @@  @@@@@@    @@@@@@@\n\n\n");


printf("\n\n\t\t\t\t\tVocê tem 4 tentativas... Bom Jogo!\n\n\n");
}
void gameover(void){
system("cls");
printf("@@@@@@@@@  @@@@@@@   @@    @@  @@@@@@     @@@@@@@   @@  @@  @@@@@@    @@@@@@\n");
printf("@@         @@   @@   @@ @@ @@  @@         @@   @@   @@  @@  @@        @@  @@\n");
printf("@@         @@   @@   @@ @@ @@  @@@@@@     @@   @@   @@  @@  @@@@@@    @@  @@\n");
printf("@@  @@@@@  @@@@@@@   @@ @@ @@  @@@@@@     @@   @@   @@  @@  @@@@@@    @@@@@@\n");
printf("@@    @@@  @@   @@   @@    @@  @@         @@   @@    @  @   @@        @@ @@\n");
printf("@@@@@@@@@  @@   @@   @@    @@  @@@@@@@    @@@@@@@     @@    @@@@@@    @@  @@\n\n\n");


system("pause");

}
void winner(void){
system("cls");
printf("@@    @@  @@   @@   @@  @@   @@  @@@@@@  @@@@@@\n");
printf("@@    @@  @@   @@@  @@  @@@  @@  @@      @@  @@ \n");
printf("@@ @@ @@  @@   @@ @ @@  @@ @ @@  @@@@@@  @@@@@@ \n");
printf("@@ @@ @@  @@   @@  @@@  @@  @@@  @@      @@ @@  \n");
printf("@@    @@  @@   @@   @@  @@   @@  @@@@@@  @@  @@ \n\n\n");



system("pause");

}

void imprimecampo(int campo[4][5], int i, int j){

    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            printf("%c ", campo[i][j]);
        }
        printf("\n");
}
printf("\n\n");
}
