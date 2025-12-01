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

link links[10000];
int link_count = 0;

int main()
{
    while (1)
    {
        link_count = 0;
        char game;
        char matrix[22][22];
        initialize_matrix(matrix);
        char player1[50];
        char player2[50];
        printf("=============================================================\n"
               "                  Welcome To Twixtplay\n"
               "=============================================================\n");
        printf("To quit the Game at any point of time just press Ctrl + C\n");
        printf("Please enter the Red(R) Player's name: ");
        scanf("%s", player1);
        printf("Please enter the Black(B) Player's name: ");
        scanf("%s", player2);
        rungame(matrix, player1, player2);
        printf("===================Thanks for Playing========================\n");
        printf("To Play The Game Again press 'r', else to quit Press 'q'\n");
        scanf("%c", game);
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
            printf("You have entered an Invalid Input, this made the programmer Angry\nBye\n");
            break;
        }
    }
    return 0;
}
