#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

int knight_moves[8][2] = {
    {1,2}, {2,1}, {2,-1}, {1,-2},
    {-1,-2}, {-2,-1}, {-2,1}, {-1,2}
};
char* YELLOW="\033[1;33m";
char* RESET="\033[0m";
char* RED = "\033[1;31m";
char* GREEN = "\033[1;32m";
char* WHITE = "\033[1;37m";
char* PINK = "\033[1;35m";
char *BLUE = "\033[1;34m";
char *CYAN = "\033[1;36m";

link links[10000];
int link_count = 0;

int main()
{
    while (1)
    {
        link_count = 0;
        char game;
        char matrix[n][n];
        initialize_matrix(matrix);
        char player1[50];
        char player2[50];
        printf("%s=============================================================\n"
               "                  %sWelcome To Twixtplay\n"
               "%s=============================================================\n",YELLOW,GREEN,YELLOW);
        printf("%sTo quit the Game at any point of time just press Ctrl + C\n",RED);
        printf("%sPlease enter the Red(R) Player's name: %s",YELLOW,WHITE);
        fgets(player1, 50, stdin);
        int length = strlen(player1);
        player1[length-1] = '\0';
        printf("%sPlease enter the Black(B) Player's name: %s",YELLOW,WHITE);
        fgets(player2, 50 , stdin);
        length = strlen(player2);
        player2[length-1] = '\0';
        printf("%s",RESET);
        rungame(matrix, player1, player2);
        printf("%s===================Thanks for Playing========================\n%s",YELLOW,RESET);
        printf("%sTo Play The Game Again press 'r', else to quit Press 'q'%s\n",RED,RESET);
        scanf("\n%c", &game);
        if (game == 'r')
        {
            continue;
        }
        else if (game == 'q')
        {
            break;
        }
        else
        {
            printf("%sYou have entered an Invalid Input, this made the programmer Angry\nBye\n%s",RED, RESET);
            break;
        }
    }
    return 0;
}
