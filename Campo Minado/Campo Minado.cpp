#include "conio.c"
#include <time.h>
#include <locale.h>
#include "conio.h"

int main()

{
 	  
 	  
 	setlocale(LC_ALL,"");  
 	  
	int erro, opc;
	int iDificult = 6;

	inicio:
	system("cls");
	textcolor(7);
	printf("*========================================*\n");
	printf("|       O que voce deseja fazer?         |\n");
	printf("*-------------------------*--------------*\n");
	printf("| 1 - Iniciar o Jogo      |  Dificuldade |\n");
	printf("| 2 - Opcoes do Jogo      |  "); textcolor(12);
	if (iDificult == 3) { printf("  Dificil   "); }
	else if (iDificult == 6) { printf("   Normal   "); }
	else if (iDificult == 9) { printf("   Facil    "); }
	textcolor(7); printf("|\n");
	printf("| 3 - Sair do Jogo        |              |\n");
	printf("*=========================*==============*\n");
	erro=0; // Inicializando Variavel de Erro...
	do
	{
		erro++; // Adiciona +1 ao valor da variavel erro.
		if(erro>1)
		{
			printf("| Erro: Opção invalida!\n");
			erro=1; // Adicino o valor 1 a variavel erro.
		}
		printf("| Informe á sua opção: ");
		scanf("%d",&opc); fflush(stdin);
		
	} while(opc>3 || opc<1); // definindo quantidade de opções, para não haver opções nulas.

	switch(opc)
	{
		case 1:
		{
			int campo[100], iVCampo[100], iVCont = 0, jogada, bomba = 101, iBC = 0;
			int cont, num, jogadas=0;
			char cv[100];

			cont = 0;
			num = 0;

			srand(time(NULL)); // isso faz com que as bombas possam cair em lugares diferentes toda vez que o jogo for iniciado.
			for (int i = 0 ; i <= 99 ; i++)
			{
				campo[i] = rand() % iDificult;
				cv[i] = '*';
				if (campo[i] == 0 ) { jogadas++; iBC++; }
				else { campo[i] = 1; }
				iVCampo[i] = 0;
			}

			monta_tela:
			system("cls");

			printf("*==============================================*\n");
			printf("| Jogo - Campo Minado "); textcolor(12); printf(" - Jadson Lima de Souza."); textcolor(7); printf(" |\n");
			printf("*----------------------------------------------*\n|\n");
            
	     	printf("|     0  1  2  3  4  5  6  7  8  9\n|\n"); 
			for (int j = 0 ; j < 99 ; j = j+10)
			{
				printf("| %.2d ",j);
				for (int i = j ; i < j+10 ; i++)
				{
					if (cv[i] != ' ') { textcolor(7); }
					else { textcolor(8); }
					printf("[");
					if (cv[i] == '*') { textcolor(8); }
					else if ((cv[i] == '#') && (bomba == i)) { textcolor(12); }
					else if (cv[i] == '#') { textcolor(4); }
					else { textcolor(6); }
					printf("%c",cv[i]);
					if (cv[i] != ' ') { textcolor(7); }
					else { textcolor(8); }
					printf("]");
					textcolor(7);
				}
				printf("\n");
			}

			printf("|\n");
			printf("| [ ] Vazio, ["); textcolor(12); printf("#"); textcolor(7); printf("] Bomba, ["); textcolor(6); printf("2"); textcolor(7); printf("] bombas proximas\n");
			printf("*==============================================*\n");
			printf("| Quantidade de Bombas no Campo %d\n",iBC);
			printf("| Quantidade de Jogadas Restantes %d\n",100-jogadas);
			printf("*==============================================*\n");
			if (jogadas >= 100) { goto winjogo; }
			if (cont == 0)
			{
				printf("| >> Escolha um Número de 0 a 99: ");
				scanf("%d",&jogada);
				iVCont = 1;
				iVCampo[jogada] = 1;

				if (campo[jogada] == 0)
				{
					bomba = jogada;
					for (int i = 0 ; i <= 99 ; i++)
					{
						if (campo[i] == 0) { cv[i] = '#'; }
					}
					cont = 1;
					goto monta_tela;
				}
				else
				{
				    while (iVCont > 0)
				    {
				        for (int i = 0 ; i <= 99 ; i++)
				        {
				            if (iVCampo[i] == 1)
				            {
                                jogada = i;
                                if (cv[jogada] == '*') { jogadas++; }
                                if ((campo[jogada-11] == 0) && (jogada-11 >= 0) &&
                                    (jogada != 10) && (jogada != 20) && (jogada != 30) && (jogada != 40) &&
                                    (jogada != 50) && (jogada != 60) && (jogada != 70) && (jogada != 80) && (jogada != 90))
                                {
                                    num = num +1;
                                }
                                if ((campo[jogada-10] == 0) && (jogada-10 >= 0)) { num = num +1; }
                                if ((campo[jogada- 9] == 0) && (jogada-9 >= 0) &&
                                    (jogada !=  9) && (jogada != 19) && (jogada != 29) && (jogada != 39) && (jogada != 49) &&
                                    (jogada != 59) && (jogada != 69) && (jogada != 79) && (jogada != 89) && (jogada != 99))
                                {
                                    num = num +1;
                                }
                                if ((campo[jogada-1] == 0) && (jogada-1 >= 0) &&
                                    (jogada != 10) && (jogada != 20) && (jogada != 30) && (jogada != 40) &&
                                    (jogada != 50) && (jogada != 60) && (jogada != 70) && (jogada != 80) && (jogada != 90))
                                {
                                    num = num +1;
                                }
                                if ((campo[jogada+1] == 0) && (jogada+1 < 100) &&
                                    (jogada !=  9) && (jogada != 19) && (jogada != 29) && (jogada != 39) && (jogada != 49) &&
                                    (jogada != 59) && (jogada != 69) && (jogada != 79) && (jogada != 89) && (jogada != 99))
                                {
                                    num = num +1;
                                }
                                if ((campo[jogada+9] == 0) && (jogada+9 < 100) &&
                                    (jogada !=  0) && (jogada != 10) && (jogada != 20) && (jogada != 30) && (jogada != 40) &&
                                    (jogada != 50) && (jogada != 60) && (jogada != 70) && (jogada != 80) && (jogada != 90))
                                {
                                    num = num +1;
                                }
                                if ((campo[jogada+10] == 0) && (jogada+10 < 100)) { num = num +1; }
                                if ((campo[jogada+11] == 0) && (jogada+11 < 100) &&
                                    (jogada !=  9) && (jogada != 19) && (jogada != 29) && (jogada != 39) && (jogada != 49) &&
                                    (jogada != 59) && (jogada != 69) && (jogada != 79) && (jogada != 89) && (jogada != 99))
                                {
                                    num = num +1;
                                }

                                if (num == 1) cv[jogada] = '1';
                                else if (num == 2) cv[jogada] = '2';
                                else if (num == 3) cv[jogada] = '3';
                                else if (num == 4) cv[jogada] = '4';
                                else if (num == 5) cv[jogada] = '5';
                                else if (num == 6) cv[jogada] = '6';
                                else if (num == 7) cv[jogada] = '7';
                                else if (num == 8) cv[jogada] = '8';
                                else {
                                    cv[jogada] = ' ';
                                    if (((jogada - 11) >=  0) && (iVCampo[jogada - 11] == 0 ) &&
                                        (jogada != 10) && (jogada != 20) && (jogada != 30) && (jogada != 40) &&
                                        (jogada != 50) && (jogada != 60) && (jogada != 70) && (jogada != 80) && (jogada != 90))
                                    { iVCampo[jogada - 11] = 1; iVCont++; }

                                    if (((jogada - 10) >=  0) && (iVCampo[jogada - 10] == 0 )) { iVCampo[jogada - 10] = 1; iVCont++; }

                                    if (((jogada -  9) >=  0) && (iVCampo[jogada -  9] == 0 ) &&
                                        (jogada !=  9) && (jogada != 19) && (jogada != 29) && (jogada != 39) && (jogada != 49) &&
                                        (jogada != 59) && (jogada != 69) && (jogada != 79) && (jogada != 89) && (jogada != 99))
                                    { iVCampo[jogada -  9] = 1; iVCont++; }

                                    if (((jogada -  1) >=  0) && (iVCampo[jogada -  1] == 0 ) &&
                                        (jogada != 10) && (jogada != 20) && (jogada != 30) && (jogada != 40) &&
                                        (jogada != 50) && (jogada != 60) && (jogada != 70) && (jogada != 80) && (jogada != 90))
                                    { iVCampo[jogada -  1] = 1; iVCont++; }

                                    if (((jogada +  1) <= 99) && (iVCampo[jogada +  1] == 0 ) &&
                                        (jogada !=  9) && (jogada != 19) && (jogada != 29) && (jogada != 39) && (jogada != 49) &&
                                        (jogada != 59) && (jogada != 69) && (jogada != 79) && (jogada != 89) && (jogada != 99))
                                    { iVCampo[jogada +  1] = 1; iVCont++; }

                                    if (((jogada +  9) <= 99) && (iVCampo[jogada +  9] == 0 ) &&
                                        (jogada !=  0) && (jogada != 10) && (jogada != 20) && (jogada != 30) && (jogada != 40) &&
                                        (jogada != 50) && (jogada != 60) && (jogada != 70) && (jogada != 80) && (jogada != 90))
                                    { iVCampo[jogada +  9] = 1; iVCont++; }

                                    if (((jogada + 10) <= 99) && (iVCampo[jogada + 10] == 0 )) { iVCampo[jogada + 10] = 1; iVCont++; }

                                    if (((jogada + 11) <= 99) && (iVCampo[jogada + 11] == 0 ) &&
                                        (jogada !=  9) && (jogada != 19) && (jogada != 29) && (jogada != 39) && (jogada != 49) &&
                                        (jogada != 59) && (jogada != 69) && (jogada != 79) && (jogada != 89) && (jogada != 99))
                                    { iVCampo[jogada + 11] = 1; iVCont++; }
                                }
                                iVCont--;
                                iVCampo[jogada] = 2;

                                cont = 0;
                                num = 0;

                                if (iVCont <= 0) { break; }
				            }
				        }
				    }

					for (int j = 0 ; j <= 99 ; j++) {
					    iVCampo[j] = 0;
					}
					iVCont = 0;
					goto monta_tela;
					
				}
			}
			printf("|\n");
			printf("| "); textcolor(12); printf(">> BOOMM <<"); textcolor(7); printf(" VOCÊ PERDEU ! ! !\n\n");
			system("pause");

			goto inicio;

			winjogo:

			printf("|\n");
			printf("| "); textcolor(10); printf(">> WINNER <<"); textcolor(7); printf(" VOCÊ GANHOU ! ! !\n\n");
			system("pause");
			goto inicio;
		}

		case 2:
        {
			system("cls");

			printf("*===============================================*\n");
			printf("|  Jogo - Campo Minado "); textcolor(12); printf(" - Jadson Lima de Souza."); textcolor(7); printf(" |\n");
			printf("*-----------------------------------------------*\n");
            printf("|                  OPCÕES                       |\n");
            printf("*-----------------------------------------------*\n");
            printf("| 1 - Dificil                                   |\n");                                    
            printf("| 2 - Normal                                    |\n");
            printf("| 3 - Fácil                                     |\n");
            printf("*-----------------------------------------------*\n");

           	erro=0; // Inicializando Variavel de Erro...

            do
            {
                erro++; // Adiciona +1 ao valor da variavel erro.
                if(erro>1)
                {
                    printf("| Erro: Opção invalida!\n");
                    erro=1; // Adicino o valor 1 a variavel erro.
                }
                printf("| Escolha o Nivel de Dificuldade: ");
                scanf("%d",&opc); fflush(stdin);
                printf("*========================================*");
            } while(opc>3 || opc<1); // definindo quantidade de opções, para não haver opções nulas.

            switch(opc)
            {
                case 1: iDificult = 3; goto inicio;
                case 2: iDificult = 6; goto inicio;
                case 3: iDificult = 9; goto inicio;
            }
        }
		case 3:
			 
 		    printf("\n");
		{	printf("*========================================*\n");
			printf("|             Jogo Encerrado             |\n");
	        printf("*========================================*\n");
		}
	}
}
