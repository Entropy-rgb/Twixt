#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

int traverse(char matrix[22][22] , int visited_matrix[22][22], char player, int x , int y){
    // TODO
    // ! DFS v/s BFS
    
}

int red_has_path(char matrix[22][22], int visited_matrix_red[22][22]){
    char player = 'R';
    for(int i = 0 ; i < 22 ; i++){
        if(matrix[0][i]==player){
            if(traverse(matrix, visited_matrix_red, player, 0, i)==1){
                return 1;
            }
        }
    }
    return 0;
}

int black_has_path(char matrix[22][22], int visited_matrix_black[22][22]){
    char player = 'B';
    for(int i = 0 ; i < 22 ; i++){
        if(matrix[i][0]==player){
            if(traverse(matrix, visited_matrix_black, player, i, 0)==1){
                return 1;
            }
        }
    }
    return 0;
}

int win(char matrix[22][22])
{
    int visited_matrix_black[22][22] = {};
    int visited_matrix_red[22][22] = {};
    if(red_has_path(matrix,visited_matrix_red)) return 1;
    if(black_has_path(matrix,visited_matrix_black)) return 2;
    return 0;
}