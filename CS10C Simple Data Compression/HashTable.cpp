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
    code = -1; //initialized code
}

WordEntry::WordEntry(const string & s, const int& n, const int& c) {
    word = s;
    numAppearances = n;
    code = c;
}

//from Lab 8: WordEntry.cpp file
void WordEntry::addNewAppearance() {
	++numAppearances;
}

void WordEntry::addCode(int num) {
    code = num;
}

//from Lab 8: WordEntry.cpp file
const string & WordEntry::getWord() {
    return word;
}

//based on getWord
const int & WordEntry::getCode() {
    return code;
}

const int & WordEntry::getAppearance() {
    return numAppearances;
}

/* from Lab 8: HashTable.cpp file
*  HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	this->size = s;
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
void HashTable::put(const string &s, int num, int code, int freq) {
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
    
    WordEntry newWord(s, freq, code);
    hashTable[num].push_front(newWord);
    
   // }
}

void HashTable::output(int index) {
    list<WordEntry>::iterator i;
    int y = index;
    i = hashTable[y].begin();
    //int num = hashTable->size();
    // while (i != hashTable[y].end()) {
    cout << i->getWord() << " - " << i->getAppearance() << " - " << i->getCode() << endl;
    //     i++;
    // }
}

