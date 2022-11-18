//CS10C - Spring 2021
//Program 4
//Pair: Baron Fung, Kelley Zhou
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
        WordEntry(const string &, const int&, const int&);
        void addNewAppearance();
        void addCode(int );
        const string & getWord();
        const int & getCode();
        const int & getAppearance();
};

class HashTable {
    private:
        list<WordEntry> *hashTable;
        int size;

    public:
        HashTable(int);
        void put(const string &, int, int, int);
        void output(int);
    
};

#endif