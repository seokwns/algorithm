#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;


int main(void) {
    int teams;
    while(scanf("%d", &teams) == 1) {
        vector<vector<char>> stage;
        for (int i = 0; i < teams; i++) {
            vector<char> line;
            for (int j = 0; j < teams; j++) {
                char team;
                cin >> team;
                line.push_back(team);
            }
            stage.push_back(line);
        }
        vector<vector<char>> cstage(stage);
        for (int i = 0; i < teams; i++) {
            sort(cstage[i].begin(), cstage[i].end());
        }

        int line = 0;
        for (int i = 0; i < teams; i++) {
            char sample = cstage[0][i];
            bool check = true;
            for (int j = 1; j < teams; j++) {
                if (cstage[j][i] != sample) {
                    check = false;
                    if (j == 1) {
                        
                    }
                    break;
                }
            }
        }
    }
    return 0;
}