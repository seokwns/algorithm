/*
https://www.acmicpc.net/problem/11387
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Status {
    long long attack;
    long long power;
    long long fatal_hit;
    long long critical_ratio;
    long long attack_speed;
};

long long battle_point(Status& stat) {
    return (
        stat.attack
        * (100 + stat.power)
        * (
            (100 - min(stat.fatal_hit, (long long) 100)) * 100
            + (
                min(stat.fatal_hit, (long long) 100)
                * stat.critical_ratio
            )
        ) 
        * (100 + stat.attack_speed)
    );
}

void update(Status& player, Status& weapon, int type) {
    player.attack += weapon.attack * type;
    player.power += weapon.power * type;
    player.fatal_hit += weapon.fatal_hit * type;
    player.critical_ratio += weapon.critical_ratio * type;
    player.attack_speed += weapon.attack_speed * type;
}

void print_result(long long before, long long after) {
    if (before < after) cout << "+" << "\n";
    else if (before == after) cout << "0" << "\n";
    else cout << "-" << "\n";
}

int main(void) {
    vector<Status> stats;

    long long attack, power, fatal_hit, critical_ratio, attack_speed;
    for (int i = 0; i < 4; i++) {
        cin >> attack >> power >> fatal_hit >> critical_ratio >> attack_speed;
        Status input = {
            attack, 
            power, 
            fatal_hit, 
            critical_ratio, 
            attack_speed
        };
        stats.push_back(input);
    }

    long long cri_point = battle_point(stats[0]);
    long long pabu_point = battle_point(stats[1]);

    update(stats[0], stats[2], -1);
    update(stats[1], stats[3], -1);

    update(stats[0], stats[3], 1);
    update(stats[1], stats[2], 1);

    long long cri_point_changed = battle_point(stats[0]);
    long long pabu_point_changed = battle_point(stats[1]);

    print_result(cri_point, cri_point_changed);
    print_result(pabu_point, pabu_point_changed);

    return 0;
}