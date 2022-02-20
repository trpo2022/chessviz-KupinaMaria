#include <iostream>
#include <lib/playermove.h>
#include <stdlib.h>
#include <string>
using namespace std;
void print(string chess[][9])
{
    char num = 'A';
    cout << "Пример хода: 'd2 d4','d7 d5' через пробел\n" << endl;

    for (int i = 0; i < 8; i++) {
        cout << 8 - i;
        for (int j = 0; j < 9; j++) {
            cout << chess[i][j];
        }
        cout << endl;
    }

    for (int i = 1; i < 9; i++) {
        cout << "  " << num;
        ++num;
    }
}
