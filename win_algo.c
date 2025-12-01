#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

int red_has_path(char matrix[22][22], int visited_matrix_red[22][22]){
    // TODO: complete this.
}

int black_has_path(char matrix[22][22], int visited_matrix_black[22][22]){
    // TODO: complete this.
}

int win(char matrix[22][22])
{
    int visited_matrix_black[22][22] = {};
    int visited_matrix_red[22][22] = {};
    if(red_has_path(matrix,visited_matrix_red)) return 1;
    if(black_has_path(matrix,visited_matrix_black)) return 2;
    return 0;
}