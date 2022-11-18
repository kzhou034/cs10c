//CS10C - Spring 2021
//Lab 9
//Pair: Baron Fung, Kelley Zhou
//Resource(s): Zybooks

#include <iostream>
#include <ctime>

using namespace std;

const int NUMBERS_SIZE = 50000;

//given 
//generates three similar arrays of random integers
int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

/*  this function sorts the given array in the range from i to k using quicksort method. 
In this function, pivot is the midpoint element (numbers[(i+k)/2]). 
(implementation of this function is given in section 21.5) */
void Quicksort_midpoint(int numbers[], int i, int k) {
    int left = i, right = k;
    int pivot = numbers[(i+k)/2];
    int temp = 0;
    while (left <= right) {
        while (numbers[left] < pivot) {
            left++;
        }
        while (numbers[right] > pivot) {
            right--;
        }
        if (left <= right) {
            temp = numbers[left];
            numbers[left] = numbers[right];
            numbers[right] = temp;
            left++; right--;
        }
    }

    if (i < right) {
        Quicksort_midpoint(numbers, i, right);
    }
    if (left < k) {
        Quicksort_midpoint(numbers, left, k);
    }
}

/*this function utilizes different pivot selection technique in quicksort algorithm. 
The pivot is the median of the following three values: leftmost (numbers[i]), 
midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). 
You should modify the partition function given in section 21.5 
to select the pivot using median-of-three technique. */
void Quicksort_medianOfThree(int numbers[], int i, int k) {
    int leftmost = numbers[i], midpoint = numbers[(i + k)/2], rightmost = numbers[k]; //1 1 2
    int pivot = 0;
    if (leftmost <= midpoint && midpoint <= rightmost) {
        pivot = midpoint;
    }
    else if (midpoint <= leftmost && leftmost <= rightmost) {
        pivot = leftmost;
    }
    else if (leftmost <= rightmost && rightmost <= midpoint) {
        pivot = rightmost;
    }
    else {
        pivot = (leftmost + rightmost) / 2; //if mid is the same as either left or right (there isn't a "middle number")
    }

    
    int left = i, right = k;
    int pivot2 = pivot;
    int temp = 0;
    while (left <= right) {
        while (numbers[left] < pivot2) {
            left++;
        }
        while (numbers[right] > pivot2) {
            right--;
        }
        if (left <= right) {
            temp = numbers[left];
            numbers[left] = numbers[right];
            numbers[right] = temp;
            left++; right--;
        }
    }

    if (i < right) {
        Quicksort_medianOfThree(numbers, i, right);
    }
    if (left < k) {
        Quicksort_medianOfThree(numbers, left, k);
    }
}

/* this function sorts the given array using InsertionSort method. 
(implementation of this method is provided in section 21.3). */
//Source: Zybooks 5.8.1
void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp = 0;  // Temporary variable for swap

    for (i = 1; i < numbersSize; ++i) {
        j = i;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            // Swap numbers[j] and numbers[j - 1]
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

int main() {
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1, arr2, arr3);

    clock_t Start1 = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
    clock_t End1 = clock();
    int elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for QuickSort (midpoint): " << elapsedTime1 << endl;

    clock_t Start2 = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
    clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for QuickSort (median of three): " << elapsedTime2 << endl;

    clock_t Start3 = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    clock_t End3 = clock();
    int elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Elapsed time for InsertionSort: " << elapsedTime3 << endl;

    return 0;
}

