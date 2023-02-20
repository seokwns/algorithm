/*
https://www.acmicpc.net/problem/1063
*/

#include <iostream>
#include <string>

using namespace std;


char king_row, stone_row;
int king_col, stone_col;

bool isValid(int x, int y) {
    if (x >= 'A' && x <= 'H' && y >= 1 && y <= 8) return true;
    return false;
}

void moving(int dx, int dy) {
    int king_tmp_row = king_row + dx;
    int king_tmp_col = king_col + dy;
    int stone_tmp_row = stone_row + dx;
    int stone_tmp_col = stone_col + dy;
    if (isValid(king_tmp_row, king_tmp_col)) {
        if (king_tmp_row == stone_row && king_tmp_col == stone_col) {
            if (isValid(stone_tmp_row, stone_tmp_col)) {
                king_row = king_tmp_row;
                king_col = king_tmp_col;
                stone_row = stone_tmp_row;
                stone_col = stone_tmp_col;
            }
        }
        else {
            king_row = king_tmp_row;
            king_col = king_tmp_col;
        }
    }
}

int main(void) {    
    int inputs;
    cin >> king_row >> king_col >> stone_row >> stone_col >> inputs;

    while(inputs--) {
        string input;
        cin >> input;

        if (input == "R") moving(1, 0);
        else if (input == "L") moving(-1, 0);
        else if (input == "B") moving(0, -1);
        else if (input == "T") moving(0, 1);
        else if (input == "RT") moving(1, 1);
        else if (input == "LT") moving(-1, 1);
        else if (input == "RB") moving(1, -1);
        else if (input == "LB") moving(-1, -1);
    }

    cout << king_row << king_col << "\n";
    cout << stone_row << stone_col << "\n";

    return 0;
}