//CS10C - Spring 2021
//Program 3
//Pair: Baron Fung, Kelley Zhou
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node(string str) {
    left = nullptr;
    right = nullptr;
    item = str;
    count = 0;
}