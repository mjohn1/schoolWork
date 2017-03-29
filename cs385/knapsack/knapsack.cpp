/*******************************************************************************
 * Name        : knapsack.cpp
 * Author      : Michael John
 * Date        : The Twenty-Second day in the Eleventh month Two-Thousand, Fourteen years after the birth of a man.
 * Description : Fills a knapsack with items of given weight and value the most effiecient way.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <fstream>

using namespace std;

struct Item {
    unsigned int item_number, weight, value;
    string description;

    explicit Item(const unsigned int item_number,
                  const unsigned int weight,
                  const unsigned int value,
                  const string &description) :
                          item_number(item_number),
                          weight(weight),
                          value(value),
                          description(description) { }

    friend std::ostream& operator<<(std::ostream& os, const Item &item) {
        os << "Item " << item.item_number << ": " << item.description
          << " (" << item.weight
          << (item.weight == 1 ? " pound" : " pounds") << ", $"
          << item.value << ")";
        os.flush();
        return os;
    }
};

class Knapsack{
public:
	Knapsack(string fn, int c): file_name(fn), capacity(c){
		string line;
		ifstream input_file_(file_name.c_str());
		counter = 1; //counts the lines
		//loops through all the lines until there are no more lines
		while(getline(input_file_, line)){
			read_line(line, counter);
			counter++;
		}
		counter--;
		knap = new int*[counter+1];
		for (int i = 0; i < counter+1; ++i){
			knap[i] = new int[capacity+1];
		}
		dynamic();
	}
	~Knapsack(){
		items.clear();
		for (int i = 0; i < counter; i++){
    		delete[] knap[i];
		}
		delete[] knap;
	}

	string file_name;
	vector<Item> items;
	int capacity;
	int ** knap;
	stack<Item> sack;
	int counter;

	//takes a line as a string and the number of the line
	void read_line(string line_, unsigned int line_num){
		string line = line_, 
			   delimiter = ",",
			   token,
			   name;
		int weight_ = 1;
		int value_ = 1;
		int	pos = 0;
		bool not_enough = true;
		while((pos = line.find(delimiter)) != string::npos){
			name = line.substr(0, pos);
			line.erase(0, pos + delimiter.length()); //erases the first word and comma
			if((pos = line.find(delimiter)) == string::npos){ //if there is only two elements and one comma
				cout << "butts"<< endl;
				break;
			}

			token = line.substr(0, line.find(delimiter)); //the second element
			istringstream iss(token);
			if(!(iss >> weight_) || (weight_ < 0)){ //false if the weight isn't a number or less than 0
				ostringstream oss;
				oss << "Error: Invalid weight '" << token << "' on line number " << line_num << ".";
				throw runtime_error(oss.str());
			}
			line.erase(0, pos + 1); //removes the second word and second comma

			if(line.length() == 0){ //if there were only two elements and two commas
				cout << "butts"<< endl;	
				break;
			}
			token = line; //the third element
			istringstream is(token);
			if(!(is >> value_) || (value_ < 0)){ //false if the value isn't a number of it's less than 0
				ostringstream oss;
				oss << "Error: Invalid value '" << token << "' on line number " << line_num << "." ;
				throw runtime_error(oss.str());
			}
			not_enough = false;
			break;
		}
		if(not_enough){
			ostringstream oss;
			oss <<  "Error: Line number " << line_num << " does not contain 3 fields.";
			throw runtime_error(oss.str());
		}
		items.push_back(Item(line_num, (unsigned)weight_, (unsigned)value_, name));
	}

	void print_items(){
		unsigned int total_weight = 0;
		unsigned int total_value = 0;
		cout << "Candidate items to place in knapsack:" << endl;
		for(unsigned int i = 0; i < items.size(); i++){
			cout << "   ";
			cout << items[i] << endl;
		}

		cout << "Capacity: " << capacity << (capacity == 1 ? " pound" : " pounds") << endl;
		cout << "Items to place in knapsack:" << endl;

		while(!sack.empty()){
			cout << "   ";
			cout << sack.top() << endl;
			total_weight += sack.top().weight;
			total_value += sack.top().value;
			sack.pop();
		}
		cout << "Total weight: " << total_weight << (total_weight == 1 ? " pound" : " pounds") << endl;
		cout << "Total value : $" << total_value << endl;
	}

	void print_knapsack(){
		for (unsigned int j = 0; j < items.size()+1; ++j)
		{
			cout << endl;
			for (int i = 0; i < (int)capacity+1; ++i)
			{
				cout << knap[j][i] << " ";
			}
		}
		cout << endl;
	}

	void dynamic(){
		for (unsigned int i = 0; i < items.size(); ++i){
			for (int j = 0; j <= capacity; ++j){
				knap[i][j] = 0;
			}
		}
		for (unsigned int i = 1; i <= items.size(); ++i){
			for (int w = 1; w <= capacity; ++w){
				if((int)items[i-1].weight <= w){
					knap[i][w] = std::max((int)(knap[i-1][w]), (int)(knap[i-1][w-items[i-1].weight] + items[i-1].value));
				}
				else{
					knap[i][w] = knap[i-1][w];
				}
			}
		}
		back_track();
	}

	void back_track(){
		int m = items.size();
		int n = capacity;

		while(m > 0 && n > 0){
			if(knap[m][n] > knap[m-1][n]){
				m = m-1;
				sack.push(items[m]);
				n = n-items[m].weight;
			}
			else{
				m = m-1;
			}
		}
		print_items();
	}
};



int main(int argc, const char *argv[]) {
    // Make sure the right number of command line arguments exist.

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <capacity> <filename>" << endl;
        return 1;
    }
    istringstream iss(argv[1]);
    int cap;
    if(!(iss >> cap) || cap <= 0){
    	cerr << "Error: Bad value '" << argv[1] << "' for capacity." << endl;
    	return 1;
    }
    ifstream input_file(argv[2]);
    // Create an ifstream object.
    // If it does not exist, print an error message.
    if (!input_file) {
        cerr << "Error: Cannot open file '" << argv[2] << "'." << endl;
        return 1;
    }
    string input;
    istringstream issss(argv[2]);
    issss >> input;
    try{
    	Knapsack k(input, cap);
    }
    catch(const exception &e){
    	cerr << e.what() << endl;
    	return 1;
    }
    return 0;
}
