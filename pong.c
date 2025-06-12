#include <stdio.h>

#include "functions.h"
#include "move.h"

void paint_pole(int rocket_1_Y, int rocket_2_Y, int ball_X, int ball_Y, int score_Player_1, 
                int score_Player_2, const int WIDTH, const int HEIGHT, int rocket_1_X, int rocket_2_X);  // Вывод поля в терминал
int check_simbol(char simbol); // проверка

int main() {
    const int WIDTH = 80;   // Ширина поля
    const int HEIGHT = 25;  // длина поля

    int BALL_START_X = WIDTH / 2;   // центр поля
    int BALL_START_Y = HEIGHT / 2;  //

    int rocket_1_X = 2;          // координата х 1 ракетки
    int rocket_2_X = WIDTH - 3;  // координата х 2 ракетки

    int rocket_1_Y = 19;  // координаты ракеток по у
    int rocket_2_Y = 5;

    int ball_X = BALL_START_X;  // координаты мяча начальные
    int ball_Y = BALL_START_Y;

    int vector_X = -1;  // шаги с которыми изменяются координаты мяча
    int vector_Y = 1;

    int score_Player_1 = 0;  // счет первого игрока
    int score_Player_2 = 0;  // второго игрока

    const int WIN = 21;  // очки для победы
    int winner = 0;      // победитель

    while (!winner) {
        paint_pole(rocket_1_Y, rocket_2_Y, ball_X, ball_Y, score_Player_1,  // отрисовка поля
                   score_Player_2, WIDTH, HEIGHT, rocket_1_X, rocket_2_X);  //
        char simbol = getchar();                                            // вводим символ
        if (check_simbol(simbol)) {                                         // проверка символа
            rocket_1_Y = moveRocket_1(rocket_1_Y, HEIGHT, simbol);  // изменение координаты ракетки 1
            rocket_2_Y = moveRocket_2(rocket_2_Y, HEIGHT, simbol);  // тоже самое для 2 ракетки
            vector_X = Vector_X(ball_X, ball_Y, vector_X, rocket_1_Y, rocket_2_Y, rocket_1_X,
                                rocket_2_X);        // изменение шага по х
            ball_X = moveball_X(ball_X, vector_X);  // изменение координаты по х мяча
            vector_Y = Vector_Y(ball_Y, vector_Y, HEIGHT);  // по у
            ball_Y = moveball_Y(ball_Y, vector_Y);          // по у
        }
        clearScreen();                        // очистка экрана
        int score_before_1 = score_Player_1;  // очки до их обновления
        int score_before_2 = score_Player_2;  //
        score_Player_1 = checkTablo_1(score_Player_1, ball_X, WIDTH);  // очки после изменения
        score_Player_2 = checkTablo_2(score_Player_2, ball_X);         //
        if (score_before_1 != score_Player_1 ||
            score_before_2 != score_Player_2) {  // если они не равны, то мячик дошел до края
            ball_X = BALL_START_X;  // в центр мяч
            ball_Y = BALL_START_Y;  //
        }
        // победитель
        if (score_Player_1 == WIN) {
            winner = 1;
        } else if (score_Player_2 == WIN) {
            winner = 2;
        }
    }
    printf("Победил игрок №%d", winner);
    return 0;
}

void paint_pole(int rocket_1_Y, int rocket_2_Y, int ball_X, int ball_Y, int score_Player_1,
                int score_Player_2, const int WIDTH, const int HEIGHT, int rocket_1_X, int rocket_2_X) {
    // отрисовка экрана сверху где счет кароче
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((y == 0 && x != 0 && x != WIDTH - 1) || (y == 3 - 1 && x != 0 && x != WIDTH - 1)) {
                printf("-");
            } else if (((x == 0 && y != 0 && y != 3 - 1) || (x == WIDTH - 1 && y != 0 && y != 3 - 1))) {
                printf("|");
            } else if (x == 5) {
                printf("Press \'Control + c\' to exit");
            } else if (x == 19) {
                printf("Player one: %d | Player two: %d", score_Player_1, score_Player_2);
            } else if (y == 1 && x < WIDTH - 55) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // отрисовка самого игрового поляя
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((x == rocket_1_X && (y == rocket_1_Y - 1 || y == rocket_1_Y || y == rocket_1_Y + 1)) ||
                (x == rocket_2_X && (y == rocket_2_Y - 1 || y == rocket_2_Y || y == rocket_2_Y + 1))) {
                printf("|");
            } else if (x == ball_X && y == ball_Y) {
                printf("o");
            } else if ((y == 0 && x != 0 && x != WIDTH - 1) ||
                       (y == HEIGHT - 1 && x != 0 && x != WIDTH - 1)) {
                printf("-");
            } else if ((x == 0 && y != 0 && y != HEIGHT - 1) ||
                       (x == WIDTH - 1 && y != 0 && y != WIDTH - 1) || (x == WIDTH / 2)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int check_simbol(char simbol) {  // проверка символа
    int flag = 0;
    if (simbol == 'a' || simbol == 'A' || simbol == 'z' || simbol == 'Z' || simbol == 'k' || simbol == 'K' ||
        simbol == 'm' || simbol == 'M' || simbol == ' ') {
        flag = 1;
    }
    return flag;
}