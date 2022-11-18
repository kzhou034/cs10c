//CS10C - Spring 2021
//Lab 7
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks pseudocode

#ifndef AVLTree_H
#define AVLTree_H

#include <iostream>
#include <string>
#include "Node.h"

class AVLTree {
    public:
        AVLTree(); 
        void insert(const string &);
        int balanceFactor(Node *);
        void printBalanceFactors();
        void visualizeTree(const string &);
    private:
        Node *root;
        //Node* findUnbalancedNode(Node*);
        Node* rotate(Node*);
        Node* rotateLeft(Node*);
        Node* rotateRight(Node*);
        void printBalanceFactors(Node *);
        void visualizeTree(ofstream &, Node *);

        bool search(const string &key) const;
        Node* returnSearch(const string &key);
        void updateHeight(Node*);
        bool replaceChild(Node*, Node*, Node*);
        bool setChild(Node*, string, Node*);
        int get_height(Node*) const;
};

#endif