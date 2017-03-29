/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Michael John
 * Date        : The Thriteenth day on the Ninth month of the Two Thousand and Fourteenth year.
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my Honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string str) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    char c;
    for(unsigned int i = 0; i < str.length(); i++){
       	c = str.at(i);
    	if(!(isalpha(c))){  //checks is the letter is in the alphabet
    		cout << "Error: String must contain only lowercase letters." << endl;
    		return false;
    	}
    	if(isupper(c)){  //checks if the letter is uppercase
    		cout << "Error: String must contain only lowercase letters." << endl;
    		return false;
    	}
    }
    return true;
}

bool all_unique_letters(const string str) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
    int c;
    int v = 0;
    for(unsigned int i = 0; i < str.length(); i++){
    	c = str.at(i)-97;  //the position of the letter in the alphabet
    	if(((v>>c) & 1) == 1){  //determines if the letter has already been seen
    		cout << "Duplicate letters found." << endl;
    		return false;								//returns false if it has been seen
    	}
    	v |= (1<<c);  //adds the letter to the count if it hasn't been seen
    }
    return true;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    if(argc <= 1 || argc > 2){  //error checks to ensure exactly one argument was passed
    	cout << "Usage: ./unique <string>" << endl;
    	return 0;
    }
    if(is_all_lowercase(argv[1]) && all_unique_letters(argv[1])){  //checks for case and uniqueness
    	cout << "All letters are unique." << endl;
    	return 0;
    }
    return 0;
}
