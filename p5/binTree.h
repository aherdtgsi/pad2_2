//
// Created by Andi on 26.01.2022.
//

#ifndef PAD2_2_BINTREE_H
#define PAD2_2_BINTREE_H
class BinTree
{
public:
    struct Node
    {
        char value;
        int count;
        Node* pre;
        Node* left;
        Node* right;
        explicit Node( char ch) : value{ch}, pre{nullptr}, count(1), left{nullptr}, right{nullptr} {}
    };
    BinTree() : root{nullptr}, sz{0} {}
    ~BinTree();
    int size() const { return sz; }
    Node* find( const char& val ) const;
    Node* insert( const char& val );
    void in_order();
    void level_order();
    int countNodes(Node* rootNode);
    Node* insert_as_root( const char& val );

    //helper
    void rotate_right(Node* node);
    void rotate_left(Node* node);
    void make_node_root(Node* node);

private:
    Node* root;
public:
    Node *getRoot() const;

private:
    // die Wurzel
    int sz; // Anzahl der Knoten
};


#endif //PAD2_2_BINTREE_H
