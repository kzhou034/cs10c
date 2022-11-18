#include "IntList.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Enter test number(1-5): ";
	int t;
	cin >> t;
	cout << endl;

    //pushFRONT, popFRONT
    if (t == 1) {
    cout << "list1 constructor called" << endl;
    IntList list1;
    cout << "pushFRONT 10" << endl;
    list1.push_front(10);
    cout << "pushFRONT 20" << endl;
    list1.push_front(20);
    cout << "pushFRONT 30" << endl;
    list1.push_front(30);
    cout << "list1: " << list1 << endl;
    cout << "popFRONT" << endl;
    list1.pop_front();
    cout << "list1: " << list1 << endl;
    cout << "popFRONT" << endl;
    list1.pop_front();
    cout << "list1: " << list1 << endl;
    cout << "popFRONT" << endl;
    list1.pop_front();
    cout << "list1: " << list1 << endl;
    //cout << "empty? " << list1.empty() << endl;
    cout << "pushFRONT 100" << endl;
    list1.push_front(100);
    cout << "pushFRONT 200" << endl;
    list1.push_front(200);
    cout << "pushFRONT 300" << endl;
    list1.push_front(300);
    cout << "list1: " << list1 << endl;
    //cout << "empty? " << list1.empty() << endl;
    //cout << "already done" << endl;
    //cout << endl;
    }

    //pushBACK, popFRONT
    if (t == 2) {
        cout << endl;
        cout << "list2 constructor called" << endl;
        IntList list2;
        cout << "pushBACK 10" << endl;
        list2.push_back(10);
        cout << "pushBACK 20" << endl;
        list2.push_back(20);
        cout << "pushBACK 30" << endl;
        list2.push_back(30);
        cout << "list2: " << list2 << endl;
        cout << "popFRONT" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
        cout << "popFRONT" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
        cout << "popFRONT" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
    }

    //popBACK
    if (t == 3) {
        cout << endl;
        cout << "list3 constructor called" << endl;
        IntList list3;
        cout << "pushFRONT 10" << endl;
        list3.push_front(10);
        cout << "pushFRONT 20" << endl;
        list3.push_front(20);
        cout << "pushFRONT 30" << endl;
        list3.push_front(30);
        cout << "list3: " << list3 << endl;
        cout << "popBACK" << endl;
        list3.pop_back();
        //cout << "list3: " << list3 << endl;
        cout << "popBACK" << endl;
        list3.pop_back();
        //cout << "list3: " << list3 << endl;
        cout << "popBACK" << endl;
        list3.pop_back();
        cout << "list3: " << list3 << endl;
    }

    if (t == 4) {
        cout << "list4 constructor called" << endl;
        IntList list4;
        cout << "pushFRONT 10" << endl;
        list4.push_front(10);
        cout << "pushFRONT 20" << endl;
        list4.push_front(20);
        cout << "pushFRONT 30" << endl;
        list4.push_front(30);
        cout << "list4: " << list4 << endl;
        cout << "PRINT REVERSE" << endl;
        list4.printReverse();
        cout << endl;
        //cout << "list4: " << list4 << endl;
        cout << endl;
    }

    return 0;
}