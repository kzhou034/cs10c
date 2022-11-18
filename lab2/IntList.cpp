#include "IntList.h"

#include <iostream>
using namespace std;

//initializes empty list with dummy head and dummy tail
IntList::IntList() {   //dh -> n <- dt
    dummyHead = new IntNode(0); //creates new dummy head
    dummyTail = new IntNode(0); //creates new dummy tail

    dummyHead->prev = nullptr; //dummy head's previous is null
    dummyHead->next = dummyTail; //dummy head's next should be tail

    dummyTail->prev = dummyHead; //dummy tail's prev is dummy head
    dummyTail->next = nullptr; //dummy tail's next is null
    
}

//destructor. deallocates all remaining dynamically allocated memory (all remaining IntNodes)
IntList::~IntList() {
    while (dummyHead->next->next != nullptr) {
        pop_front();
    }
}

//inserts data value (within a new node) @ the front of list. O(1) operation
void IntList::push_front(int value) {
    IntNode *temp = new IntNode(value);
    
    if (empty() == true) { //if there is only dummy head/tail
        //cout << "list empty. doing pushfront" << endl;
        temp->prev = dummyHead; //temp prev is dummy head
        temp->next = dummyTail; //temp next is what was previously dummy head's next node
        //temp is now in between dummy head and what used to be the first/head node(in this case, the dummy tail)
        dummyHead->next = temp; //assigns dummy head next to the temp
        dummyTail->prev = temp; //assigned dummy tail's prev to the temp
        //temp is now between dummy head and dummy tail
    }
    else {
        //cout << "else entered" << endl;
        temp->prev = dummyHead; //temp prev is dummy head
        temp->next = dummyHead->next; //temp next is what was previously dummy head's next node
        //temp is now in between dummy head and what used to be the first/head node
        dummyHead->next = temp; //assigns dummy head next to the temp
        temp->next->prev = temp; //changes the PREV of dummy head next to point to temp
        //temp is now between dummy head and old first node
    }
}

//removes node @ front of list (the node after the dummy head). O(1)
void IntList::pop_front() {
    if (empty() == true) {
        return;
    }
    else {
        //cout << "using popfront now" << endl;
        if (dummyHead->next->next == dummyTail) {
            delete dummyHead->next;
            dummyHead->next = dummyTail;
            dummyTail->prev = dummyHead;
        }
        else {
            IntNode *newHead = dummyHead->next->next;
            delete dummyHead->next;
            dummyHead->next = newHead;
        }
        

        // IntNode* oldHead = dummyHead->next; //oldHead assigned first node(head)
        // dummyHead->next = oldHead->next;
        // oldHead->next->prev = dummyHead;
        // delete oldHead;
    }
}

//inserts data val (within new node) @ back of list. O(1)
/*void IntList::push_back(int value) {
    IntNode *temp = new IntNode(value);
    if (dummyHead->next == dummyTail) {
        dummyHead->next = temp;
        dummyTail->prev = temp;
        temp->prev = dummyHead;
        temp->next = dummyTail;
    }
    else {
        dummyTail->next = temp; //sets what is after the tail to the new node(value)
        temp->prev = dummyTail;
        dummyTail = temp; //sets tail to the next value; last value is new tail
    }
}
*/

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    if (empty()) {
        temp->prev = dummyHead;
        temp->next = dummyTail;

        dummyHead->next = temp;
        dummyTail->prev = temp;
    }
    else {
        temp->prev = dummyTail->prev;
        temp->next = dummyTail;
        dummyTail->prev->next = temp;
        dummyTail->prev = temp;
    }
}

//removes node @ back of list (node before dummy tail). O(1)
void IntList::pop_back() {
    if (empty() == true) {
        return;
    }
    else {
        if (dummyTail->prev->prev == dummyHead) { //list has one node
            delete dummyTail->prev; //dummy tail prev is that single node (which is the head and tail)
            dummyTail->prev = dummyHead; //reassign dummy tail previous to dummy head because there are no more nodes
            dummyHead->next = dummyTail; //since there are no nodes, dummy head points to dummy tail
        }
        else { //dummy tail prev is current tail (not head)
            IntNode* newTail = dummyTail->prev->prev; //dummy tail prev prev is new tail, 
            delete dummyTail->prev; //delete old tail
            dummyTail->prev = newTail; //reassign old tail to new tail
            newTail->next = dummyTail; //new tail points to dummy tail
        }
    }
}

//returns true if list is empty (only has dummy head/tail)
bool IntList::empty() const {
    if (dummyHead->next == dummyTail) {
        //cout << "the list is empty" << endl;
        return true;
    }
    else {
        //cout << "the list is NOT EMPTY" << endl;
        return false;
    }
    return false;
}

//prints on one line all int values in list in REVERSE order 
//each int separated by space, doesn't output newline/space at end
void IntList::printReverse() const {
    //IntNode *temp2 = dummyTail->prev;
    
    if (!empty()) {
        for (IntNode* temp = dummyTail->prev; temp->prev != dummyHead; temp = temp->prev) {
            cout << temp->data << " ";
        }
        cout << dummyHead->next->data;
    }

    /*if (!empty()) {
        for (IntNode* temp = dummyTail; temp->prev->prev != dummyHead; temp = temp->prev) {
            cout << temp->data << " ";
        }
        cout << dummyHead->next->data;
    }*/
    
    /*for (IntNode* temp = dummyTail->prev; temp != dummyHead->next; temp = temp->prev) {
        cout << temp2->data << " ";
    }
    cout << temp2->data; */
}

//outputs to stream all of the ints in the list on one line
//each int separated by space, doesn't output newline/space at end
ostream & operator<<(ostream &out, const IntList &rhs) {
    
    if (!rhs.empty()) {
        IntNode* temp = rhs.dummyHead->next;
        while (temp->next != rhs.dummyTail) {
            out << temp->data << " ";
            temp = temp->next;
        }
        out << rhs.dummyTail->prev->data;
    }
    
    /* IntNode *temp = rhs.dummyHead->next; //takes the head
    if (temp == 0) { //empty
        return out;
    }
    else if (rhs.dummyHead->next->next == rhs.dummyTail) { //one node
        out << temp->data;
    }
    else {
        while (temp->next != rhs.dummyTail->next) { //multiple nodes
            if (temp->prev != rhs.dummyHead) {
                out << temp->data << " ";
                temp = temp->next;
            }
            else {
                out << temp->data;
            }
        }
    } */
    
    return out; 
}



