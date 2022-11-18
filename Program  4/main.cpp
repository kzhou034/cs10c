//CS10C - Spring 2021
//Program 4
//Pair: 
//Resource(s): Code from our Lab 8 submission, cplusplus.com

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include "HashTable.h"

using namespace std;

void Quicksort_midpoint(vector<WordEntry> vec, int i, int k) {
        int left = i, right = k;
        int pivot = vec.at((i+k)/2).getAppearance();
        WordEntry temp("");
        while (left <= right) {
            while (vec.at(left).getAppearance() > pivot) {
                left++;
            }
            while (vec.at(right).getAppearance() < pivot) {
                right--;
            }
            if (left <= right) {
                temp = vec.at(left);
                vec.at(left) = vec.at(right);
                vec.at(right) = temp;
                left++; 
                right--;
            }
        }

        if (i < right) {
            Quicksort_midpoint(vec, i, right);
        }
        if (left < k) {
            Quicksort_midpoint(vec, left, k);
        }
    }

int main() {
    string fileName = "";

    cout << "Enter name of file: ";
    cin >> fileName;
    cout << endl;

    ifstream file;

    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }

    string text = "";
    string input = "";
    vector<string> vectors;

    while (!file.eof()) {
        //getline(file, input);
        file >> input;
        vectors.push_back(input);
        text += input;
        text += " ";
    }
    file.close();

    //it     '     s     an     airplane     !
    // I am a tree. 

    // ... 
    cout << "size: " << vectors.size() << endl;

    vector<WordEntry> vec;

    
    // splits strings
    
    for (int i = 0; i < vectors.size(); i++) { // !!!!!
        cout << "enter vectors" << endl;
        string lah = "";
        string alph = "";
        cout << "word: " << vectors.at(i) << endl;
        for (int test = 0; test < vectors.at(i).size(); ++test) {
            cout << "letter: " << vectors.at(i).at(test) << endl;
            if (ispunct(vectors.at(i).at(test)) || isdigit(vectors.at(i).at(test))) {
                lah.push_back(vectors.at(i).at(test));
                bool char_exist = false;
                if (vec.size() > 0) {
                    for (int l = 0; l < vec.size(); ++l) {
                        if (lah == vec.at(l).getWord()) {
                            vec.at(l).addNewAppearance();
                            char_exist = true;
                        }
                    }
                    if (char_exist == false) {
                        vec.push_back(WordEntry(lah));
                    }
                }
                else {
                    vec.push_back(WordEntry(lah));
                }
            }
            else if (isalpha(vectors.at(i).at(test))) { //who.
                alph.push_back(vectors.at(i).at(test));
            }
        }
        if (vec.size() > 0) {
            bool exist = false;
            for (int y = 0; y < vec.size(); ++y) {
                if (vec.at(y).getWord() == alph) {
                    cout << "add appearance" << endl;
                    vec.at(y).addNewAppearance();
                    exist = true;
                }
            }
            if (exist == false) {
                vec.push_back(WordEntry(alph));
            }
        }
        else {
            vec.push_back(WordEntry(alph));
        }
    }
        
    cout << "vec size: " << vec.size() << endl;
    
    //     if (isspace(text[i])) {
    //         i++;
    //     }
    //     if (ispunct(text[i]) || isdigit(text[i])) {
    //         string dah = "";
    //         dah.push_back(text[i]);
    //         bool word_search = false;
    //         for (int w = 0; w < vec.size(); ++w) {
    //             //cout << "Word to compare: " << vec.at(w).getWord() << endl;
    //             if (dah == vec.at(w).getWord()) {
    //                 vec.at(w).addNewAppearance();
    //                 //cout << "Appearances: " << vec.at(w).getAppearance() << endl;
    //                 word_search = true;
    //             }
    //         }
    //         if (word_search == false) {
    //             vec.push_back(WordEntry(dah));
    //         }
    //     }
    //     else {    
    //         //string k = text.substr(0, );
    //         char temp = text[i];
    //         string temp2 = "";
    //         bool word = false;
    //         while (word == false) {
    //             if (isdigit(text[i + 1]) || isspace(text[i+1]) || ispunct(text[i+1])) {
    //                 //WordEntry(temp);
    //                 temp2.push_back(temp);
    //                 bool word_search = false;
    //                 int j = 0;
    //                 for (int y = 0; y < vec.size(); y++) {
    //                     if (temp2 == vec.at(y).getWord()) {
    //                         word_search = true;
    //                         j = y;
    //                     }
    //                 }
    //                 if (word_search) {
    //                     vec.at(j).addNewAppearance();     //<-- updates count
    //                 }
    //                 else {
    //                     vec.push_back(WordEntry(temp2));
    //                 }
    //                 word = true;
    //             }
    //             else {
    //                 temp += text[i + 1];
    //                 i++;
    //             }
    //         }
    //     }
    // }

    for (int i = 0; i < vec.size(); ++i) {
        cout << "vector word: " << vec.at(i).getWord() << endl;
    }
        
    //quicksorting by appearances G->L
    Quicksort_midpoint (vec, 0, vec.size()-1);   
    
    int counter = 1;
    HashTable encoder(vec.size());   //<-- creates hash table of vec.size size (encoder)
    HashTable decoder(vec.size());

    for (int i = 0; i < vec.size(); ++i) {
        encoder.put(vec.at(i).getWord(), i);
        decoder.put(vec.at(i).getWord(), i);
        vec.at(i).addCode(counter);
        counter++;
        cout << "counter work pls" << endl;
    }

    // string user_input = "";
    // cout << "search for a word: ";
    // cin >> user_input;

    cout << "Token - Frequency - Code" << endl;
    encoder.output();



    return 0;
}
