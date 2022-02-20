#include <iostream>
#include <lib/gorizontal.h>
#include <lib/playermove.h>
#include <lib/vertical.h>
#include <stdlib.h>
#include <string>
using namespace std;
string buff;
int CHESS_BOOL[9][9];

void move_FIGURES(std::string chess[9][9])
{
    struct figures {
        std::string Nb, Rw, Rb, Pw, Pb, Kw, Kb, Qw, Qb, Bw, Bb, Nw;
        figures()
            : Nb{"♘"},
              Rw{"♜"},
              Rb{"♖"},
              Pw{"♟"},
              Pb{"♙"},
              Kw{"♚"},
              Kb{"♔"},
              Qw{"♛"},
              Qb{"♕"},
              Bw{"♝"},
              Bb{"♗"},
              Nw{"♞"}
        {
        }
    };
    struct figures f;
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 9; j++) {
            chess[i][j] = "|_|";
            CHESS_BOOL[i][j] = 0;
        }
    }
    for (int i = 1; i < 9; i++) {
        chess[1][i] = "|" + f.Pb + "|";
        CHESS_BOOL[1][i] = 1;
        chess[6][i] = "|" + f.Pw + "|";
        CHESS_BOOL[6][i] = 1;
    }
    chess[0][1] = chess[0][8] = "|" + f.Rb + "|";
    CHESS_BOOL[0][1] = CHESS_BOOL[0][8] = 1;
    chess[7][1] = chess[7][8] = "|" + f.Rw + "|";
    CHESS_BOOL[7][1] = CHESS_BOOL[7][8] = 1;
    chess[0][2] = chess[0][7] = "|" + f.Nb + "|";
    CHESS_BOOL[0][2] = CHESS_BOOL[0][7] = 1;
    chess[7][2] = chess[7][7] = "|" + f.Nw + "|";
    CHESS_BOOL[7][2] = CHESS_BOOL[7][7] = 1;
    chess[0][3] = chess[0][6] = "|" + f.Bb + "|";
    CHESS_BOOL[0][3] = CHESS_BOOL[0][6] = 1;
    chess[7][3] = chess[7][6] = "|" + f.Bw + "|";
    CHESS_BOOL[7][3] = CHESS_BOOL[7][6] = 1;
    chess[0][4] = "|" + f.Qb + "|";
    CHESS_BOOL[0][4] = 1;
    chess[0][5] = "|" + f.Kb + "|";
    CHESS_BOOL[0][5] = 1;
    chess[7][4] = "|" + f.Qw + "|";
    CHESS_BOOL[7][4] = 1;
    chess[7][5] = "|" + f.Kw + "|";
    CHESS_BOOL[7][5] = 1;

    print(chess);
}

void board_figura_remove(string chess[9][9], char x, int y)
{
    chess[8 - y][8 - (104 - x)] = "|_|";
}

void board_hod(string chess[9][9], char x, int y)
{
    if (CHESS_BOOL[8 - y][8 - (104 - x)] == 1) {
        buff = chess[8 - y][8 - (104 - x)];
        board_figura_remove(chess, x, y);
        CHESS_BOOL[8 - y][8 - (104 - x)] = 0;

    } else {
        chess[8 - y][8 - (104 - x)] = buff;
        CHESS_BOOL[8 - y][8 - (104 - x)] = 1;
        buff = "";
        print(chess);
    }
}

int main()
{
    std::string chess[9][9];
    move(chess);
    int y = 0;
    char x = 0;
    while (cin >> x >> y) {
        if (gorizontal(y) == 1 && vertical(x) == 1) {
            board_hod(chess, x, y);
        } else {
            printf("marks");
        }
    }
    return 0;
}