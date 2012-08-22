#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main(int argc,char ** argv){

	string test;
	getline(cin,test);
	istringstream iss(test);
	vector<string> black,white;
	int count=1;
	while( iss){
		count++;
		string s;
		iss >> s;
		if(count==5){
			white.push_back(s);
		}
		else {
			black.push_back(s);
		}
	}
	return 0;
}
