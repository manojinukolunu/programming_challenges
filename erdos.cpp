#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>

#define DEBUGMODE 1
#define pdebug(...) do{if(DEBUGMODE)printf(__VA_ARGS__);}while(0)

using namespace std;
class Node{
    public:
        string nodeName;
        Node(string name);
        vector<string> neighbours;
        void addNeighbours(string neighbour);

};


Node:: Node(string name){
    nodeName=name;
}


void Node::addNeighbours(string neighbour){
    neighbours.push_back(neighbour);

}



class Graph{
    public:
        vector<Node *> nodes;
        void addNode(Node *node);
        void printGraph(){
            for(int i=0;i<nodes.size();i++){
                cout << "NOde Name" << nodes[i]->nodeName <<endl;
            }

        }

};
void Graph::addNode(Node *node){
    nodes.push_back(node);
}


int main(int argc,char **argv){
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
        Graph * graph = new Graph;
        while(P--){
            getline(myfile,paper);
            string author="";
            stringstream stream(paper);
            string word;
            char * st=new char[paper.size()+1];
            strcpy(st,paper.c_str());
            char * pch= strtok(st,".,");
            while(pch!=NULL){
                cout << pch << endl;
                pch=strtok(NULL,"");
            }
            delete []st;
            cout << endl<<endl;
            // now paper contains the paper and author info
        }
        //now we have the graph
        //check for connectivity and

        //graph->printGraph();
    }


}
