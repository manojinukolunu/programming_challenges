#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc,char ** argv){
	int testcases;
	string dummy;
	
	cin >> testcases;

	getline(cin,dummy); // for the blank line that follows after
	getline(cin,dummy);

	while(testcases--){
		int numcandidates;
		cin >> numcandidates;
		while(numcandidates--){
			vector<string> candidates;
			string candidate;
			cin >> candidate;
			candidates.push_back(candidate);
		}
		//now we have all the candidates
		cout << "Here" <<endl;
		vector<vector<int> > ballots;
		getline(cin,dummy);
		for(int i=0;i<1000;i++){
			vector <int> temp;
			int tempints;
			string ballot;
			getline(cin,ballot);

			if (ballot==""){
				cout<< "empty ballot";
				break;

			}

			istringstream iss(ballot);
			while( iss >> tempints)
				temp.push_back(tempints);
			ballots.push_back(temp);
		}
		//now we have the contents of each ballot in the 
		//2d arrat ballots 
		//
		for(int i=0;i<ballots.size();i++){
			for (int j=0;j<ballots[i].size();j++){
				cout <<ballots[i][j];
			}
			cout<< endl;
		}
	}
}

