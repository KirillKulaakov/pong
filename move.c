#include "move.h"

int moveRocket_1(int rocket_1_Y, const int HEIGHT, char simbol) {  // движение ракетки
    if (simbol == 'a' || simbol == 'A') {
        if ((rocket_1_Y - 2) != 0) {
            rocket_1_Y -= 1;
        }
    }
    if (simbol == 'z' || simbol == 'Z') {
        if ((rocket_1_Y + 2) != HEIGHT - 1) {
            rocket_1_Y += 1;
        }
    }
    return rocket_1_Y;
}

int moveRocket_2(int rocket_2_Y, const int HEIGHT, char simbol) {  // движение ракетки
    if (simbol == 'k' || simbol == 'K') {
        if ((rocket_2_Y - 2) != 0) {
            rocket_2_Y -= 1;
        }
    }
    if (simbol == 'm' || simbol == 'M') {
        if ((rocket_2_Y + 2) != HEIGHT - 1) {
            rocket_2_Y += 1;
        }
    }
    return rocket_2_Y;
}

int Vector_X(int ball_X, int ball_Y, int vector_X, int rocket_1_Y, int rocket_2_Y, int rocket_1_X, int rocket_2_X) {
    // если мяч задевает ракетку 1, то он в другую сторону
    if (ball_X == rocket_1_X + 1 &&
        (ball_Y == rocket_1_Y - 1 || ball_Y == rocket_1_Y || ball_Y == rocket_1_Y + 1)) {
        vector_X = -(vector_X);
    }
    // также для 2 ракетки
    if (ball_X == rocket_2_X - 1 &&
        (ball_Y == rocket_2_Y - 1 || ball_Y == rocket_2_Y || ball_Y == rocket_2_Y + 1)) {
        vector_X = -(vector_X);
    }
    return vector_X;
}

int Vector_Y(int ball_Y, int vector_Y, const int HEIGHT) {
    // если мяч задевает стену, то он в другую сторону
    if (ball_Y == 1 || ball_Y == HEIGHT - 2) {
        vector_Y = -(vector_Y);
    }
    return vector_Y;
}
