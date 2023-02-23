/*
https://www.acmicpc.net/problem/1068
*/
#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int index;
    Node* par;
    int chd;
};

bool exists(int root_index, Node* node) {
    Node* iter = node;
    while(iter->par != nullptr) iter = iter->par;
    return (iter->index == root_index);
}

int main(void) {
    int n;
    cin >> n;

    vector<Node*> nodes;
    int root_index = 0;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node;
        temp->index = i;
        temp->par = nullptr;
        temp->chd = 0;
        nodes.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        if (input == -1) {
            root_index = i;
            nodes[i]->par = nullptr;
            continue;
        }

        nodes[i]->par = nodes[input];
        nodes[input]->chd++;
    }

    int k;
    cin >> k;

    if (k == root_index) cout << "0" << "\n";
    else {
        nodes[k]->par->chd--;
        nodes[k]->par = nullptr;
        int leaf = 0;
        for (int i = 0; i < n; i++) {
            if (exists(root_index, nodes[i]) && nodes[i]->chd == 0) leaf++;
        }
        cout << leaf << "\n";
    }

    return 0;
}