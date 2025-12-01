#ifndef MAIN_H
#define MAIN_H

#define n 24

typedef struct{
    int x;
    int y;
}peg;

typedef struct{
    peg a;
    peg b;
}link;

extern link links[10000];
extern int link_count;
extern int knight_moves[8][2];
extern char* YELLOW;
extern char* RESET;
extern char* RED ;
extern char* GREEN;
extern char* WHITE;
extern char* PINK;
extern char* BLUE;
extern char* CYAN;

#endif