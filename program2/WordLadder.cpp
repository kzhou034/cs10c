//CS10C - Spring 2021
//Program 2
//Pair: Baron Fung, Kelley Zhou

#include <fstream>
#include "WordLadder.h"
#include <iterator> // from https://www.cplusplus.com/reference/iterator/
using namespace std;

WordLadder::WordLadder(const string &file) {
    ifstream inFS;
    
    inFS.open(file);
    if (!inFS.is_open()) {
        cout << "Error opening " << file << endl;
        return;
    }

    string word;
    while (inFS >> word) {
        if (word.size() != 5) {
            cout << "Error: word does not contain 5 characters" << endl;
            return;
        }
        dict.push_back(word);
    }

    inFS.close();

}


void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream outFS;
    
    outFS.open(outputFile);
    if (!outFS.is_open()) {
        cout << "Error opening " << outputFile << endl;
        return;
    }
    
    if (start == end) {
        outFS << start << endl;
        outFS.close();
        return;
    }

    list<string>::iterator j; 
    bool startFound = false;
    for (j = dict.begin(); j != dict.end(); j++) {
        if (*j == start) {
            startFound = true;
        }
    }

    bool endFound = false;
    for (j = dict.begin(); j != dict.end(); j++) {
        if (*j == start) {
            endFound = true;
        }
    }

    if (startFound == false && endFound == false) {
        outFS << "Error: start and end words not found." << endl;
        return;
    }
    else if (startFound == false) {
        outFS << "Error: start word not found." << endl;
        return;
    }
    else if (endFound == false) {
        outFS << "Error: end word not found." << endl;
        return;
    }

    stack<string> temp;
    queue< stack<string> > queuedStacks;

    temp.push(start);
    queuedStacks.push(temp); //enqueue
    //Enqueue(queuedStacks, temp);

    stack<string> currStack;
    string wordTop = "";

    //*****while this Queue of Stacks is not empty
    while (!queuedStacks.empty()) { 
        //*****get the word on top of the front Stack of this Queue
        currStack = queuedStacks.front();
        wordTop = currStack.top();

        //cout << "wordTop: " << wordTop << endl;
        list<string>::iterator i; 

        //copy of front stack
        //stack<string> new_stack = currStack; 
        //cout << "new_stack created." << endl;

        //*****for each word in the dictionary
        //cout << "for each word in the dictionary" << endl;
        i = dict.begin();
        while (i != dict.end()) {
            //cout << "for loop i = dict.begin entered" << endl;

            //*****if the word is off by just one letter from the top word
            //cout << "if the word is off by just one letter from the top word" << endl;
            if (oneLetterOff(wordTop, *i)) {
                //cout << "if statement oneLetterOff entered and is TRUE" << endl;
                //*****create a new Stack that is a copy of the front Stack and push on this off-by-one word found
                //new_stack was created above for loop
                stack<string> new_stack = currStack;
                new_stack.push(*i);

                //*****if this off-by-one word is the end word of the ladder, this new Stack contains the entire word
                //*****ladder. You are done!
                if (*i == end) { //this is for when we change a letter, so if it was stop, shop, chop, chip, chit  it would return once the word is chit meaning we've reached the end
                    list<string> output;
                    while (!new_stack.empty()) {
                        output.push_front(new_stack.top());
                        new_stack.pop();
                    }
                    for (i = output.begin(); i != output.end(); ++i) {
                        outFS << *i << " ";
                    }
                    outFS << endl;
                    outFS.close();
                    return;
                }
                //*****otherwise, enqueue this new Stack and remove this word from the dictionary
                else {
                    queuedStacks.push(new_stack);
                    i = dict.erase(i);
                }
            }
            else {
                i++;
            }
        }
        queuedStacks.pop();
    }
    outFS << "No Word Ladder Found." << endl;
    outFS.close();
}

bool WordLadder::oneLetterOff (const string word, const string dictionaryWord) {

    //cout << "if statement entered. checking if one letter off" << endl;
    //cout << "word parameter: " << word << ", dictionary word parameter: " << dictionaryWord << endl;

    int numSameLetters = 0; //keeps track of have many letters are the same in the word
    for (unsigned int j = 0; j < word.size(); j++) {
        if (dictionaryWord.at(j) == word.at(j)) {
            numSameLetters++;
        }
    }
    if (numSameLetters == 4) { //all words are same size, so if it is one less (size - 1), then it is one letter off
        //cout << "one letter off is TRUE" << endl << "numSameLetters: " << numSameLetters << endl;
        return true;
    }

    //cout << "one letter off is FALSE" << endl << "numSameLetters: " << numSameLetters << endl;
    return false;
}