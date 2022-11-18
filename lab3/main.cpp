//CS10C - Spring 2021
//Lab 3
//Pair: Baron Fung, Kelley Zhou

#include <iostream>
#include <ctime> //to seed time
#include <stdexcept> //to implement exceptions
#include <vector> //to use vectors
#include <string> //cuz in case string is used?
#include <cstdlib> //rand

using namespace std;

//Passes in an index of type int and a vector of type T (T could be string, double or int). 
//The function returns the index of the min value starting from "index" to the end of the "vector".
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    T small = vals.at(index); // small of type T = the first value of the vector at index
    for (unsigned i = index; i < vals.size(); ++i) {
        if (vals.at(i) <= small) {
            small = vals.at(i);
            index = i;
        }
    }
    return index;
}

//Passes in a vector of type T and sorts them based on the selection sort method. 
//This function should utilize the min_index function to find the index of the min value in the unsorted portion of the vector.
template<typename T>
void selection_sort(vector<T> &vals) { 
    for (unsigned i = 0; i < vals.size(); ++i) {
        unsigned num = min_index(vals, i); //finds the smallest element, returns index
        T temp = vals.at(i); //swaps
        vals.at(i) = vals.at(num);
        vals.at(num) = temp;
    }
}

//Passes in a vector of type T (T could be string, double or int) and an index of type int. 
//The function returns the element located at the index of the vals. 
//You should write up a try catch block in main function so that when the index is out of the range of the vector, 
//the "std::outofrange" exception will be caught by the catch (const std::outofrange& excpt). 
//Once the exception is caught, it should output "out of range exception occured" followed by a new line.
template<typename T>
T getElement(vector<T> vals, int index) { //getter function
    return vals.at(index);
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){

    //test selection sort
    srand(time(0));
    // vector<char> test;
    // for (unsigned i = 0; i < 5; ++i) {
    //     int size = rand() % 26;
    //     char c = 'a';
    //     for (unsigned y = 0; y < size; ++y) {
    //         ++c;
    //     }
    //     test.push_back(c);
    // }
    // cout << "test vector before sorting: ";
    // for (unsigned i = 0; i < test.size(); ++i) {
    //     cout << test.at(i) << " ";
    // }
    // cout << endl << "selection sort called" << endl;
    // selection_sort(test);

    // cout << "test vector after sorting: ";
    // for (unsigned i = 0; i < test.size(); ++i) {
    //     cout << test.at(i) << " ";
    // }
    
    // cout << endl;
    
    // Part B
    
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    //int size = vals.size();
    while(--numOfRuns >= 0) {
        try {
            cout << "Enter a number: " << endl;
            cin >> index;
            
            // if (index > size || index < 0) { // throws out of range
            //     throw out_of_range("out of range exception occured");
            // }
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (const out_of_range& excpt) { //catches out of range
            cout << excpt.what() << endl;
            cout << "out of range exception occured" << endl;
        }
    }
    return 0;
}
