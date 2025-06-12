#include "functions.h"
#include <stdio.h>

int moveball_X(int ball_X, int vector_X) {
    ball_X += vector_X;
    return ball_X;
}

int moveball_Y(int ball_Y, int vector_Y) {
    ball_Y += vector_Y;
    return ball_Y;
}

int checkTablo_1(int score_Player_1, int ball_X, const int WIDTH) {
    if (ball_X > WIDTH - 3) {  // если мяч у правого края, то игроку №1 начисляют очко
        score_Player_1 += 1;
    }
    return score_Player_1;
}

int checkTablo_2(int score_Player_2, int ball_X) {
    if (ball_X < 2) {  // если мяч у левого края, то игроку №2 начисляют очко
        score_Player_2 += 1;
    }
    return score_Player_2;
}

void clearScreen(void) { printf("\33[0d\33[2J"); }
