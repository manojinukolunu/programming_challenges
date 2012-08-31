#include <iostream>
#include <string>

using namespace std;

int main(){
    string st="--23456789TJQKA";
    char c='T';
    string str(1,c);
    cout <<str<<endl;
    cout << st.find(str);


}
