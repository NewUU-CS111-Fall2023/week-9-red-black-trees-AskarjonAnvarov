/*
 * Author: Asqarjon Anvarov
 * Date: 13.12.2023
 * Name: Problem 2
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
    void leftRotate(Node *x);
    void rightRotate(Node *x);
    void printTreeHelper(Node *root, int space) const;

public:
    RedBlackTree() : root(nullptr) {}
    void insert(int data);
    void printTree() const;
    void leftRotate();
    void rightRotate();
};

void RedBlackTree::rotateLeft(Node *x) {
    // ... (as before)
}

void RedBlackTree::rotateRight(Node *x) {
    // ... (as before)
}

void RedBlackTree::fixInsert(Node *z) {
    // ... (as before)
}

void RedBlackTree::leftRotate(Node *x) {
    if (x == nullptr || x->right == nullptr)
        return;

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

void RedBlackTree::rightRotate(Node *x) {
    if (x == nullptr || x->left == nullptr)
        return;

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

void RedBlackTree::insert(int data) {
    
    fixInsert(z);
}

void RedBlackTree::printTreeHelper(Node *root, int space) const {
    
}

void RedBlackTree::printTree() const {
    printTreeHelper(root, 0);
    std::cout << std::endl;
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

    rbt.leftRotate();
    std::cout << "After left rotate:" << std::endl;
    rbt.printTree();

    rbt.rightRotate();
    std::cout << "After right rotate:" << std::endl;
    rbt.printTree();

    return 0;
}

