#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;


void get_input(vector<double>& means, int question_count) {
    for (int i = 0; i < question_count; i++) {
        double mean = 0.0;
        cin >> mean;
        means.push_back(mean);
    }
}


bool is_possible_number(double mean, int poeple_number) {
    int mean_int = mean * 1000;
    int low = 0;
    int high = poeple_number * 10;
    bool possible = false;
    while(low <= high) {
        int iter = (low + high) / 2;
        int current_mean = iter * 1000 / poeple_number;
        if (current_mean == mean_int) {
            possible = true;
            break;
        }
        else {
            if (current_mean > mean_int) {
                high = iter - 1;
            }
            else {
                low = iter + 1;
            }
        }
    }
    return possible;
}


int get_number_of_people(vector<double>& means, int question_count) {
    int result = 1;
    for (int n = 1; n <= 1000; n++) {
        bool is_possible = true;
        for (int i = 0; i < question_count; i++) {
            if (is_possible_number(means[i], n) == false) {
                is_possible = false;
            }
        }
        if (is_possible) {
            result = n;
            break;
        }
    }
    return result;
}


int main(void) {
    int question_count = 0;
    cin >> question_count;
    vector<double> means;
    get_input(means, question_count);
    int number_of_people = get_number_of_people(means, question_count);
    cout << number_of_people << endl;
    return 0;
}