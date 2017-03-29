/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Michael John
 * Version     : 1.0
 * Date        : The twenty third day in the tenth month, two thousand and fourteen years after the birth of his son.
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by The Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;
// Function prototype.
static long mergesort(int array[], int scratch[], int low, int high);

/**
 * Counts the number of inversions in an array in theta(n^2) time.
 */
long count_inversions_slow(int array[], int length) {
    long int counter = 0;
    for(int i = 0; i < length-1; ++i){
        for(int j = i+1; j < length; ++j){
            if(array[i] > array[j]){
                counter++;
            }
        }
    }
    cout << "Number of inversions: ";
    return counter;
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    // TODO
    // Hint: Use mergesort!
    int *scratch = new int[length];
    cout << "Number of inversions: ";
    return mergesort(array, scratch, 0, length-1);
    delete [] scratch;
}

static long mergesort(int array[], int scratch[], int low, int high) {
    // TODO
    long int count = 0;
    if(low < high){
        int mid = low + ((high-low) >> 2);
        count += mergesort(array, scratch, low, mid) + mergesort(array, scratch, mid+1, high);

        int i = low, j = mid+1;
        for(int k = low; k <= high; ++k){
            if((i <= mid) && (j > high || array[i] <= array[j])){
                scratch[k] = array[i++];
            }
            else{
                count += (j-k);
                scratch[k] = array[j++];
                //cout << low << mid << high << count << endl; 
                //cout << i << j << k << endl;        
                 // don't add one but some other amount   
            }
        }
        for(int k = low; k <= high; k++){
            array[k] = scratch[k];
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    // TODO: parse command-line argument
    bool val = false;

    if(argc > 2){ // too many argument error
        cout << "Usage: ./inversioncounter [slow]"<< endl;
        return 0;
    }
    if(argc == 2){
        istringstream iiss(argv[1]);
        string input;
        iiss >> input;
        if(input != "slow"){ // if the input is not the word slow
            cout << "Error: Unrecognized option " << input << "." << endl;
            return 0;
        }
        val = true;
    }
    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }
    if(values.size() == 0){
        cout << "Error: Sequence of integers not received." << endl;
        return 0;
    }
    
    int *values_array  = new int[values.size()];
    for (unsigned int i = 0; i < values.size(); ++i){
        values_array[i] = values[i];
    }
    // TODO: produce output
    if(values.size() == 1){
        cout << "Number of inversions: 0" << endl;
        return 0;
    }
    if(val){
        cout << count_inversions_slow(values_array, values.size()) << endl;

    }
    else{
        cout << count_inversions_fast(values_array, values.size()) << endl;
    }
    delete [] values_array;
    return 0;
}
