//CS10C - Spring 2021
//Program 4
//Pair: 
//Resource(s): Code from our Lab 8 submission, cplusplus.com

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

class WordEntry {
    private:
        string word;
        int numAppearances;
        int code;
    public:
        WordEntry(const string &);
        void addNewAppearance();
        void addCode(int );
        const string & getWord();
        int & getCode();
        int & getAppearance();
};

class HashTable {
    private:
        list<WordEntry> *hashTable;
        int size;

    public:
        HashTable(int);
        void put(const string &, int);
        void output();
    
};

#endif
