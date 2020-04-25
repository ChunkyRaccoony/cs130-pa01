#ifndef BSTTREE_H
#define BSTTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class BstTree{
    public:
        BstTree();
        ~BstTree();
        int bstInsert(string word);
        bool bstSearch(string word) const;
        bool bstDelete(string word);
        void bstRangeSearch(string word1, string word2);

    private:
        struct Node {
               int count;
               string value;
               Node *left, *right, * parent;
               Node(string i= "") : value(i), count(0), left(0), right(0), parent(0) { }
               };
        Node* root;
        int insert(string word, Node* n);
        void clear(Node* n);
        Node* getNodeFor(string value, Node* n) const;
        Node* getPredecessorNode(string word) const;
        void printRange(Node* root, string w1, string w2);
};

#endif