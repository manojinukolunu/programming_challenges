#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

struct letter_replacement{
    char letter;
    char letter_replacement;
};
bool comp(string s1,string s2);
map<char,char>construct_replacement(vector<string>,vector<string>);

vector<string> sort(vector<string>);
void printvec(vector<string>);

int main(int argc,char ** argv){
	int dict_length;  // this is the length of the dictionary
	cin >> dict_length;
    string dummy;
    getline(cin,dummy);
	vector<string> dict;//this is the dictionary
	while (dict_length--){
	    string word;
        getline(cin,word);
        dict.push_back(word);
	}
	sort(dict.begin(),dict.end(),comp);
	printvec(dict);
	// now we have the dictionary..
	while(1){
	    cout << " in wile 1 loop" << endl;
		string enc_string;
		getline(cin,enc_string);
		cout << enc_string << endl;
        vector<string> enc_words;
        istringstream iss(enc_string);
        while(iss){
            string s;
            iss>>s;
            enc_words.push_back(s);
        }
        cout << "after enc_words " << endl;
        sort(enc_words.begin(),enc_words.end(),comp);
        //now enc_words has all the encrypted words in a sorted order
        map<char,char> replacement=construct_replacement(enc_words,dict);
         for( map<char,char>::iterator ii=replacement.begin(); ii!=replacement.end(); ++ii)
        {
            cout << (*ii).first << ": " << (*ii).second << endl;
        }
        printvec(enc_words);
	}
}

map<char,char> construct_replacement(vector<string>enc_words,vector<string>dict){
    map<char,char> replacement;
     map<char,char>::iterator it;
    for (int i=0;i<enc_words.size();i++){
        // start with the longest word in the
        //encrypted text and match with the dictionary
        if(enc_words[i].size()!=dict[i].size()){
            break;
        }
        else{
            for(int j=0;j<dict[i].size();j++){
                it=replacement.find(dict[i][j]);
                if (it==replacement.end())
                    replacement[dict[i][j]]=enc_words[i][j];
            }
        }
    }

    return replacement;

}

bool comp(string s1,string s2){
    return (s1.size()>s2.size());
}

void printvec(vector<string> sorted){
    for(int i=0;i<sorted.size();i++){
        cout << sorted[i]<<endl;
    }

}


