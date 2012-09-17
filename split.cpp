#include <string>
#include <iostream>
#include <vector>

using namespace std;


vector<string> split(string str,string delim);

int main(int argc, char ** argv){

    vector<string> test=split("Smith, M.N., Martin, G., Erdos, P.: Newtonian forms of prime factors",".,");


}

vector<string> split(string str,string delim){
    int start=0;
    vector<string> splitstrings;
    size_t found;
    do{
        found=str.find(delim);
        cout << found << endl;
        str=str.substr(found+=2);
        cout << str << endl;
    }while(found!=string::npos);

    return splitstrings;

}
