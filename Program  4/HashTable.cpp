//CS10C - Spring 2021
//Program 4
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Code from our Lab 8 submission, cplusplus.com

#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include "HashTable.h"

using namespace std;

//from Lab 8: WordEntry.cpp file, added getCode
WordEntry::WordEntry(const string &text) {
	if (text == "") {
        word = "";
        numAppearances = 0;
        code = -1;
    }
    
    word = text;
    numAppearances = 1;
    code = -20; //initialized code
}

//from Lab 8: WordEntry.cpp file
void WordEntry::addNewAppearance() {
	++numAppearances;
}

void WordEntry::addCode(int num) {
    cout << "code before: " << code << " num: " << num << endl;
    code = num;
    cout << "add code used: " << code << endl;
}

//from Lab 8: WordEntry.cpp file
const string & WordEntry::getWord() {
    return word;
}

//based on getWord
int & WordEntry::getCode() {
    return this->code;
}

int & WordEntry::getAppearance() {
    return this->numAppearances;
}

/* from Lab 8: HashTable.cpp file
*  HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	size = s;
    hashTable = new list<WordEntry>[size]; //list of type WordEntry of size
}


/* from Lab 8: HashTable.cpp file
*  put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int num) {
    // if (contains(s)) {
    //     list<WordEntry>::iterator i;
    //     i = hashTable[num].begin();
    //     while (i != hashTable[num].end()) {
    //         if (i->getWord() == s) {
    //             i->addNewAppearance(); //add 1 to the frequency
    //             return;
    //         }
    //         i++;
    //     }
    // }
    // else {
        WordEntry newWord(s);
        hashTable[num].push_front(newWord);
   // }
}

void HashTable::output() {
    list<WordEntry>::iterator i;
    i = hashTable[0].begin();
    int num = hashTable->size();
    while (i != hashTable[0].end()) {
        cout << i->getWord() << " - " << i->getAppearance() << " - " << i->getCode() << endl;
        i++;
    }
    cout << "hashtable size: " << num << endl;
}
