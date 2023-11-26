#include <stdio.h>
#include <stdlib.h>
int main()
{
    //jogo da velha com menu by Gustavo M
    int i, j, sair, jogador = 1, ganhou = 0, jogadas = 0, op, jogador1 = 0, jogador2 = 0, partidas = 0,empate=0;
    char jogo[3][3];

    do{
        printf("\n-----MENU-----");
        printf("\n1 - JOGAR.");
        printf("\n2 - PONTU�AO.");
        printf("\n3 - TUTORIAL.");
        printf("\n4 - SAIR.");
        printf("\n--------------");
        printf("\n");
        printf("Digite uma das opcoes para prosseguir\n");
        scanf("%d", &op);
        // op�ao 1 - Jogar
        if (op == 1){
            system("cls");
            printf("\n\t-----JOGO DA VELHA-----\n");
            printf("\n");
            for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                      jogo[i][j] = ' ';
                }
            }
            do{
            // Imprime o tabuleiro
                printf("\n           0       1       2\n");
                printf("\n");
                for (i = 0; i < 3; i++){
                    printf("%d", i);
                    for (j = 0; j < 3; j++){
                        printf("\t   %c",jogo[i][j]);
                        if (j < 2){
                            printf(" |");
                        }
                    }
                    printf("\n");
                if (i < 2){
                  printf("\t---------------------\n");
                }
                }
                do{
                     printf("\nJogador %d,primeiro digite a linha e depois a coluna que deseja jogar: ", jogador);
                      scanf("%d%d",&i,&j);

                }while (i < 0 || i > 2 || j < 0 || j > 2 || jogo[i][j] != ' ');

                if (jogador == 1){
                    jogo[i][j] = 'X';
                    jogador++;
                }
                else{
                    jogo[i][j] = 'O';
                    jogador = 1;
                }
                jogadas++;
                // Ganhou por linha
                if ((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') ||
                    (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') ||
                    (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X')){
                    printf("Parabens, Jogador 1 venceu!\n");
                    jogador1++;
                    ganhou = 1;
                }
                if ((jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O') ||
                    (jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') ||
                    (jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O')){
                    printf("Parabens, Jogador 2 venceu!\n");
                    jogador2++;
                    ganhou = 1;
                }
                // Ganhou por coluna
                if ((jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') ||
                    (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') ||
                    (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X')){
                    printf("Parabens, Jogador 1 venceu!\n");
                    jogador1++;
                    ganhou = 1;
                }
                if ((jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') ||
                    (jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') ||
                    (jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O')){
                    printf("Parabens, Jogador 2 venceu!\n");
                    jogador2++;
                    ganhou = 1;
                }
                // Ganhou na diagonal
                if ((jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') ||
                    (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')){
                    printf("Parabens, Jogador 1 venceu!\n");
                    jogador1++;
                    ganhou = 1;
                }
                if ((jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') ||
                    (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O')){
                    printf("Parabens, Jogador 2 venceu!\n");
                    jogador2++;
                    ganhou = 1;
                }
                if (ganhou == 1){
                    partidas++;
                }
                // Sair pos partida
            }while (ganhou == 0 && jogadas < 9);
            if (ganhou == 0 && jogadas < 9){
                  printf ("\nEmpate o jogo acabou sem vencedor");
                  empate++;
            }
        }
        // PontuaÇao
         if (op == 2){
            system("cls");
            printf("\nPONTUACAO\n");
            printf("\nPartidadas jogadas: %d", partidas);
            printf("\nVitorias do jogador 1: %d", jogador1);
            printf("\nVitorias do jogador 2: %d", jogador2);
            printf ("\nEmpates: %d", empate);
            printf("\n\n");
            system("pause");
        }//fim pontuaçao
        // Tutorial
        else if (op == 3){
            system("cls");
            printf("\n--TUTORIAL--\n");
            printf("\nGUIA DE COMO JOGAR");
            printf("\n1'Na aba 'MENU'aperte o numero 1.");
            printf("\n2'O Jogador 1 comeca , com o  'x'.");
            printf("\n3'Primeiro o jogador informa sua linha (horizontal) e depois sua colula(vertical).");
            printf("\n4'Ganha quem completar uma diagonal ou uma linha ou uma coluna.");
            printf("\n\n");
            system("pause");
        }//fim tutorial
        // Sair
        else if (op == 4)
        {
            system("cls");
            printf("Deseja realmente sair? Digite 1 (SIM) / 2 (NAO): ");
            scanf("%d", &sair);
            if (sair == 1)
            {
                break;
            }
            else if (sair == 2)
            {
                printf("Voltando ao menu...\n");
                system("pause");
            }
        }//fim sair 
    } while ('true');
    return 0;
}
