/*
https://www.acmicpc.net/problem/14425
*/
#include <iostream>
#include <string>
using namespace std;


struct Node {
    string data;
    int hash;
    Node* par;
    Node* left;
    Node* right;
};

Node* root = new Node;
int n, m;

int hash_code(string input) {
    long long result = 0;
    long long modulo_ = 2147483647;
    for (int i = 0; i < input.length(); i++) {
        result = ((result * 37) + input[i]) % modulo_;
    }
    return int(result % 10000);
}

void append(Node* node) {
    Node* iter = root;
    while(true) {
        if (iter->hash >= node->hash) {
            if (iter->left != nullptr) iter = iter->left;
            else {
                iter->left = node;
                node->par = iter;
                break;
            }
        }
        else {
            if (iter->right != nullptr) iter = iter->right;
            else {
                iter->right = node;
                node->par = iter;
                break;
            }
        }
    }
}

bool search(string input) {
    Node* iter = root;
    int input_hash = hash_code(input);
    while(true) {
        if (iter->hash > input_hash) {
            if (iter->left != nullptr) iter = iter->left;
            else {
                return false;
            }
        }
        else if (iter->hash < input_hash) {
            if (iter->right != nullptr) iter = iter->right;
            else {
                return false;
            }
        }
        else {
            if (iter->data == input) return true;
            else {
                if (iter->left->hash == input_hash) iter = iter->left;
                else return false;
            }
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    string rst;
    cin >> rst;
    root->data = rst;
    root->hash = hash_code(rst);
    root->par = nullptr; root->left = nullptr; root->right = nullptr;

    for (int i = 1; i < n; i++) {
        string input;
        cin >> input;
        Node* temp = new Node;
        temp->data = input;
        temp->hash = hash_code(input);
        append(temp);
    }

    int answer = 0;
    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        bool exists = search(input);
        if (exists) answer++;
    }

    cout << answer << "\n";
    return 0;
}