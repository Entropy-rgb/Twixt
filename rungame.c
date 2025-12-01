#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

int move_validity(char matrix[n][n], int x, int y , int player){
    if(x == 0 && y == 0){
        return 0;
    }
    if(x == 0 && y == n-1){
        return 0;
    }
    if(x == n-1 && y == 0){
        return 0;
    }
    if(x == n-1 && y == n-1){
        return 0;
    }
    if(player==1 && (y==0 || y==n-1)){
        return 0;
    }
    if(player==2 && (x == 0 || x == n-1)){
        return 0;
    }
    if(x>=0 && y>=0 && x<n && y <n && matrix[x][y]=='.'){
        return 1;
    }
    return 0;
}

void rungame(char matrix[n][n], char player1[50], char player2[50])
{
    while (win(matrix) == 0)
    {   int r_x, r_y, b_x, b_y;
        int prev_move_validity = 1;
        do{
            printboard(matrix);
            if(prev_move_validity == 0){
               printf("%sThe move you are trying to play is invalid, please try again.%s\n",RED,RESET) ;
            }
            printf("%sIts RED(R)'s turn, please input the coordinates you would like to mark ur pin on: %s",YELLOW,WHITE);
            scanf("%d %d",&r_x,&r_y);
            r_x--;
            r_y--;
            prev_move_validity = move_validity(matrix,r_x, r_y ,1);
        } while (prev_move_validity == 0);
        matrix[r_x][r_y] = 'R';
        make_link_if_Possible(matrix,r_x,r_y,1);
        if(win(matrix)!=0){
            break;
        }
        prev_move_validity = 1;
        do
        {
            printboard(matrix);
            if(prev_move_validity == 0){
           printf("%sThe move you are trying to play is invalid, please try again.%s\n",RED,RESET) ;
         }
            printf("%sIts BLACK(B)'s turn, please input the coordinates you would like to mark ur pin on: %s",YELLOW,WHITE);
            scanf("%d %d",&b_x,&b_y);
            printf("%s",RESET);
            b_x--;
            b_y--;
            prev_move_validity = move_validity(matrix,b_x, b_y ,2);
        } while (move_validity(matrix,b_x, b_y ,2) == 0);
        matrix[b_x][b_y] = 'B';
        make_link_if_Possible(matrix,b_x,b_y,2);
    }
    if (win(matrix) == 1)
    {
        printf("%sCongratulations, Player %s won with %s side\n%s",CYAN, player1, "RED(R)",WHITE);
    }
    else if (win(matrix) == 2)
    {
        printf("%sCongratulations, Player %s won with %s side\n%s",CYAN, player2, "BLACK(B)",WHITE);
    }
}
