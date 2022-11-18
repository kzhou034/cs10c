#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList {
    public:
        IntList(); //initializes empty list with dummy head and dummy tail
        ~IntList(); //destructor. deallocates all remaining dynamically allocated memory (all remaining IntNodes)
        void push_front(int value); //inserts data value (within a new node) at the front of list. O(1) operation
        void pop_front(); //removes node at front of list (the node after the dummy head). O(1)
        void push_back(int value); //inserts data val (within new node) @ back of list. O(1)
        void pop_back(); //removes node @ back of list (node before dummy tail). O(1)
        bool empty() const; //returns true if list is empty (only has dummy head/tail)
        
        //prints on one line all int values in list in REVERSE order 
        //each int separated by space, doesn't output newline/space at end
        void printReverse() const; 

        //outputs to stream all of the ints in the list on one line
        //each int separated by space, doesn't output newline/space at end
        friend ostream & operator<<(ostream &out, const IntList &rhs); 
    
    private:
        IntNode *dummyHead;
        IntNode *dummyTail;
        
};

#endif