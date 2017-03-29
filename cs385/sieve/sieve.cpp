
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

//Michael John
//September Sixth in the Year Two Thousand, Fourteen
//I pledge my honor that I have abided by the Stevens Honor System

using namespace std;

class PrimesSieve{
public:
	PrimesSieve(int limit) : is_prime_(new bool[limit + 1]), limit_(limit){
		sieve();
	}

	~PrimesSieve() {
		delete [] is_prime_;
	}

	inline int num_primes() const{
		return num_primes_;
	}

	void display_primes() const{
		const int max_prime_width = num_digits(max_prime_), primes_per_row = 80 / (max_prime_width + 1); //gives us the max amount of numbers that will fit on one line
		cout << endl;
		cout << "Number of primes found: " << num_primes() << endl;
		cout << "Primes up to " << limit_ <<":" << endl;
		int j = 0;  //used to count the amount of numbers printed on each line

		for(int i = 2; i <= limit_; i++){  //loops through is_prime_[]
			if(is_prime_[i]){
				if(j >= primes_per_row){ // if we are at the maximum amount of nums in the row, move to the next
					cout << endl;
					j = 0;
				}
				if(max_prime_width <= 2){ //if the numbers can be printed on one line
					if(i == max_prime_){
						cout << i;
					}
					else{
						cout << i << " ";
					}
				}
				if(max_prime_width >= 3){ //if the width of the numbers must be set because they won't fit on one line
					if(i == max_prime_ || j == primes_per_row-1){
						cout << setw(max_prime_width) << i;
					}
					else{
						cout << setw(max_prime_width) << i << " ";
					}
				}
				j++;
			}
		}
	}	
private:
	bool * const is_prime_;
	const int limit_;
	int num_primes_;
	int max_prime_;

	int count_num_primes() const{
		int count = 0;
		for(int i = 2; i <= limit_; i++){ //loops through is_prime_ counting the true values
			if(is_prime_[i])
				count++;
		}

		return count;
	}

	int num_digits(int num) const{
		int digits; //the number of digits
		for(digits = 0; num > 0; digits++){
			num = num/10;
		}
		return digits;
	}

	void sieve(){  // calculates the primes
		if (limit_ > 0){ //can't calculate negatives
			is_prime_[0] = false;
		}
		if (limit_ > 1){ //1 isn't prime
			is_prime_[1] = false;
		}
		for(int i = 2; i <= limit_; ++i){
			is_prime_[i] = true;
		}
		for(int i = 2, i_bound = (int)sqrt(limit_); i <= i_bound; ++i){
			if(is_prime_[i]){
				for(int j = i*i; j <= limit_; j+=i){
					is_prime_[j] = false;
				}
			}
		}
		for(max_prime_ = limit_; !(is_prime_[max_prime_]); max_prime_--); //finds the maximum prime
		num_primes_ = count_num_primes();
	}
};

int main(void){
	string limit_str;
	int limit;

	cout << "**************************** Sieve of Eratosthenes ****************************" <<endl;
	cout << "Search for primes up to: ";
	cin >> limit_str;

	istringstream iss(limit_str);
	// Checking for errors
	if (! (iss >> limit)) {
		cerr <<"Error: Input is not an integer." << endl;
		return 1;
	}
	if (limit < 2){
		cerr << "Error: Input must be an integer >= 2." << endl; //2 is the smallest prime
		return 1;
	}
	PrimesSieve ps(limit);
	ps.display_primes();
	return 0;
}