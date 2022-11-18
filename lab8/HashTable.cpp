//CS10C - Spring 2021
//Lab 8
//Pair: Baron Fung, Kelley Zhou
//Reference(s): Zybooks, Assignment 2: WordLadder.cpp

#include "HashTable.h"
#include "WordEntry.h"
#include <iterator> // from https://www.cplusplus.com/reference/iterator/

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	size = s;
    hashTable = new list<WordEntry>[size]; //list of type WordEntry of size
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    int stringHash = 5381;

    for (char c: s) { //for each character c in s
        stringHash = (((stringHash * 33) % size) + c) % size; //From lab session 5/20
    }
    return stringHash % size;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
    if (contains(s)) {
        list<WordEntry>::iterator i;
        i = hashTable[computeHash(s)].begin();
        while (i != hashTable[computeHash(s)].end()) {
            if (i->getWord() == s) {
                i->addNewAppearance(score); //updates addNewAppearance with score from parameter (from WordEntry)
                return;
            }
            i++;
        }
    }
    else {
        WordEntry newWord(s, score);
        hashTable[computeHash(s)].push_front(newWord);
    }
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    if (contains(s)) { //if word is in the table
        list<WordEntry>::iterator i;
        i = hashTable[computeHash(s)].begin();
        while (i != hashTable[computeHash(s)].end()) {
            if (i->getWord() == s) {
                return i->getAverage(); //returns the average of the string (getAverage() from WordEntry)
            }
            i++;
        }
    }
    return 2.0; //returned if not found/neutral result
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) { 
    list<WordEntry>::iterator i;
    i = hashTable[computeHash(s)].begin();
    while (i != hashTable[computeHash(s)].end()) {
        if (i->getWord() == s) { //getWord() from WordEntry 
            return true; //word is in the table. end function
        }
        i++;
    }
    return false; //word is not in the table
}

// MAIN.CPP BELOW ====================================
/*
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	// declare a few needed variables for inputing the data
	string line;    
	int score;
	string message = " ";
	
	// open input file
	ifstream myfile("movieReviews.txt");
	if (myfile.fail()) {
	    cout << "could not open file" << endl;
	    exit(1);
	}
	
	//create hash table
	HashTable table(20071);
	
	while (!myfile.eof()) {
	    myfile >> score;     // get score
	    myfile.get();        // get blank space
	    getline(myfile, line);
	    int len = line.size();
	    while(len > 0) {     // identify all individual strings
	        string sub;
	        len = line.find(" ");
	        if (len > 0) {
	            sub = line.substr(0, len);
	            line = line.substr(len + 1, line.size());
	        }
	        else {
	            sub = line.substr(0, line.size() - 1);
	        }
	        table.put(sub, score); // insert string with the score
	    }
	}
	
	// after data is entered in hash function
	// prompt user for a new movie review
	while(message.length() > 0) {
	    cout << "enter a review -- Press return to exit: " << endl;
	    getline(cin, message);
	
	    // used for calculating the average
	    double sum = 0;
	    int count = 0;
	    
	    double sentiment = 0.0;
	    
	    size_t len = message.size();
	    // get each individual word from the input
	    while(len != string::npos) {
	        string sub;
	        len = message.find(" ");
	        if (len != string::npos) {
	            sub = message.substr(0, len);
	            message = message.substr(len + 1, message.size());
	        }
	        else {
	            sub = message;
	        }
	        // calculate the score of each word
	        sum += table.getAverage(sub);
	        ++count;
	    }
	
	    if (message.size() > 0) {
	    	sentiment = sum / count;
	        cout << "The review has an average value of " << sentiment << endl;
	        if (sentiment >= 3.0) {
	        	cout << "Positive Sentiment" << endl;
	        }
	        else if (sentiment >= 2.0) {
	        	cout << "Somewhat Positive Sentiment" << endl;
	        }
	        else if (sentiment >= 1.0) {
	        	cout << "Somewhat Negative Sentiment" << endl;
	        }
	        else {
	        	cout << "Negative Sentiment" << endl;
	        }
	        cout << endl;
	    }
	}
	
	return 0;
}
*/