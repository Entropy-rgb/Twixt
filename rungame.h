#ifndef RUNGAME_H
#define RUNGAME_H

void rungame(char matrix[22][22], char player1[50], char player2[50]);
int move_validity(char matrix[22][22], int x, int y , int player);

#endif