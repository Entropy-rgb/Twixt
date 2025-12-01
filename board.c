#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

void initialize_matrix(char matrix[22][22])
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            matrix[i][j] = '.';
        }
    }
}

void printboard(char matrix[22][22])
{
    printf("   ");
    for (int i = 0; i < 22; i++)
    {
        if (i + 1 > 9)
            printf("%d ", i + 1);
        else
            printf("%d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < 22; i++)
    {
        if (i + 1 > 9)
            printf("%d ", i + 1);
        else
            printf("%d  ", i + 1);

        for (int j = 0; j < 22; j++)
        {
            printf("%c  ", matrix[i][j]);
        }
        printf("\n");
    }
}