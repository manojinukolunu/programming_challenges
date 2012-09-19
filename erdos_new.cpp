#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <queue>

#define DEBUGMODE 0
#define pdebug(...) do{if(DEBUGMODE)printf(__VA_ARGS__);}while(0)

using namespace std;

vector <string> split(string str);
void printvec(vector<string> sorted);


int main(int argc,char ** argv){
    string start="Erdos, P";
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
        map <string,set<string> > graph;
        map <string,set<string> > :: iterator it;
        do{
            getline(myfile,paper);
            vector<string> authors;
            if (paper!="")
                authors = split(paper);
            int size = authors.size();
            for(int i=0;i<size;i++){
                for(int j=0 ;j<size;j++){
                    if (i!=j){
                        it = graph.find(authors[i]);
                        if(it==graph.end()){
                            graph[authors[i]].insert(authors[j]);
                        }
                        else{
                            (*it).second.insert(authors[j]);
                        }
                    }
                }
            }
            cout << endl;
        }while(P--);


        //now we have the graph find out the paths from erdos to other nodes...

        //Running Breadth first search on the graph with start nodes as "Erdos, P"



        map<string,string> color;
        map<string,int> distance;
        set<string> :: iterator its;

        for(it=graph.begin();it!=graph.end();it++){
            if((*it).first==start){
                continue;
            }
            else{
                color[(*it).first]="WHITE";
                distance[(*it).first] = -1;
            }
        }


        color[start]="BLACK";
        distance[start]=0;
        queue<string> Q;
        Q.push(start);
        while(!Q.empty()){
            string next=Q.front();
            Q.pop();
            for(its=graph[next].begin();its!=graph[next].end();its++){
                if (color[(*its)]=="WHITE"){
                    color[(*its)]="BLACK";
                    distance[(*its)]=distance[next]+1;
                    Q.push((*its));
                }
            }
            color[next]="BLACK";
        }


        #if DEBUGMODE==1
        map<string,int> ::iterator itd;
        for(itd=distance.begin();itd!=distance.end();itd++){
            cout << (*itd).first << "   " <<(*itd).second << endl;
        }
        #endif

    }
}

vector<string> split(string str){
    size_t start = 0;
    size_t found;
    found = str.find(".:");
    str = str.substr(0,found);
    vector <string> subStrings;
    do {
        found = str.find(".,");
        string author= str.substr(0,found);
        author = author.substr(author.find_first_not_of(" "),author.size());
        subStrings.push_back(author);
        str = str.substr(found+2,str.size()-1);
    }while(found!=string::npos);
    return subStrings;
}


void printvec(vector<string> sorted){
    for(int i=0;i<sorted.size();i++){
        cout << sorted[i]<<endl;
    }

}
