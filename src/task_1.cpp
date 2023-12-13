/*
 * Author: Asqarjon Anvarov
 * Date: 13.12.2023
 * Name: Problem 1
 */

#include <iostream>
#include <vector>

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node *parent, *left, *right;

    Node(int val) : data(val), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
};

class RedBlackTree {
private:
    Node *root;

    void rotateLeft(Node *x);
    void rotateRight(Node *x);
    void fixInsert(Node *z);
    void printTreeHelper(Node *root, int space) const;

public:
    RedBlackTree() : root(nullptr) {}
    void insert(int data);
    void printTree() const;
};

void RedBlackTree::rotateLeft(Node *x) {
    Node *y = x->right;
    x->right = y->left;

    if (y->left != nullptr) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rotateRight(Node *x) {
    Node *y = x->left;
    x->left = y->right;

    if (y->right != nullptr) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

void RedBlackTree::fixInsert(Node *z) {
    while (z != root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node *y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        } else {
            Node *y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int data) {
    Node *z = new Node(data);
    Node *y = nullptr;
    Node *x = root;

    while (x != nullptr) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == nullptr) {
        root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    fixInsert(z);
}

void RedBlackTree::printTreeHelper(Node *root, int space) const {
    if (root == nullptr) {
        return;
    }

    const int INDENTATION = 4;
    space += INDENTATION;

    printTreeHelper(root->right, space);

    std::cout << std::endl;
    for (int i = INDENTATION; i < space; i++) {
        std::cout << " ";
    }

    std::cout << root->data << "(" << (root->color == RED ? "RED" : "BLACK") << ")" << std::endl;

    printTreeHelper(root->left, space);
}

void RedBlackTree::printTree() const {
    printTreeHelper(root, 0);
}

int main() {
    RedBlackTree rbt;

    int N;
    std::cout << "Enter the number of nodes (N): ";
    std::cin >> N;

    std::cout << "Enter the values of nodes:" << std::endl;
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        rbt.insert(value);
    }

    std::cout << "Red-Black Tree:" << std::endl;
    rbt.printTree();

    return 0;
}
