//CS10C - Spring 2021
//Lab 7
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks pseudocode

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node* left;
        Node* right;
        Node* parent;  
        int count;
        int height;
        Node(string);
};

#endif