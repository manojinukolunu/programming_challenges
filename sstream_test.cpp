#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main(int argc,char ** argv){
	string test;
	getline(cin,test);
	istringstream iss(test);
	
	int n;
	
	while( iss >> n){
		cout << n << endl;
		}
		
		}