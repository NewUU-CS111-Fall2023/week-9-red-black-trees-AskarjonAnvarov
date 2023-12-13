/*
 * Author: Asqarjon Anvarov
 * Date: 13.12.2023
 * Name: Problem 3
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
    void fixDelete(Node *x, Node *xParent, bool isLeftChild);
    void leftRotate(Node *x);
    void rightRotate(Node *x);
    Node* findMin(Node *node) const;
    Node* findMax(Node *node) const;
    Node* successor(Node *node) const;
    Node* predecessor(Node *node) const;
    void transplant(Node *u, Node *v);

public:
    RedBlackTree() : root(nullptr) {}
    void insert(int data);
    void remove(int data);
    void printTree() const;
    void leftRotate();
    void rightRotate();
    void insertFix(Node *z);
    void deleteFix(Node *x);
};

void RedBlackTree::rotateLeft(Node *x) {
   
}

void RedBlackTree::rotateRight(Node *x) {
   
}

void RedBlackTree::fixInsert(Node *z) {
  
}

void RedBlackTree::leftRotate(Node *x) {
   
}

void RedBlackTree::rightRotate(Node *x) {
  
}

Node* RedBlackTree::findMin(Node *node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* RedBlackTree::findMax(Node *node) const {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* RedBlackTree::successor(Node *node) const {
    if (node->right != nullptr) {
        return findMin(node->right);
    }

    Node *parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* RedBlackTree::predecessor(Node *node) const {
    if (node->left != nullptr) {
        return findMax(node->left);
    }

    Node *parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void RedBlackTree::transplant(Node *u, Node *v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != nullptr) {
        v->parent = u->parent;
    }
}

void RedBlackTree::insert(int data) {
   
    insertFix(z);
}

void RedBlackTree::remove(int data) {
    Node *z = root;
    while (z != nullptr) {
        if (data == z->data) {
            break;
        } else if (data < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }

    if (z == nullptr) {
        std::cout << "Node with value " << data << " not found." << std::endl;
        return;
    }

    Node *y = z;
    Color originalColor = y->color;
    Node *x;

    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = findMin(z->right);
        originalColor = y->color;
        x = y->right;

        if (y->parent == z) {
            if (x != nullptr) {
                x->parent = y;
            }
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (originalColor == BLACK) {
        deleteFix(x);
    }

    delete z;
}

void RedBlackTree::insertFix(Node *z) {
   
}

void RedBlackTree::deleteFix(Node *x) {
    while (x != root && (x == nullptr || x->color == BLACK)) {
        if (x == x->parent->left) {
            Node *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == BLACK) {
                    if (w->left != nullptr) {
                        w->left->color = BLACK;
                    }
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right != nullptr) {
                    w->right->color = BLACK;
                }
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == BLACK) {
                    if (w->right != nullptr) {
                        w->right->color = BLACK;
                    }
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left != nullptr) {
                    w->left->color = BLACK;
                }
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if (x != nullptr) {
        x->color = BLACK;
    }
}

void RedBlackTree::printTreeHelper(Node *root, int space) const {
    // ... (as before)
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

    int valueToDelete;
    std::cout << "Enter the value to delete: ";
    std::cin >> valueToDelete;
    rbt.remove(valueToDelete);

    std::cout << "Red-Black Tree after deletion:" << std::endl;
    rbt.printTree();

    rbt.leftRotate();
    std::cout << "After left rotate:" << std::endl;
    rbt.printTree();

    rbt.rightRotate();
    std::cout << "After right rotate:" << std::endl;
    rbt.printTree();

    return 0;
}
