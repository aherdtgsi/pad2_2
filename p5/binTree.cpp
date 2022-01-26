//
// Created by Andi on 26.01.2022.
//

#include <stack>
#include <queue>
#include "binTree.h"
#include "iostream"

BinTree::~BinTree() {
    delete root;
}

BinTree::Node *BinTree::find(const char &val) const {
    Node* p = root;
    while (p != nullptr) {
        if (p->value == val) {
            return p;
        } else if (p->value > val) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return nullptr;
}

BinTree::Node *BinTree::insert(const char &val) {
    Node* p = root;
    Node* newNode = new Node(val);
    if (root == nullptr) {
        root = newNode;
        sz++;
        return newNode;
    }
    while (p != nullptr) {
        if (p->value == val) {
            p->count++;
            return p;
        }
        else if (p->value > val) {
            if (p->left == nullptr) {
                p->left = newNode;
                sz++;
                return newNode;
            }
            p = p->left;
        }
        else {
            if (p->right == nullptr) {
                p->right = newNode;
                sz++;
                return newNode;
            }
            p = p->right;
        }
    }
    return nullptr;
}
void BinTree::in_order() {
    std::cout << "in_order: ";
    if (root == nullptr) {
        return;
    }
    std::stack<Node*> st;
    Node* p = root;
    while (p != nullptr || !st.empty()) {
        while (p != nullptr) {
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        if(p->count!=1){
            std::cout << p->value << "(" << p->count << ")" << " ";
        } else{
            std::cout << p->value << " ";
        }
        p = p->right;
    }
    std::cout << std::endl;
}

void BinTree::level_order() {
    std::cout << "level_order: ";
    if (root == nullptr) {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        if(p->count!=1){
            std::cout << p->value << "(" << p->count << ")" << " ";
        } else{
            std::cout << p->value << " ";
        }
        if (p->left != nullptr) {
            q.push(p->left);
        }
        if (p->right != nullptr) {
            q.push(p->right);
        }
    }
    std::cout << std::endl;
}

int BinTree::countNodes(Node* rootNode) {
    if (rootNode == nullptr) {
        return 0;
    }
    return 1 + countNodes(rootNode->left) + countNodes(rootNode->right);
}

BinTree::Node *BinTree::getRoot() const {
    return root;
}
