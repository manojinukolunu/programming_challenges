#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(int argc,char ** argv){
	int dict_length;
	cin >> dict_length;
	while (dict_length--){
		vector<string> dict;
		string word;
		getline(cin,word);
		dict.push_back(word);
	}
	while(1){
		string dec_string;
		getline(cin,dec_string);
		