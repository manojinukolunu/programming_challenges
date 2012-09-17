#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

#define debug 1

using namespace std;




class dict{
    public:
        vector<string> internaldict;
        void insert(string str);
        vector<string> getStrOnLen(int len);
        void printdict(){
            printvec();
        }
    private:
        void printvec(){
            for(int i=0;i<internaldict.size();i++){
                cout << internaldict[i]<<endl;
            }

}

};

vector<string> dict::getStrOnLen(int length){
    vector <string> strings;
    for(int i=0;i<internaldict.size();i++){
        if (internaldict[i].size()==length){
            strings.push_back(internaldict[i]);
        }
    }
    return strings;
}


void dict::insert(string str){
    if(internaldict.empty()){
        //empty so no need to insert based on length
        internaldict.push_back(str);
    }
    else {
        int strlen=str.size();
        for(int i=0;i<internaldict.size();i++){
            if (strlen>=internaldict[i].size()){
                internaldict.insert(internaldict.begin()+i,str);
                break;
            }
        }
    }
}


bool comp(string s1,string s2);


map<char,char> construct_replacement(vector<string>enc_words,dict *dict){
    map<char,char> replacement;
    map<char,char>:: iterator it;
    bool solution;
    for(int i=0;i<enc_words.size();i++){
        //Now construct the replacement table
        // for every word merging with the previous word
        string currencword=enc_words[i];
        vector<string> dict_word=dict->getStrOnLen(currencword.size());

        if (!dict_word.empty()){
            //pick the first dict word and construct the
            //decoder
            for(int j=0;j<dict_word.size();j++){
                //construct replacement with word;
                string currstr = dict_word[j];
                for(int k=0;k<currencword.size();k++){
                    it = replacement.find(currencword[k]);
                    if(it==replacement.end()){
                        //no problem just add the mapping
                        replacement[currencword[k]]=currstr[k];
                    }
                    else{
                        //if the mapping exists check if the previous mapped one
                        // is matching the current mapped one
                        // otherwise clear the replacement and pick another string.
                        if(replacement[currencword[k]]==(*it).second){
                            continue;
                        }
                        else {
                            replacement.clear();
                            break;
                        }
                    }

                }
            }

        }
        else{
            solution=false;
        }

    }

    if(!solution){
        replacement.clear();
        return replacement;
    }
    else{
        return replacement;
    }

}

int main(int argc,char **argv){
    int dict_length;  // this is the length of the dictionary
	cin >> dict_length;
    string dummy;
    getline(cin,dummy);
    dict *d = new dict;
	while (dict_length--){
	    string word;
        getline(cin,word);
        d->insert(word);
	}
	d->printdict();

	while(1){
	    #ifdef debug
	    cout << " in wile 1 loop" << endl;
	    #endif
		string enc_string;
		getline(cin,enc_string);
		#ifdef debug
		cout << enc_string << endl;
		#endif
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
        cout << "after sorring" << endl;
        map<char,char> replacement=construct_replacement(enc_words,d);
        if (replacement.empty()){
            cout << "No solution";
        }
        else{
            for( map<char,char>::iterator ii=replacement.begin(); ii!=replacement.end(); ++ii){
                cout << (*ii).first << ": " << (*ii).second << endl;
            }
        }

	}
    return 0;
}



bool comp(string s1,string s2){
    return (s1.size()>s2.size());
}
