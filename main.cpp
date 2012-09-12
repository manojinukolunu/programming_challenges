#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int dictionary_length;
    cin >> dictionary_length;
    vector<string> dictionary;
    while(dictionary_length--){
        string dic_word;
        getline(cin,dic_word);
        dictionary.push_back(dic_word);
        cout << dic_word;
    }

    cout << "Hello World!" << endl;
    return 0;
}

