/*******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Author      : Michael John
 * Date        : The ninth day of the tenth month in the year two-thousand and fourteen.
 * Description : Provides moves to achieve a goal state with three jugs of water with various volumes.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class State{
public:
	vector<string> v;
	State(int x, int y, int z): a(x), b(y), c(z){
	}
	~State(){
		v.clear();
	}
	int get_a(){
		return a;
	}
	int get_b(){
		return b;
	}
	int get_c(){
		return c;
	}
	void set_a(int q){
		a = q;
	}
	void set_b(int w){
		b = w;
	}
	void set_c(int e){
		c = e;
	}
	void push_data(int a, int b, int c){
		stringstream (ss1);
		ss1 << a;
		string str1 = ss1.str();
		stringstream (ss2);
		ss2 << b;
		string str2 = ss2.str();
		stringstream (ss3);
		ss3 << c;
		string str3 = ss3.str();
		v.push_back("(" +str1+ ", " +str2+ ", " +str3+ ")\n");
	}
	void print_data(){
		for(unsigned int it = 0; it < v.size(); ++it){
			cout << v[it]; 
		}
		cout << "(" << a << ", " << b << ", " << c << ")";
	}

private:
	int a, b, c;
};
void main_function(int c);
void the_function(bool** visited);
bool** visited;
queue <State> q;
State goal(0,0,0);
int capA = 0;
int capB = 0;
int capC = 0;

void intro(int a, int b, int c, int d, int e, int f){
	State the_start(0,0,c);
	the_start.v.push_back("Initial state. ");
	goal.set_a(d);
	goal.set_b(e);
	goal.set_c(f);
	capA = a;
	capB = b;
	capC = c;
	if(the_start.get_a() == goal.get_a() && the_start.get_b() == goal.get_b()){
		the_start.print_data();
	}
	else{
		q.push(the_start);
		main_function(c);
	}
}

void main_function(int c){
	visited = new bool*[c+1];
	for(int i = 0; i < c+1; ++i){
		visited[i] = new bool[c+1];
		for (int j = 0; j < c+1; ++j){
			visited[i][j] = false;
		}
	}
	the_function(visited);
	for(int i = 0; i< c+1; i++){
		delete[] visited[i];
	}
	delete [] visited;
}

void the_function(bool** visited){
	int help = 0;
	int x = 0;
	while(q.size() != 0){
		//q.front().print_data();
		if((q.front().get_a() == goal.get_a() && q.front().get_b() == goal.get_b())){
			q.front().print_data();
			x = 1;
		}
		if(q.front().get_c() != 0 && q.front().get_a() != capA){ //1
			help = capA - q.front().get_a();
			if(help > q.front().get_c()){
				help = q.front().get_c();
			}
			if(!(visited[help + q.front().get_a()][q.front().get_b()])){
				visited[help + q.front().get_a()][q.front().get_b()] = true;
				State tom(help+q.front().get_a(), q.front().get_b(), q.front().get_c() - help);
				for(unsigned int i = 0; i < q.front().v.size(); ++i){
					tom.v.push_back(q.front().v[i]);
				}
				tom.push_data(q.front().get_a(), q.front().get_b(), q.front().get_c());
				stringstream (ss);
				ss << help;
				string str = ss.str();
				tom.v.push_back("Pour " +str+ ((help > 1)? " gallons" : " gallon") + " from C to A. ");
				q.push(tom);
				//cout << "1"<< endl;
			}
		}
		if(q.front().get_b() != 0 && q.front().get_a() != capA){ //2
			help = capA - q.front().get_a();
			if(help > q.front().get_b()){
				help = q.front().get_b();
			}
			if(!(visited[help + q.front().get_a()][q.front().get_b() - help])){
				visited[help + q.front().get_a()][q.front().get_b() - help] = true;
				State tom(help + q.front().get_a(), q.front().get_b() - help, q.front().get_c());
				for(unsigned int i = 0; i < q.front().v.size(); ++i){
					tom.v.push_back(q.front().v[i]);
				}
				tom.push_data(q.front().get_a(), q.front().get_b(), q.front().get_c());
				stringstream (ss11);
				ss11 << help;
				string str11 = ss11.str();
				tom.v.push_back("Pour " +str11+ ((help > 1)? " gallons" : " gallon") +" from B to A. ");
				q.push(tom);
				//cout << "2"<< endl;
			}
		}
		if(q.front().get_c() != 0 && q.front().get_b() != capB){ //3
			help = capB - q.front().get_b();
			if(help > q.front().get_c()){
				help = q.front().get_c();
			}
			if(!(visited[q.front().get_a()][q.front().get_b() + help])){
				visited[q.front().get_a()][q.front().get_b() + help] = true;
				State tom(q.front().get_a(), q.front().get_b()+help, q.front().get_c()-help);
				for(unsigned int i = 0; i < q.front().v.size(); ++i){
					tom.v.push_back(q.front().v[i]);
				}
				tom.push_data(q.front().get_a(), q.front().get_b(), q.front().get_c());
				stringstream (ss12);
				ss12 << help;
				string str12 = ss12.str();
				tom.v.push_back("Pour " +str12+ ((help > 1)? " gallons" : " gallon") + " from C to B. ");
				q.push(tom);
				//cout << "3"<< endl;
			}
		}
		if(q.front().get_a() != 0 && q.front().get_b() != capB){ //4
			help = capB - q.front().get_b();
			if(help > q.front().get_a()){
				help = q.front().get_a();
			}
			if(!(visited[q.front().get_a() - help][q.front().get_b() + help])){
				visited[q.front().get_a()-help][q.front().get_b() + help] = true;
				State tom(q.front().get_a()-help, q.front().get_b()+help, q.front().get_c());
				for(unsigned int i = 0; i < q.front().v.size(); ++i){
					tom.v.push_back(q.front().v[i]);
				}
				tom.push_data(q.front().get_a(), q.front().get_b(), q.front().get_c());
				stringstream (ss13);
				ss13 << help;
				string str13 = ss13.str();
				tom.v.push_back("Pour " +str13+ ((help > 1)? " gallons" : " gallon") + " from A to B. ");
				q.push(tom);
				//cout << "4"<< endl;
			}
		}
		if(q.front().get_b() != 0 && q.front().get_c() != capC){ //5
			help = capC - q.front().get_c();
			if(help > q.front().get_b()){
				help = q.front().get_b();
			}
			if(!(visited[q.front().get_a()][q.front().get_b() - help])){
				visited[q.front().get_a()][q.front().get_b() - help] = true;
				State tom(q.front().get_a(), q.front().get_b()-help, q.front().get_c()+help);
				for(unsigned int i = 0; i < q.front().v.size(); ++i){
					tom.v.push_back(q.front().v[i]);
				}
				tom.push_data(q.front().get_a(), q.front().get_b(), q.front().get_c());
				stringstream (ss112);
				ss112 << help;
				string str112 = ss112.str();
				tom.v.push_back("Pour " +str112+ ((help > 1)? " gallons" : " gallon") + " from B to C. ");
				q.push(tom);
				//cout << "5"<< endl;
			}
		}
		if(q.front().get_a() != 0 && q.front().get_c() != capC){ //6
			int help = capC - q.front().get_c();
			if(help > q.front().get_a()){
				help = q.front().get_a();
			}
			if(!(visited[q.front().get_a() - help][q.front().get_b()])){
				visited[q.front().get_a() - help][q.front().get_b()] = true;
				State tom(q.front().get_a()-help, q.front().get_b(), q.front().get_c()+help);
				for(unsigned int i = 0; i < q.front().v.size(); ++i){
					tom.v.push_back(q.front().v[i]);
				}
				tom.push_data(q.front().get_a(), q.front().get_b(), q.front().get_c());
				stringstream (ss123);
				ss123 << help;
				string str123 = ss123.str();
				tom.v.push_back("Pour " +str123+ ((help > 1)? " gallons" : " gallon") + " from A to C. ");
				q.push(tom);
				//cout << "6"<< endl;
			}
		}
		q.pop();
	}
	if(x <= 0){
		cout << "No solution." << endl;
	}
}


int error_help(char * const arg, string cap_goal, string letter){
	istringstream iss(arg);
	int value;
	if(!(iss >> value)){
		cerr << "Error: Invalid " << cap_goal << " '" << arg << "' " << "for jug " << letter << "." << endl;
		return 1;
	}
	if(value < 0){
		cerr << "Error: Invalid " << cap_goal << " '" << arg << "' " << "for jug " << letter << "." << endl;
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char * const argv[]) {
    if(argc != 7){  //error checks to ensure exactly one argument was passed
        cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
        return 0;
    }

    istringstream iss(argv[3]);
	int value;
	if(!(iss >> value)){
		if(value == 0){
			cerr << "Error: Invalid capacity '0' for jug C." << endl;
			return 0;
		}
	}

   	if(	error_help(argv[1], "capacity", "A") +
   		error_help(argv[2], "capacity", "B") +
   		error_help(argv[3], "capacity", "C") +
   		error_help(argv[4], "goal", "A") +
   		error_help(argv[5], "goal", "B") +
   		error_help(argv[6], "goal", "C") > 0){
   		return 0;
   	}

   	istringstream c(argv[3]);
   	istringstream x(argv[4]);
   	istringstream y(argv[5]);
   	istringstream z(argv[6]);
   	int q,w,e,r,t,u;
   	if((c >> q) && (x >> w) && (y >> e) && (z >> r)){
   		if(q == 0){
   			cerr << "Error: Invalid capacity '0' for jug C." << endl;
   			return 0;
   		}
    	if(q != w+e+r){
    		cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
    		return 0;
    	}
    }
    istringstream a(argv[1]);
   	istringstream s(argv[2]);
   	istringstream d(argv[3]);
   	istringstream f(argv[4]);
   	istringstream g(argv[5]);
   	istringstream h(argv[6]);
   	if((a >> q) && (s >> w) && (d >> e) && (f >> r) && (g >> t) && (h >> u)){
   		intro(q,w,e,r,t,u);
   	}

    return 0;
}
