#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>


#define DEBUGMODE 1
#define pdebug(...) do{if(DEBUGMODE)printf(__VA_ARGS__);}while(0)

using namespace std;

vector <string> split(string str);
void printvec(vector<string> sorted);
string strip(string);

class Author{
    public:
        int number;
        string name;

};
struct ltstr
{
  bool operator()(Author s1, Author s2) const
  {
    return s1.name==s2.name;
  }
};

int main(int argc,char ** argv){
    int scenarios;
    int P,N;
    string dummy;
    string paper;
    ifstream myfile("erdos.txt", ifstream::in);
    myfile >> scenarios;
    myfile >> P;
    myfile >> N;//
    pdebug("Scenarios %d\n P %d\n N %d\n",scenarios,P,N);
    while(scenarios--){
        while(P--){
            getline(myfile,paper);
            vector<string> authors;
            size_t foundErdos;
            foundErdos = paper.find("Erdos");
            //cout << "Paper"<<paper << endl;
            if (paper!="")
                authors = split(paper);
            vector<Author> list;
            if(foundErdos!=string::npos){
                //this means erdos is there in the list of authors
                // set the erdos numbers of the authors to 1
                for (int i=0;i<authors.size();i++){
                    Author A;
                    A.number=1;
                    A.name=authors[i];
                    if (authors[i]!="Erdos, P")
                        list.push_back(A);
                }
            }
            //printvec(authors);

        }
    }
}

vector<string> split(string str){
    size_t start = 0;
    size_t found;
    found = str.find(".:");
    //cout << found << endl;
    str = str.substr(0,found);
    vector <string> subStrings;
    do {
        found = str.find(".,");
        //cout << found << endl;
        //cout << str.substr(0,found) << endl
        string author= str.substr(0,found);
        author = author.substr(author.find_first_not_of(" "),author.size());
        subStrings.push_back(author);
        str = str.substr(found+2,str.size()-1);
        //cout << str << endl;
    }while(found!=string::npos);
    return subStrings;
}


void printvec(vector<string> sorted){
    for(int i=0;i<sorted.size();i++){
        cout << sorted[i]<<endl;
    }

}

string strip(string str){


}


