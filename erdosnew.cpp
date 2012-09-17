#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>

#define DEBUGMODE 1
#define pdebug(...) do{if(DEBUGMODE)printf(__VA_ARGS__);}while(0)


using namespace std;

class Author{
    public :
        int erdosnumber;
        string name;


};

vector<string> split(string str);

int main(int argc,char ** argv){
    int scenarios;
    int P,N;
    string dummy;
    string paper;
    vector<string> authors;
    ifstream myfile("erdos.txt", ifstream::in);
    myfile >> scenarios;
    myfile >> P;
    myfile >> N;
    pdebug("Scenarios %d\n P %d\n N %d\n",scenarios,P,N);
    while(scenarios--){
        while(P--){
            getline(myfile,paper);
            string author="";
            stringstream stream(paper);
            string word;
            if (paper.find("Erdos")!=string::npos){
                //this means there is erdos in this paper
                while(getline(paper,word,',')){


                }

            }

        }


    }
}


vector<string> split(string str){
}


