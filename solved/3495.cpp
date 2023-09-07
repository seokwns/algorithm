#include <iostream>
#include <vector>
using namespace std;


int h, w;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> h >> w;

    double area = 0;
    int count = 0;
    char input;

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            cin >> input;

            if (input == '/' || input == '\\') {
                count++;
                area += 0.5;
            }
            else if (input == '.' && count % 2 != 0) {
                area += 1.0;
            }
        }
    }

    cout << area << endl;
    return 0;
}