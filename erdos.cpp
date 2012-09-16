#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>



using namespace std;

class Node{
    public:


};























int main(int argc,char **argv){
    int scenarios;
    //cin >> scenarios;
    int P,N;
    //c/in >> P;
    //cin >> N;
    string dummy;
    string paper;
    vector<string> authors;

    ifstream myfile("erdos.txt", ifstream::in);

    myfile >> scenarios;
    myfile >> P;
    myfile >> N;
    cout << scenarios<<endl;
    cout << P << endl <<N<<endl;
    while(scenarios--){
        while(P--){
            getline(myfile,paper);
            string author="";
                int countcommas=0;
                stringstream stream(paper);
                string word;
                while(getline(stream,word,',')){
                    cout << word << endl;
                }


            for(int i=0;i<paper.size();i++){
                if(paper[i]==','){
                    countcommas++;
                }
            }
            // now paper contains the paper and author info

        }
    }


}
