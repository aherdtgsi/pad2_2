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
                newNode->pre = p;
                sz++;
                return newNode;
            }
            p = p->left;
        }
        else {
            if (p->right == nullptr) {
                p->right = newNode;
                newNode->pre = p;
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



void BinTree::rotate_right(Node* node) {
    if(node == nullptr)
        return;
    Node* p = node;
    Node* q = p->left;
    if(q== nullptr){
        std::cout << "cannot rotate_right(), no left node"<< std::endl;
        return;
    }
    p->left = q->right;
    q->right = p;
    if(p->left!= nullptr){
        p->left->pre = p;
    }
    if(p->pre!= nullptr){
        if(p->pre->right==p){
            p->pre->right = q;
        } else if(p->pre->left==p){
            p->pre->left = q;
        }
        q->pre = p->pre;
    }
    else{
        root = q;
        q->pre= nullptr;
    }
    p->pre=q;

}


void BinTree::rotate_left(Node* node) {
    if(node == nullptr)
        return;
    Node* p = node;
    Node* q = p->right;
    if(q== nullptr){
        std::cout << "cannot rotate_left(), no right node"<< std::endl;
        return;
    }
    p->right = q->left;
    q->left = p;
    if(p->right!= nullptr){
        p->right->pre = p;
    }
    if(p->pre!= nullptr){
        if(p->pre->right==p){
            p->pre->right = q;
        } else if(p->pre->left==p){
            p->pre->left = q;
        }
        q->pre = p->pre;
    }
    else{
        root = q;
        q->pre = nullptr;
    }
    p->pre=q;
}




BinTree::Node *BinTree::insert_as_root(const char &val) {
    Node* newNode = insert(val);
    make_node_root(newNode);
}

void BinTree::make_node_root(BinTree::Node *node) {
    if(node == nullptr){
        return;
    }
    level_order();
    while (node!=root){
        level_order();
        if(node->pre->left==node){
            rotate_right(node->pre);
        } else if(node->pre->right==node){
            rotate_left(node->pre);
        }
    }
}
