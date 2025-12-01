#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

int traverse_red(char matrix[22][22] , int visited_matrix[22][22], int x , int y){
    visited_matrix[x][y] = 1;
    // int ans = 0;
    if(x == 21){
        return 1;
    }
    for(int i = 0 ; i < 8 ; i++){
        int nx = x + knight_moves[i][0];
        int ny = y + knight_moves[i][1];
        if(nx >= 0 && ny >= 0 && nx < 22 && ny < 22 && visited_matrix[nx][ny] == 0 && matrix[nx][ny] == 'R'){
            int has_link = 0;
            for(int j = 0 ; j < link_count ; j++){
                if(((x==links[j].a.x && y == links[j].a.y && nx == links[j].b.x && ny==links[j].b.y) || (x == links[j].b.x && y == links[j].b.y && nx == links[j].a.x && ny == links[j].a.y))){
                    has_link = 1;
                    // printf("\n\nLINK COORDS x = %d , y = %d\n\n",nx,ny);
                    break;
                }
            }
            if(has_link){
                if(traverse_red(matrix,visited_matrix,nx,ny)){
                    return 1;
                }
            }
        }
    }
    return 0;
    }


int traverse_black(char matrix[22][22] , int visited_matrix[22][22], int x , int y){
    visited_matrix[x][y] = 1;
    // int ans = 0;
    if(y == 21){
        return 1;
    }
    else
    {
        for(int i = 0 ; i < 8 ; i++){
            int nx = x + knight_moves[i][0];
            int ny = y + knight_moves[i][1];
            if(nx >= 0 && ny >= 0 && nx < 22 && ny < 22 && visited_matrix[nx][ny] == 0 && matrix[nx][ny]=='B'){
                int has_link = 0;
                for(int j = 0 ; j < link_count ; j++){
                    if(((x==links[j].a.x && y == links[j].a.y && nx == links[j].b.x && ny == links[j].b.y) || (x == links[j].b.x && y == links[j].b.y && nx == links[j].a.x && ny == links[j].a.y))){
                        has_link = 1;
                        break;
                    }
                    if(has_link){
                        if(traverse_black(matrix,visited_matrix,nx,ny)){
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
}

int red_has_path(char matrix[22][22], int visited_matrix_red[22][22]){
    char player = 'R';
    for(int i = 0 ; i < 22 ; i++){
        if(matrix[0][i]==player){
            visited_matrix_red[0][i] = 1;
            if(traverse_red(matrix, visited_matrix_red, 0, i)!=0){
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
            visited_matrix_black[i][0] = 1;
            if(traverse_black(matrix, visited_matrix_black, i, 0)!=0){
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