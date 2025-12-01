#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

void initialize_matrix(char matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = '.';
        }
    }
}

void printboard(char matrix[n][n])
{
    printf("\033[2J\033[H");
    printf("%s",WHITE);
    printf("   ");
    for (int i = 0; i < n; i++)
    {
        printf("%02d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        
        printf("%02d  ", i + 1);

        for (int j = 0; j < n; j++)
        {
            // printf("%c   ", matrix[i][j]);
            int has_link = 0;
            for(int k = 0 ; k < link_count ; k++){
                if(((i==links[k].a.x && j == links[k].a.y) || (i == links[k].b.x && j == links[k].b.y))){
                    has_link = 1;
                    break;
                }
            }
            if(has_link == 1){
                if(matrix[i][j]=='R'){
                    printf("%s%c%s   ",RED, matrix[i][j],WHITE);
                }else if(matrix[i][j] == 'B'){
                    printf("%s%c%s   ",CYAN, matrix[i][j],WHITE);
                }
            }else{
                printf("%c   ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("%s",RESET);
}