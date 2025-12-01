#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "main.h"
#include <stdlib.h>
#include "board.h"
#include "linking.h"
#include "rungame.h"
#include "win_algo.h"

int check_intersection(link l, char matrix[22][22])
{
    int cl = 0;
    // int count = 0;
    while(cl < link_count){
        float m1  = ((float)links[cl].a.y - (float)links[cl].b.y)/((float)links[cl].a.x - (float)links[cl].b.x);
        float c1 = (float)links[cl].a.y - (m1*((float)links[cl].a.x));
        float m2  = ((float)l.a.y - (float)l.b.y)/((float)l.a.x - (float)l.b.x);
        float c2 = (float)l.a.y - (m1*((float)l.a.x));
        float val1 = (((float)l.a.y) - (m1 * ((float)l.a.x)) - c1)*(((float)l.b.y) - (m1 * ((float)l.b.x)) - c1);
        float val2 = (((float)links[cl].a.y) - (m2 * ((float)links[cl].a.x)) - c2)*(((float)links[cl].b.y) - (m2 * ((float)links[cl].b.x)) - c2);
        if(val1 > 0 || val2 > 0){
            cl++;
            // count++;
        }else{
            return 1;
        }
    }
    return 0;
}

int make_link_if_Possible(char matrix[22][22],int x, int y, int player )
{
    char color = (player == 1 ? 'R' : 'B');
    for(int k = 0 ; k < 8 ; k++){
        int nx = x + knight_moves[k][0];
        int ny = y + knight_moves[k][1];
        if(nx < 1 || ny < 1|| nx > 22 || ny > 22) continue;
        if(matrix[nx - 1][ny - 1]==color){
            link newlink = {{x,y},{nx,ny}};
            if(check_intersection(newlink, matrix)==0){
                links[link_count++] = newlink;
            }
        }
    }
    return 0;
}
