#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <io.h>

#define clrscr() system("cls")
#define sleep(int) _sleep(int)

void gotoxy(int x, int y) 
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int pontos = 0;
int vidas = 5;
int level = 1;

void menu();

void carro( int x, int y)
{
     gotoxy( x, y ); printf( "  \xDC " );
     gotoxy( x, y + 1 ); printf( "/| |\\" );
     gotoxy( x, y + 2 ); printf( "0 \xBA 0" );
     gotoxy( x, y + 3 ); printf( " /\xCD\\" );
     gotoxy( x, y + 4 ); printf( "0   0" );
}

void pista()
{
     int x = 0;
          for( int b = 3; b < 24; b++ )
          {
               gotoxy( 10, b ); printf( " |^|" );
               gotoxy( 27, b ); printf( "|^|" );
               gotoxy( 20, b ); printf( "|" );
          }
}

void limpacarro( int x, int y )
{
     gotoxy( x, y - 1 ); printf( "    " );
     gotoxy( x, y ); printf( "     " );
     gotoxy( x, y + 1 ); printf( "     " );
     gotoxy( x, y + 2 ); printf( "     " );
     gotoxy( x, y + 3 ); printf( "     " );
     gotoxy( x, y + 4 ); printf( "     " );
}

void status( int pontos, int vidas, int level )
{
     gotoxy( 40, 5 ); printf( "Pontos: %d ", pontos );
     gotoxy( 40, 6 ); printf( "Vidas Restantes: %1d", vidas );
     gotoxy( 40, 7 ); printf( "Nivel: %d", level );
}

void perdeu()
{
     clrscr();
     pista();
     gotoxy( 30, 12 ); printf( "Voce Perdeu!!!" );
     gotoxy( 30, 13 ); printf( "Voce fez %d pontos no nivel %d", pontos, level );
     gotoxy( 30, 14 ); printf( "Pressione qualquer tecla para voltar ao menu" );
     sleep( 300 );
     getch();
     menu();
}


void bateu()
{
     char ch;
     if( vidas == 0 ) perdeu();
     clrscr();
     pista();
     gotoxy( 35, 10 ); printf( "Voce Bateu!" );
     gotoxy( 35, 12 ); printf( "Perdeu uma vida, %d vidas restantes", vidas );
     gotoxy( 35, 13 ); printf( "Toma cuidado ai cara!!!" );
     gotoxy( 35, 15 ); printf( "Pressione <ENTER> para continuar." );
     gotoxy( 35, 16 ); printf( "Pressione <ESQ> para sair." );
     ch = getch();
     clrscr();
     pista();
     switch( ch )
     {
             case 13: break;
             case 27: exit( true );
             default: bateu();
     }
}

void fim()
{
     clrscr();
     pista();
     carro( 15, 18 );
     level--;
     status( pontos, vidas, level );
     gotoxy( 40, 12 ); printf( "Parabens!!!" );
     gotoxy( 40, 15 ); printf( "Voce Conseguiu Finalizar o Game" );
     gotoxy( 40, 16 ); printf( "Agora va fazer algo de util =D" );
     gotoxy( 40, 18 ); printf( "Jadson Lima de Souza" );
     sleep( 1000 );
     getch();
     exit( true );
}

void inicio()
{
      char tecla;
      int x1 = 15, x2, y1 = 18, y2 = 5;
      int cont = 0;
      int velocidade = 500;
      
      clrscr();
      pista();
      carro( x1, y1 );
      while( tecla != 27 )
      {
             if( pontos == 10 && level < 8 )
             {
                 pontos = 0;
                 level++;
             }
             if( pontos == 20 && level >= 8 ) 
             {
                 pontos = 0;
                 level++;
             }
             if( level == 1 ) velocidade = 300;
             if( level == 2 ) velocidade = 250;
             if( level == 3 ) velocidade = 200;
             if( level == 4 ) velocidade = 170;
             if( level == 5 ) velocidade = 150;
             if( level == 6 ) velocidade = 130;
             if( level == 7 ) velocidade = 100;
             if( level == 8 ) velocidade = 90;
             if( level == 9 ) velocidade = 70;
             if( level == 10 ) velocidade = 50;
             if( level == 11 ) velocidade = 20;
             if( cont == 0 )
             {
                 x2 = rand() %2;
                 cont = 1;
             }
             
             if( x2 == 1 )
             {
                  x2 = 15;
             }
             if( x2 == 0 )
             {
                  x2 = 21;
             }
             limpacarro( x2, y2 );
             carro( x2, y2 );
             y2++;
             if( kbhit()) tecla = getch();
             switch( tecla )
             {
                     case 'd': if( x1 == 15 )
                               {
                                   limpacarro( x1, y1 );
                                   x1 = 21;
                                   carro( x1, y1 );
                               }
                               break;
                     case 'a': if( x1 == 21 )
                               {
                                   limpacarro( x1, y1 );
                                   x1 = 15;
                                   carro( x1, y1 );
                               }
                               break;
                     case 27: exit( true );
             }
             sleep( velocidade );
             if( y2 == 20 )
             {
                 limpacarro( x2, y2 );
                 y2 = 2;
                 cont = 0;
                 pontos += 1;
             }
             if( y2 == y1 && x2 == x1 )
             {
                 vidas-=1;
                 bateu();
                 y2 = 3;
             }
             for( int c = 0; c < 5; c++ )
             {
                 if( y2+c == y1 && x2 == x1 )
                 {
                     vidas-=1;
                     bateu();
                     y2 = 3;
                     
                 }
                 carro( x1, y1 );
             }
             status( pontos, vidas, level );
             if( level == 12 ) fim();
      }   
}

void instrucoes()
{
     clrscr();
     gotoxy( 15, 8 ); printf( "Instrucoes" );
     gotoxy( 10, 10 ); printf( "Utilize as teclas ( a ) / ( d ) para ir para a esquerda ou direita" );
     gotoxy( 10, 11 ); printf( "Sao 11 niveis no total, para finalizar o jogo basta vencer o nivel 11" );
     gotoxy( 10, 12 ); printf( "Voce deve desviar de todos os carros que encontrar na pista" );
     gotoxy( 10, 14 ); printf( "Pressione qualquer tecla para voltar ao menu" );
     getch();
     menu();
}

void menu()
{
     clrscr();
     
     char ch;
     system("color A");
     gotoxy( 15, 10 ); printf( "CRAZY CARS" );
     gotoxy( 13, 15 ); printf( "( 1 ) Iniciar" );
     gotoxy( 13, 16 ); printf( "( 2 ) Instrucoes" );
     gotoxy( 13, 17 ); printf( "( 3 ) Sair" );
     gotoxy( 16, 19 ); printf( "Jadson Lima de Souza" );
     ch = getch();
     switch( ch )
     {
             case '1': inicio(); break;
             case '2': instrucoes(); break;
             case '3': exit( true );
             case 27: exit( true );
             default: menu();
     }
}

main()
{
      clrscr();
      menu();
      inicio();
      return 0;     
}


