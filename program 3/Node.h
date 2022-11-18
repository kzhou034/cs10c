//CS10C - Spring 2021
//Program 3
//Pair: 

#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string>
using namespace std;

class Node {
    // private:
    //     Node *left;
    //     Node *right;
    //     string item;

    public:
        Node(string str);
        int count;
        Node *left;
        Node *right;
        string item;

};

#endif
