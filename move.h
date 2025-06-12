#ifndef MOVE

#define MODE

int moveRocket_1(int rocket_1_Y, const int HEIGHT, char simbol);
int moveRocket_2(int rocket_2_Y, const int HEIGHT, char simbol);
int Vector_X(int ball_X, int ball_Y, int vector_X, int rocket_1_Y, int rocket_2_Y, int rocket_1_X, int rocket_2_X);
int Vector_Y(int ball_Y, int vector_Y, const int HEIGHT);

#endif