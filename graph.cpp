#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc,char ** argv){
    const  char * buff[]={"Smith","erdos","chen"};
    vector<string> authors(buff,buff+3);
    for(int i=0;i<authors.size();i++){
        for(int j=0;j<i;j++){
            cout << i << "   "<<j<< "   ";
        }
        cout << endl;
    }

}
void printmap(map<string,vector<string> > m){
    map<string,vector<string> > :: iterator it;
    for(it = m.begin();it!=m.end();it++){
        for(int i=0;i < (*it).second.size();i++){
            cout << (*it).first << "  " <<(*it).second[i];
        }
        cout << endl;
    }


}
