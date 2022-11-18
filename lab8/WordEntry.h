//CS10C - Spring 2021
//Lab 8
//Pair: 
//Reference(s): Zybooks, Assignment 2: WordLadder.cpp

#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {

 private:
	string word;
	int numAppearances;
	int totalScore;
 public:
	WordEntry(const string &, int);
	void addNewAppearance(int);
	const string & getWord();
	double getAverage();
};
#endif
