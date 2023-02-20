/*
https://rebro.kr/63
http://contest.usc.edu/index.php/Fall07/Home?action=download&upname=problems.in.txt
http://contest.usc.edu/index.php/Fall07/Home?action=download&upname=problems.out.txt

https://www.acmicpc.net/problem/5175
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
    int tc;
    cin >> tc;

    vector<string> outputs;
    for (int cts = 1; cts <= tc; cts++) {
        int n, m;
        cin >> m >> n;
        
        vector<int> masks;
        for (int i = 0; i < n; i++) {
            long long mask = 0;
            do {
                int data;
                cin >> data;
                mask = mask | (1 << (data - 1));
            } while (getc(stdin) == ' ');

            if (find(masks.begin(), masks.end(), mask) == masks.end()) {
                masks.push_back(mask);
            }
            else {
                masks.push_back(-1);
            }
        }
        // cout << "masks: ";
        // for (auto mask : masks) {
        //     cout << mask << " ";
        // }
        // cout << endl;

        long long set = 1, full = 0, temp;
        for (int mm = 0; mm < m; mm++) full = full | (1 << mm);

        for (int x = 0; x < n; x++) {
            if (masks[x] == -1) continue;

            if (masks[x] == full) {
                set = 0 | (1 << x);
                break;
            }

            long long tmp = masks[x];
            for (int y = 1; y < n; y++) {
                if (masks[y] == -1) continue;

                int t = tmp | masks[y];
                if (t != tmp) {
                    set = set | (1 << y);
                    tmp = t;
                }
            }
        }


        cout << "full    masks: ";
        for (int j = 0; j < n; j++) {
                cout << (full & (1 << j));
        }
        cout << endl;
        for (int y = 1; y < n; y++) {    
            if (masks[y] == -1) continue;

            int tmpset = set ^ (1 << y);
            int tmpfull = masks[0];
            for (int j = 1; j < n; j++) {
                if (tmpset & (1 << j)) {
                    tmpfull = tmpfull | masks[j];
                }
            }
            cout << "current: " << (char)('A' + y) << "   " << masks[y] << "    masks: ";
            for (int j = 0; j < n; j++) {
                    cout << (tmpfull & (1 << j));
            }
            cout << endl;
            // cout << "current : " << (char)('A' + y) << " | " << tmpfull << " | " << tmpset << " , " << set << endl;
            if (tmpfull == full) set = tmpset;
        }

        string ss = "Data Set ";
        ss.append(to_string(cts));
        ss.append(": ");
        for (int i = 0; i < n; i++) {
            if (set & (1 << i)) {
                ss += (char)('A' + i);
                ss.append(" ");
            }
        }
        outputs.push_back(ss);
    }

    for (auto output : outputs) {
        cout << output << "\n\n";
    }

    return 0;
}

/*
1
6 5
1 2
2 3
3 4
4 5
5 6

10 10
1 4 7
2 5 8
3 6 9
4 10 1
1 3 5
2 4 6
7 9 10
8 7 6 
7 8 6
6 8 7

1
4 14
1 2
1 2
2 3
2 3
1 2
2 3
4 2
4 3
4 2
4 3
4 1
4 2
4 1
4 3
*/