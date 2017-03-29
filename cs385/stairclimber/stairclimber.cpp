/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Michael John
 * Date        : The twenty-second day of the ninth month in the year two-thousand and twelve.
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;
vector< vector<int> > v;
vector <int> y;
 
vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    if(num_stairs == 1){
        y.push_back(1);
        v.push_back(y);
        y.pop_back();
        //return v;
    }
    else if(num_stairs == 2){
        y.push_back(1);
        y.push_back(1);
        v.push_back(y);
        y.pop_back();
        y.pop_back();
        y.push_back(2);
        v.push_back(y);
        y.pop_back();
        //return v;
    }
    else if(num_stairs == 3){
        y.push_back(1);
        y.push_back(1);
        y.push_back(1);
        v.push_back(y);
        y.pop_back();
        y.pop_back();
        y.pop_back();

        y.push_back(1);
        y.push_back(2);
        v.push_back(y);
        y.pop_back();
        y.pop_back();

        y.push_back(2);
        y.push_back(1);
        v.push_back(y);
        y.pop_back();
        y.pop_back();

        y.push_back(3);
        v.push_back(y);
        y.pop_back();
        
    }
    else{
        y.push_back(1);
        get_ways(num_stairs-1);
        y.pop_back();
        y.push_back(2);
        get_ways(num_stairs-2);
        y.pop_back();
        y.push_back(3);
        get_ways(num_stairs-3);
        y.pop_back();
    }
    return v;
}

void display_help1(const vector<int> &vec){
    for(unsigned int i = 0; i < vec.size(); i++){
        //cout << "[";
        if(i == vec.size()-1){
            cout << vec[i] << "]" << endl;
        }
        else{
            cout << vec[i] << ", ";
        }
    }
}

int num_of_stairs(const vector <int> &vec){
    int total = 0;
    for(unsigned int i = 0; i < vec.size(); i++){
        total += vec[i];
    }
    return total;
}

int num_digits(int num){
        int digits; //the number of digits
        for(digits = 0; num > 0; digits++){
            num = num/10;
        }
        return digits;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
    int count = 1;
    const int count_width = num_digits(ways.size());
    if(ways.size() == 1){
        cout << "1 way to climb 1 stair." << endl;
        cout << "1. ["<< ways[0][0] << "]";
    }
    else{
        cout << ways.size() << " ways to climb " << num_of_stairs(ways[0]) << " stairs." << endl;
        for(unsigned int i = 0; i < ways.size(); i++){
            if(count_width > 1){
                cout << setw(count_width) << count << ". [";
            }
            else{
                cout << count << ". [";
            }
            display_help1(ways[i]);
            count++;
        }    
    }    
}


int main(int argc, char * const argv[]) {
    if(argc <= 1 || argc > 2){  //error checks to ensure exactly one argument was passed
        cout << "Usage: ./stairclimber <number of stairs>" << endl;
        return 0;
    }
    int limit;
    istringstream iss(argv[1]);
    // Checking for errors
    if (! (iss >> limit) && limit != 0) {
        cerr <<"Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 1){
        cerr << "Error: Number of stairs must be a positive integer." << endl; //2 is the smallest prime
        return 1;
    }
    display_ways(get_ways(limit));
    return 0;
}
