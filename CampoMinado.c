/*
 * File:   main.cpp
 * Author: Franklyn
 *
 * Created on 9 de Novembro de 2017, 22:59
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <time.h>
void level1(void);
void level2(void);
void level3(void);
int movimenta_tab1(int a, int b);
int movimenta_tab2(int a, int b);
int movimenta_tab3(int a, int b);
void tela_inicio(void);
void tela_sorteio(void);
void tela_bomba(void);
void tela_gameover(void);
void tela_winner(void);

int main (int argc, char** argv) {



    int tab3 [9] [11];
	int i,l, generica;
	char alerta[50]={255};







    //tela inicial
for (i=0;i<50;i++)

		{
	i=0;
    		tela_inicio();

				printf("\nCarregamento concluido...");
				printf("\n\n 				%s\n Aperte 1 para continuar\n Aperte 2 para sair\n			Digite: ", alerta);
				generica=0;
				fflush(stdin);
				scanf("%d",&generica);

					if(generica==2)
					{
						return 0;

		            }

    else if(generica==1)
	{
		i=50;
	}


    else
	{
		system("cls");

		alerta[0]='o';
		alerta[1]='p';
		alerta[2]='c';
		alerta[3]='a';
		alerta[4]='o';
		alerta[5]=' ';
		alerta[6]='i';
		alerta[7]='n';
		alerta[8]='v';
		alerta[9]='a';
		alerta[10]='l';
		alerta[11]='i';
		alerta[12]='d';
		alerta[13]='a';
		alerta[14]='!';



    	}

}


system("cls");
tela_inicio();
printf("\n\n 1- level facil\n 2- level medio\n 3- level dificil\n\n			selecione o level: ");
generica=0;
fflush(stdin);

scanf("%d",& generica);

 switch(generica)
 {
 	case 1: level1();
 	break;
 	case 2: level2();
 	break;
 	case 3: level3();
 	break;
 }









return 0;
}

void level1(void){

    int tab [5] [7];
	int i,l;
	int linha,coluna,qtbomba=0,qtnobomba=0;


	char piso=178,nobomb=177,bomb=42;  //variavel responsavel pelos casas q ainda não foram abertas


	for(i=0;i<5;i++){      //for que preenche o tabuleiro level facil com piso
		for(l=0;l<=7;l++){

        tab[i] [l] = piso;

            }
    }



	for (i=0;i<50;i++){


	do{
    i=0;


	system("cls");
    printf("\n\n\n\n\n");
    printf("					    0  1  2  3  4  5 \n\n");
    printf("					0   %c |%c |%c |%c |%c |%c\n",tab [0] [0],tab [0] [1],tab [0] [2],tab [0] [3],tab [0] [4],tab [0] [5],tab [0] [6]);
    printf("					    ----------------\n");
    printf("					1   %c |%c |%c |%c |%c |%c\n",tab [1] [0],tab [1] [1],tab [1] [2],tab [1] [3],tab [1] [4],tab [1] [5],tab [1] [6]);
    printf("					    ----------------\n");
    printf("					2   %c |%c |%c |%c |%c |%c\n",tab [2] [0],tab [2] [1],tab [2] [2],tab [2] [3],tab [2] [4],tab [2] [5],tab [2] [6]);
    printf("					    ----------------\n");
    printf("					3   %c |%c |%c |%c |%c |%c\n",tab [3] [0],tab [3] [1],tab [3] [2],tab [3] [3],tab [3] [4],tab [3] [5],tab [3] [6]);
        printf("\n			bombas encontradas: %d/%d",qtbomba,3-qtbomba);
    	printf("\n\n			digite a linha: ");   //direciona linha da matriz
    	scanf("%d",&linha);
    	printf("\n			digite a coluna: ");  //direciona coluna da matriz
    	scanf("%d",&coluna);

				if (tab[linha] [coluna]==177){  // controle para caso o usuario digite uma casa ja aberta
						printf("\n							casa ja liberada, informe outra cordenada !\n\n\n");
				system ("pause");
                                             }
	            else if(linha>3){
	            	printf("\n							linha inexistente, informe outra\n\n"); //controle para caso o usuario digite uma linha inexistente
	            	system("pause");
				}

                else if(coluna>5){
	            	printf("\n							coluna inexistente, informe outra\n\n\n"); //controle para caso o usuario digite uma coluna inexistente
	            	system("pause");
				}

				else if (tab[linha] [coluna]==42){ //controle para informar que o usauario ja encontrou uma mina nesta posiçãao
						printf("\n							Uma mina ja foi encontrada nesta casa, tente o azar nas proximas!\n\n\n");
				system ("pause");

                }

                else{
                	i=9;
				}

}while(i==!9); //caso o usuario digite uma casa valida sai do looping, contrario ee digitara de novo

                tab [linha] [coluna]= movimenta_tab1(linha,coluna); //chama função com linha e coluna digitada para validação

				if(tab [linha] [coluna]==42) // se o usario encontrar uma bomba mostra tela de bomba, e incrementa dados na variavel qtbomba para validação futura
				{
					qtbomba=qtbomba+1;
					system("cls");
                	tela_bomba();
                	printf("																					%d tentativas restantes\n", 3-qtbomba);
                	system("pause");

                }

				if(tab [linha] [coluna]==177)// incrementa dados na variavel qtnobomba para validaçao futura
				{
					qtnobomba=qtnobomba+1;
				}


				if (qtbomba>2)//caso o usuario atinja o limite de bomas 3 o jogo é finaliazo mostrando a tela game over e saindo do looping
				{
                system("cls");
				tela_gameover();
				system("pause");
				i=50;
				}




                if(qtnobomba==21 && qtbomba<3) //caso o usuario vença o jogo sai do looping apresentando a tela winner
				{
                system("cls");
				tela_winner();
				system("pause");
                i=50;
				}




}









}

void level2(void){

    int tab [7] [9];
	int i,l;
	int linha,coluna,qtbomba=0,qtnobomba=0;


	char piso=178,nobomb=177,bomb=42;  //variavel responsavel pelos casas q ainda não foram abertas


	for(i=0;i<7;i++){      //for que preenche o tabuleiro level facil com piso
		for(l=0;l<=9;l++){

        tab[i] [l] = piso;

            }
    }



	for (i=0;i<50;i++){


	do{
    i=0;


	system("cls");
    printf("\n\n\n\n\n");
    printf("					    0  1  2  3  4  5  6  7       \n\n");
    printf("					0   %c |%c |%c |%c |%c |%c |%c |%c\n",tab [0] [0],tab [0] [1],tab [0] [2],tab [0] [3],tab [0] [4],tab [0] [5],tab [0] [6],tab [0] [7],tab [0] [8]);
    printf("					    -----------------------\n");
    printf("					1   %c |%c |%c |%c |%c |%c |%c |%c\n",tab [1] [0],tab [1] [1],tab [1] [2],tab [1] [3],tab [1] [4],tab [1] [5],tab [1] [6],tab [1] [7],tab [1] [8]);
    printf("					    -----------------------\n");
    printf("					2   %c |%c |%c |%c |%c |%c |%c |%c\n",tab [2] [0],tab [2] [1],tab [2] [2],tab [2] [3],tab [2] [4],tab [2] [5],tab [2] [6],tab [2] [7],tab [2] [8]);
    printf("					    -----------------------\n");
    printf("					3   %c |%c |%c |%c |%c |%c |%c |%c\n",tab [3] [0],tab [3] [1],tab [3] [2],tab [3] [3],tab [3] [4],tab [3] [5],tab [3] [6],tab [3] [7],tab [3] [8]);
    printf("					    -----------------------\n");
    printf("					4   %c |%c |%c |%c |%c |%c |%c |%c\n",tab [4] [0],tab [4] [1],tab [4] [2],tab [4] [3],tab [4] [4],tab [4] [5],tab [4] [6],tab [4] [7],tab [4] [8]);
    printf("					    -----------------------\n");
    printf("					5   %c |%c |%c |%c |%c |%c |%c |%c\n",tab [5] [0],tab [5] [1],tab [5] [2],tab [5] [3],tab [5] [4],tab [5] [5],tab [5] [6],tab [5] [7],tab [5] [8]);
        printf("\n			bombas encontradas: %d",qtbomba);
    	printf("\n\n			digite a linha: ");   //direciona linha da matriz
    	scanf("%d",&linha);
    	printf("\n			digite a coluna: ");  //direciona coluna da matriz
    	scanf("%d",&coluna);

				if (tab[linha] [coluna]==177){  // controle para caso o usuario digite uma casa ja aberta
						printf("\n							casa ja liberada, informe outra cordenada !\n\n\n");
				system ("pause");
                                             }
	            else if(linha>5){
	            	printf("\n							linha inexistente, informe outra\n\n"); //controle para caso o usuario digite uma linha inexistente
	            	system("pause");
				}

                else if(coluna>7){
	            	printf("\n							coluna inexistente, informe outra\n\n\n"); //controle para caso o usuario digite uma coluna inexistente
	            	system("pause");
				}

				else if (tab[linha] [coluna]==42){ //controle para informar que o usauario ja encontrou uma mina nesta posiçãao
						printf("\n							Uma mina ja foi encontrada nesta casa, tente o azar nas proximas!\n\n\n");
				system ("pause");

                }

                else{
                	i=9;
				}

}while(i==!9); //caso o usuario digite uma casa valida sai do looping, contrario ee digitara de novo

                tab [linha] [coluna]= movimenta_tab2(linha,coluna); //chama função com linha e coluna digitada para validação

				if(tab [linha] [coluna]==42) // se o usario encontrar uma bomba mostra tela de bomba, e incrementa dados na variavel qtbomba para validação futura
				{
					qtbomba=qtbomba+1;
					system("cls");
                	tela_bomba();
                	printf("																					%d tentativas restantes\n", 5-qtbomba);
                	system("pause");

                }

				if(tab [linha] [coluna]==177)// incrementa dados na variavel qtnobomba para validaçao futura
				{
					qtnobomba=qtnobomba+1;
				}


				if (qtbomba>4)//caso o usuario atinja o limite de bomas 3 o jogo é finaliazo mostrando a tela game over e saindo do looping
				{
                system("cls");
				tela_gameover();
				system("pause");
				i=50;
				}




                if(qtnobomba==63 && qtbomba<4) //caso o usuario vença o jogo sai do looping apresentando a tela winner
				{
                system("cls");
				tela_winner();
				system("pause");
                i=50;
				}




}









}

void level3(void){

    int tab [9] [11];
	int i,l;
	int linha,coluna,qtbomba=0,qtnobomba=0;


	char piso=178,nobomb=177,bomb=42;  //variavel responsavel pelos casas q ainda não foram abertas


	for(i=0;i<9;i++){      //for que preenche o tabuleiro level facil com piso
		for(l=0;l<=11;l++){

        tab[i] [l] = piso;

            }
    }



	for (i=0;i<50;i++){


	do{
    i=0;


	system("cls");
    printf("\n\n\n\n\n");
    printf("					    0  1  2  3  4  5  6  7  8  9  10 \n\n");
    printf("					0   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [0] [0],tab [0] [1],tab [0] [2],tab [0] [3],tab [0] [4],tab [0] [5],tab [0] [6],tab [0] [7],tab [0] [8],tab [0] [9],tab [0] [10]);
    printf("					    ----------------------------\n");
    printf("					1   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [1] [0],tab [1] [1],tab [1] [2],tab [1] [3],tab [1] [4],tab [1] [5],tab [1] [6],tab [1] [7],tab [1] [8],tab [1] [9],tab [1] [10]);
    printf("					    ----------------------------\n");
    printf("					2   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [2] [0],tab [2] [1],tab [2] [2],tab [2] [3],tab [2] [4],tab [2] [5],tab [2] [6],tab [2] [7],tab [2] [8],tab [2] [9],tab [2] [10]);
    printf("					    ----------------------------\n");
    printf("					3   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [3] [0],tab [3] [1],tab [3] [2],tab [3] [3],tab [3] [4],tab [3] [5],tab [3] [6],tab [3] [7],tab [3] [8],tab [3] [9],tab [3] [10]);
    printf("					    ----------------------------\n");
    printf("					4   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [4] [0],tab [4] [1],tab [4] [2],tab [4] [3],tab [4] [4],tab [4] [5],tab [4] [6],tab [4] [7],tab [4] [8],tab [4] [9],tab [4] [10]);
    printf("					    ----------------------------\n");
    printf("					5   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [5] [0],tab [5] [1],tab [5] [2],tab [5] [3],tab [5] [4],tab [5] [5],tab [5] [6],tab [5] [7],tab [5] [8],tab [5] [9],tab [5] [10]);
    printf("					    ----------------------------\n");
    printf("					6   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [6] [0],tab [6] [1],tab [6] [2],tab [6] [3],tab [6] [4],tab [6] [5],tab [6] [6],tab [6] [7],tab [6] [8],tab [6] [9],tab [6] [10]);
    printf("					    ----------------------------\n");
    printf("					7   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [7] [0],tab [7] [1],tab [7] [2],tab [7] [3],tab [7] [4],tab [7] [5],tab [7] [6],tab [7] [7],tab [7] [8],tab [7] [9],tab [7] [10]);
    printf("					    ----------------------------\n");
    printf("					8   %c |%c |%c |%c |%c |%c |%c |%c |%c |%c |%c\n",tab [8] [0],tab [8] [1],tab [8] [2],tab [8] [3],tab [8] [4],tab [8] [5],tab [8] [6],tab [8] [7],tab [8] [8],tab [8] [9],tab [8] [10]);
        printf("\n			bombas encontradas: %d",qtbomba);
    	printf("\n\n			digite a linha: ");   //direciona linha da matriz
    	scanf("%d",&linha);
    	printf("\n			digite a coluna: ");  //direciona coluna da matriz
    	scanf("%d",&coluna);

				if (tab[linha] [coluna]==177){  // controle para caso o usuario digite uma casa ja aberta
						printf("\n							casa ja liberada, informe outra cordenada !\n\n\n");
				system ("pause");
                                             }
	            else if(linha>8){
	            	printf("\n							linha inexistente, informe outra\n\n"); //controle para caso o usuario digite uma linha inexistente
	            	system("pause");
				}

                else if(coluna>10){
	            	printf("\n							coluna inexistente, informe outra\n\n\n"); //controle para caso o usuario digite uma coluna inexistente
	            	system("pause");
				}

				else if (tab[linha] [coluna]==42){ //controle para informar que o usauario ja encontrou uma mina nesta posiçãao
						printf("\n							Uma mina ja foi encontrada nesta casa, tente o azar nas proximas!\n\n\n");
				system ("pause");

                }

                else{
                	i=9;
				}

}while(i==!9); //caso o usuario digite uma casa valida sai do looping, contrario ee digitara de novo

                tab [linha] [coluna]= movimenta_tab3(linha,coluna); //chama função com linha e coluna digitada para validação

				if(tab [linha] [coluna]==42) // se o usario encontrar uma bomba mostra tela de bomba, e incrementa dados na variavel qtbomba para validação futura
				{
					qtbomba=qtbomba+1;
					system("cls");
                	tela_bomba();
                	printf("																					%d tentativas restantes\n", 5-qtbomba);
                	system("pause");

                }

				if(tab [linha] [coluna]==177)// incrementa dados na variavel qtnobomba para validaçao futura
				{
					qtnobomba=qtnobomba+1;
				}


				if (qtbomba>4)//caso o usuario atinja o limite de bomas 3 o jogo é finaliazo mostrando a tela game over e saindo do looping
				{
                system("cls");
				tela_gameover();
				system("pause");
				i=50;
				}




                if(qtnobomba==99 && qtbomba<4) //caso o usuario vença o jogo sai do looping apresentando a tela winner
				{
                system("cls");
				tela_winner();
				system("pause");
                i=50;
				}




}









}


int movimenta_tab1(int a, int b){
    int i, l, lbomblinha,lbombcoluna;
	int tab [5] [7]; //tabuleiro comparativo do level facil
    int nobomb=177;
    int bomb=42;

    	for(i=0;i<5;i++){ //transformação do tabuleiro para 0
		for(l=0;l<=7;l++){

        tab[i] [l] = 0;
		}
    }
    for(i=0;i<5;i++)
	{

    lbomblinha= rand() % 5;
    lbombcoluna= rand() % 7;
    tab [rand()%5] [rand() % 7]=1;
}



	if(tab[a] [b]==1){
        tab[a] [b]=bomb;
    }
    else
	tab[a] [b]=nobomb;



    return tab[a] [b];
}

int movimenta_tab2(int a, int b){

    int i, l, lbomblinha,lbombcoluna;
	int tab [7] [9]; //tabuleiro comparativo do level facil
    int nobomb=177;
    int bomb=42;

    	for(i=0;i<5;i++){ //transformação do tabuleiro para 0
		for(l=0;l<=7;l++){

        tab[i] [l] = 0;
		}
    }
    for(i=0;i<7;i++)
	{

    lbomblinha= rand() % 5;
    lbombcoluna= rand() % 7;
    tab [rand()%5] [rand() % 7]=1;
}



	if(tab[a] [b]==1){
        tab[a] [b]=bomb;
    }
    else
	tab[a] [b]=nobomb;



    return tab[a] [b];
}

int movimenta_tab3(int a, int b){
    int i, l, lbomblinha,lbombcoluna;
	int tab [9] [11]; //tabuleiro comparativo do level facil
    int nobomb=177;
    int bomb=42;

    	for(i=0;i<9;i++){ //transformação do tabuleiro para 0
		for(l=0;l<=11;l++){

        tab[i] [l] = 0;
		}
    }
    for(i=0;i<5;i++)
	{

    lbomblinha= rand() % 5;
    lbombcoluna= rand() % 7;
    tab [rand()%5] [rand() % 7]=1;
}



	if(tab[a] [b]==1){
        tab[a] [b]=bomb;
    }
    else
	tab[a] [b]=nobomb;



    return tab[a] [b];
}

void tela_inicio(void){
printf("		,@:;+@.  .@'.#@;    :##;@    `@:`:@@`    ,@:;+@. @@++@@+@@@\n");
printf("		`@`   *   @;  .@;   @   '   +;     +@'   `@`   *     @@.\n");
printf("		`@        @,   @;  `@   :  ,@       @@   `@          @@:\n");
printf("		`@        @,  `@    @@`    @:       `@+  `@          @@\n");
printf("		`@####    @, `@     .@@#   @`        @@  `@####      @@\n");
printf("		`@        @;.@@       @@#  @,        @#  `@          @@\n");
printf("		`@        @,  @+       #@  @#        @,  `@          @@\n");
printf("		`@        @,  `@   +    @  @@       .@   `@          @@\n");
printf("		`@`       @;   `@  @    @   @@      @    `@`         @@\n");
printf("		`@.       @'    .# @# ##     #@+` :#     `@.         @@\n\n\n");

printf("     '+     #        ;           :;;`      :@@@.          ;           ;+   ``     .+      +      ;+;;.       `#@@;\n");
printf("  `@@;      @+       @     #     ;+`+@`   @;   @@         @     :,    +#   .@`    .@     +@      ;+ `'@@    #@   +@\n");
printf(" ,@`       @`@      ,@'   `@+    ;+  '@  @`     @:        @@    @@    ;+   :+@`   ,@     @,@     ;+    '@  '#     '@\n");
printf(" @        `@ :@     @ @   @ @    ;+  ;@ .@      ;@       ':@`  #.@    ;+   ;;`@`  :+    #. @`    ;+     @  @       @\n");
printf("@'        @`  @`    @ '+ :' @.   ;+  @  ++      :@       @ .@ `@ '+   ;+   ;; `@` :+    @  `@    ;+     @  @       @\n");
printf("@,       .@@@@@@   ,#  @ @  .@   ;#@@   ##      '#       @  @`@   @   ;+   +;  `@`:'   @@@@@@;   ;+    :@  @       @\n");
printf("#@       @     @;  @`  ;@`   @   ;#     .@      @`      ''  `@'   @`  ;+   @,   `@;'  `@     @   ;+   .@   @`     '#\n");
printf(" @#     :@     `@  @    #    @'  ;+      @#    @+       @    @    :@  ;+   @,    `@;  @.     @#  '+ .@@    :@    ;@\n");
printf("  ;@@@@ @`      @':@         `@  ++       +@@@@,        @          @  '@   @,     `, `@       @  +@@'       .@@@@+\n");
}
void tela_sorteio(void){


printf("                  `@@@; @@@@\n");
printf("                 #@@@@` @# @@`\n");
printf("                @@@@@@ .@`  @@;\n");
printf("              .@@@@@@@ #@@  @@@@\n");
printf("             @@@@@@@@@ @#@. @;`@@\n");
printf("            @@@@@@@@@# #@@@@@   @@.\n");
printf("           @@ @@@@@@@, @@@@@@;  @@@+\n");
printf("          .@  @@@@@@@ `@@@@@@@  @`.@@\n");
printf("          @; ;@@@@@@# :@@@@@@@@@@  ,@.\n");
printf("          @;,@@@@+ #@ @@@@@@@@@@@`  #@\n");
printf("          #@@@@@@  @@ @@  :@@@@@@@  @@\n");
printf("         +@@@@@@. @@; @'   @@@@@@@#@@+\n");
printf("         @@@@@@@,+@@  @''  @@@@@@#@@@'\n");
printf("         @@@@@@#@@@    @+@,@  `@#@@@@;\n");
printf("        .@@@@@#@@` `@@  :@@@.  @@@@@@,\n");
printf("        @@@@@#@@  @@#@@:  @@@  #@'@@@,\n");
printf("        @@@@#@` `@@@@#@@@  '@@:@`  @@.\n");
printf("        @@@#@  @@@@:  +@@@,  @@@;  @#`\n");
printf("       ;@@#` `@@@@@    @@@@@  +@@  @@\n");
printf("       @@@  @@@@@@@@',@@#@#@@.  @@@@@\n");
printf("       @` `@@@@@@@@@@@@@@#@@@@@  #@@@\n");
printf("         @@@.`'@@@@@@@@@#@#@@@@@`  @@\n");
printf("        @@@'   :@@@@   @@@@#@@@#@@  @\n");
printf("         @@@#`.@@@@@   `@@@@   `@@@`\n");
printf("           @@@@@@@@@@#@@@@@@:  .@@@@\n");
printf("            .@@@@@@@#@@@@@@@+@#@@@:\n");
printf("              +@@@@#@.:@@@++@@@@.\n");
printf("                @@#@    @@#@@@\n");
printf("                  @@@. ;@@@@\n");
printf("                   ,@@@@#+\n");


}

void tela_bomba(void){



printf("                                    ,'@@@@\n");
printf("                             .,.   `#@`@  .\n");
printf("                          +@@@@@@@@@@` @ \n");
printf("                         @@.                                         MINA ENCONTRADA\n");
printf("                        @@                                               PRESSIONE QUALQUER TECLA PARA CONTINUAR\n");
printf("                      ##\n ");
printf("                    @@@@@@@@\n");
printf("                    @@@@@@@@'\n");
printf("                   @.+@@@@;:@\n");
printf("                  @@@@@@@@@@@+\n");
printf("              ` @@@@;`    '@@@@;\n");
printf("               @@@           @@@@\n");
printf("              @@,     ,+@@@@@@#@@@\n");
printf("             @@    ;@@@@@@@@@@@@@@#\n");
printf("            @@`  '@@@@@@@@@@@@@@@@@:\n");
printf("           `@# `@@@@@@@@@@@@@@@@@@@@\n");
printf("           @@ :@@@@@@@@@@@@@@@@@@@@@;\n");
printf("           @+;@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("          :@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("           @@@@@@@@@@@@@@@@@@@@@@@@@:\n");
printf("            @@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("            @@@@@@@@@@@@@@@@@@@@:@@,\n");
printf("             @@@@@@@@@@@@@@@@@@ @@#\n");
printf("              @@@@@@@@@@@@@@@' @@@\n");
printf("               @@@@@@@@@@@#. `@@#``\n");
printf("                #@@@@:     :@@#,`\n");
printf("                  #@@@@@@@@@@'\n");
printf("                    `'#@@#:\n");


}

void tela_gameover(void){
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@++++++++++++@@@@@@@++++++++@@@@@@@+++++@@@@@@@+++++@@#++++++++++++++++@@@@@\n");
printf("@@@@@@@@@@@''''''''''''@@@@@@@'''''''+@@@@@@@'''''@@@@@@@'''''@@#''''''''''''''''@@@@@\n");
printf("@@@@@@@@@@@''''''''''''@@@@@@@'''''''+@@@@@@@'''''@@@@@@@'''''@@#''''''''''''''''@@@@@\n");
printf("@@@@@@@@+''''#@@@@@@@@@@@@@@'''''@@'''''@@@@@'''''''@@#'''''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@+''''#@@@@@@@@@@@@@@'''''@@'''''@@@@@'''''''@@#'''''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@'''''@@@@@@@@@@@@@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@'''''@@@@@@@@@@@@@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@'''''@@@@@+++++++@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''++++++++++@@@@@@@\n");
printf("@@@@@@'''''@@@@#'''''''@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''''''''''''@@@@@@@\n");
printf("@@@@@@'''''@@@@#'''''''@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''''''''''''@@@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#''''''''''''''''@@@'''''@@'''@@'''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#''''''''''''''''@@@'''''@@'''@@'''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@##+''''#@@@@'''''@@#''''+######'''''@@@'''''@@###@@'''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@+''''#@@@@'''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@'''''@@#''''#@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@+''''+####'''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@'''''@@#''''+###########@@@@@\n");
printf("@@@@@@@@@@@''''''''''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@'''''@@#''''''''''''''''@@@@@\n");
printf("@@@@@@@@@@@''''''''''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@'''''@@#''''''''''''''''@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");;
printf("@@@@@@@@+'''''''''''#@@@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''''''''''''@@@@@@@\n");
printf("@@@@@@@@+'''''''''''#@@@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''''''''''''@@@@@@@\n");
printf("@@@@@@++'''''''''''''++@@#''''+@@@@@@+''''@@@'''''''''''''''''@@#''''''''''''''++@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@@@@@@@@#''''#@@@@@@'''''@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@@@@@@@@#''''#@@@@@@'''''@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@@@@@@@@#''''#@@@@@@'''''@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#''''+@@@@@@+''''@@@'''''@@@@@@@@@@@@@@#''''#@@@@@@'''''@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#'''''''@@'''''''@@@''''''''''''''#@@@@#''''#@@@@'''''''@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#'''''''@@'''''''@@@''''''''''''''#@@@@#''''#@@@@'''''''@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@#'''''''##'''''''@@@''''''''''''''#@@@@#''''+####'''''''@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@@@@''''''''''''@@@@@'''''@@@@@@@@@@@@@@#'''''''''''+@@@@@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@@@@''''''''''''@@@@@'''''@@@@@@@@@@@@@@#'''''''''''+@@@@@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@@@@@@'''''''+@@@@@@@'''''@@@@@@@@@@@@@@#''''#@#'''''''@@@@@@@\n");
printf("@@@@@@'''''@@@@@@@'''''@@@@@@@'''''''+@@@@@@@'''''@@@@@@@@@@@@@@#''''#@#'''''''@@@@@@@\n");
printf("@@@@@@##+'''''''''''+##@@@@@@@###''###@@@@@@@'''''''''''''''''@@#''''#@@##'''''''@@@@@\n");
printf("@@@@@@@@+'''''''''''#@@@@@@@@@@@@''@@@@@@@@@@'''''''''''''''''@@#''''#@@@@'''''''@@@@@\n");
printf("@@@@@@@@+'''''''''''#@@@@@@@@@@@@''@@@@@@@@@@'''''''''''''''''@@#''''#@@@@'''''''@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

}

void tela_winner(void){
printf("\n\n\n                               ##\n");
printf("                                     ##\n");
printf("                                                                   \n");
printf("                        ##  ;##  ##. :##   '#####;    ;#####'    :'######` '######'.` \n");
printf("                        ##  '##  ##. :##  #########  #########  ,########` '########  \n");
printf("                        ##  '##  ##. :##  ###;::###  ###;::###  ###;:::::` '##:::'##`\n");
printf("                        ##  '##  ##. :##  ##.  `.##  ##:   `##  ###        '##    ##. \n");
printf("                        ##  '##  ##. :##  ##`   .##  ##,    ##  #########` '##,,,'##`  \n");
printf("                        ##  '##  ##. :##  ##`   .##  ##,    ##  #########` '########  \n");
printf("                        ##  '##  ##. :##  ##`   .##  ##,    ##  ##'......  '#######,  \n");
printf("                        ##, '##` ##. :##  ##`   .##  ##,    ##  ###        '## `##.`  \n");
printf("                        ###########  :##  ##`   .##  ##,    ##  #########` '##  :#'   \n");
printf("                        '##########` :##  ##`   .##  ##,    ##   ########` '##   ###  \n\n\n\n");
}
