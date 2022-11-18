//CS10C - Spring 2021
//Lab 5
//Pair: 

#include "Heap.h"
#include <iostream>

using namespace std;

/*Initializes an empty heap.*/
Heap::Heap() {
    numItems = 0;
}

/*Inserts a PrintJob to the heap without
violating max-heap properties.*/
void Heap::enqueue(PrintJob* add) {
    if (numItems == MAX_HEAP_SIZE) { //doesn't enqueue if heap is full
        //cout << "Heap is full." << endl;
        return;
    }
    else {
        numItems++;
        arr[numItems - 1] = add;
        // cout << "Current elements in heap: ";
        // for (int i = 0; i < numItems; i++) {
        //     cout << arr[i]->getPriority() << " ";
        // }
        perlocateUp(numItems - 1);

        // cout << endl;
        // cout << "Current elements in heap (after insert): ";
        // for (int i = 0; i < numItems; i++) {
        //     cout << arr[i]->getPriority() << " ";
        // }
    }
}
/*Removes the node with highest priority from the heap. 
Follow the algorithm on priority-queue slides. */
void Heap::dequeue() {
    if (numItems > 0) { 
        //cout << "removing: ";
        PrintJob* highestPriority = arr[0];
        //cout << highestPriority->getPriority() << endl;
        arr[0] = arr[numItems - 1]; //last node is now at the root
        delete highestPriority; //deletes old root
        arr[numItems - 1] = 0; //last node is now empty (holds 0)
        numItems--; //num of items in heap is reduced by 1
        //cout << "swapped. numItems decreased" << endl;
        trickleDown(0); //trickle starts at root (0)
    }
    else { //heap is empty
        //cout << "Heap is empty." << endl;
        return;
    }
}

/*Returns the node with highest priority.*/
PrintJob* Heap::highest() {
    if (numItems == 0) {
        return nullptr;
    }
    return arr[0]; //node with highest priority should be the root (index 0)
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages
(Add a new line at the end.)*/
void Heap::print() {
    if (numItems > 0) {
        cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
}

/*This function is called by dequeue function
to move the new root down the heap to the 
appropriate location.*/
void Heap::trickleDown(int root) {
    // cout << "Current elements: ";
    // for (int i = 0; i < numItems; i++) {
    //     cout << arr[i]->getPriority() << " ";
    // }
    
    if (root * 2 + 1 >= numItems || root * 2 + 2 > numItems) {
        return;
    }

    PrintJob* leftChild = arr[(root *2) + 1];
    PrintJob* rightChild = arr[(root *2) + 2];
    if (((numItems - 1) % 2 > 0) && (arr[root]->getPriority() > leftChild->getPriority())) {
        if (rightChild == nullptr) {
            return;
        }
    }
    
    
    //cout << "CurrRoot: " << arr[root]->getPriority() << ", Left child: " << leftChild->getPriority() << ", Right child: " << rightChild->getPriority() << endl << endl;

    if (leftChild->getPriority() != 0 && rightChild->getPriority() != 0) { //left and right children are not empty
        //cout << "left and right children are not empty" << endl;
        if (leftChild->getPriority() >= rightChild->getPriority()) { //left
            //cout << "left is greater than right" << endl;
            PrintJob* temp = arr[root];
            arr[root] = arr[(root * 2) + 1];
            arr[(root * 2) + 1] = temp;
            trickleDown((root * 2) + 1);
        }
        else if (leftChild->getPriority() < rightChild->getPriority()){ //right
            //cout << "right is greater than left" << endl;
            PrintJob* temp = arr[root];
            arr[root] = arr[(root * 2) + 2];
            arr[(root * 2) + 2] = temp;
            trickleDown((root * 2) + 2);
        }
    }
    else if (leftChild->getPriority() != 0) { //left child, no right
        //cout << "left child, no right" << endl;
        if (leftChild->getPriority() > arr[root]->getPriority()) {
            PrintJob* temp = arr[root];
            arr[root] = arr[(root * 2) + 1];
            arr[root * 2 + 1] = temp;
            trickleDown((root * 2) + 1);
        }
    }
    else if (rightChild->getPriority() != 0) {
        //cout << "right child, no left" << endl;
        if (rightChild->getPriority() > arr[root]->getPriority()) {
            PrintJob* temp = arr[root];
            arr[root] = arr[(root * 2) + 2];
            arr[(root * 2) + 2] = temp;
            trickleDown((root * 2) + 2);
        }
    }

}

//helper
void Heap::perlocateUp(int items) {
    while( (items >= 1) && (arr[items]->getPriority() > arr[(items - 1 ) / 2]->getPriority()) ) {
        swap(arr[items], arr[(items - 1) / 2]);
        items = (items - 1) / 2;
        if (arr[numItems - 1]->getPriority() > arr[(items - 1) / 2]->getPriority()) {
            swap(arr[numItems - 1], arr[(numItems - 1) / 2]);
        }
    }
}
