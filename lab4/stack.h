//CS10C - Spring 2021
//Lab 4
//Pair:

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 20;

template<typename T>
class stack {

    private:
        T data[MAX_SIZE];
        int size;

    public:
        //constructs an empty stack
        stack(); 

        //inserts a new element (val) of type T (T could be integer or string) into the data. 
        //if the data array is full, this function should throw an overflow_error exception with error message "Called push on full stack."
        void push(T val); 

        //removes the last element from data. if the data array is empty,
        //this function should throw an out of range exception with error messafe "Called pop on empty stack."
        void pop();

        //returns the top element of stack (last inserted element). if stack is empty,
        //this function should throw an underflow_error exception with error message "Called top on empty stack."
        T top();

        //returns true if the stack is empty, otherwise it returns false
        bool empty();

};

#endif

//constructs an empty stack
template<typename T>
stack<T>::stack() {
    size = 0;
}

//inserts a new element (val) of type T (T could be integer or string) into the data. 
//if the data array is full, this function should throw an overflow_error exception with error message "Called push on full stack."
template<typename T>
void stack<T>::push(T val) {   
    ++size;
    if (size < 21) { // if size = 20-
        data[size - 1] = val;
    }
    else {
        throw overflow_error("Called push on full stack.");
    }
}

//removes the last element from data. if the data array is empty,
//this function should throw an out of range exception with error messafe "Called pop on empty stack."
template<typename T>
void stack<T>::pop() {
    if (size == 0) {
        throw out_of_range("Called pop on empty stack.");
    }
    else {
        size--; //size 4 --> 1, 2, 3, 4 --> size-- --> 1, 2, 3
    }
}

//returns the top element of stack (last inserted element). if stack is empty,
//this function should throw an underflow_error exception with error message "Called top on empty stack."
template<typename T>
T stack<T>::top() {
    T topVal; 
    if (size == 0) {
        throw underflow_error("Called top on empty stack.");
    }
    else {
        topVal = data[size - 1];
    }
    return topVal;
}

//returns true if the stack is empty, otherwise it returns false
template<typename T>
bool stack<T>::empty() {
    if (size == 0) { //size==0 means stack is empty
        return true; //returns true if size==0
    }
    return false; //else returns false
}
