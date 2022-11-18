//CS10C - Spring 2021
//Lab 7
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks pseudocode

#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(string i) {
    data = i;
    left = nullptr;
    right = nullptr;
    count = 0;
    height = 0;
}