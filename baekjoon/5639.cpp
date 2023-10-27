#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
};

void insert(Node* root, Node* node) {
    Node* cursor = root;
    while (true) {
        if (cursor->key > node->key) {
            if (cursor->left == nullptr) {
                cursor->left = node;
                node->parent = cursor;
                break;
            }
            else cursor = cursor->left;
        }
        else {
            if (cursor->right == nullptr) {
                cursor->right = node;
                node->parent = cursor;
                break;
            }
            else cursor = cursor->right;
        }
    }
}

void travel(Node* node) {
    if (node->left != nullptr) {
        travel(node->left);
    }
    if (node->right != nullptr) {
        travel(node->right);
    }
    cout << node->key << endl;
}

int main(void) {
    int n;
    cin >> n;

    Node* root = new Node;
    root->key = n;
    root->left = nullptr;
    root->right = nullptr;

    while (cin >> n) {
        Node* node = new Node;
        node->key = n;
        node->left = nullptr;
        node->right = nullptr;
        insert(root, node);
    }

    travel(root);
}