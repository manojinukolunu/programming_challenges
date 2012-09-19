#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;


class submission{
    public:
        int contestant;
        int problem_number;
        int time;
        char L;
        bool operator <(const submission& s1){
            if(L=='C'){
                return
            }
            return true;
        }
};

int main(int argc,char ** argv){
    int number_of_testcases;
    string dummy;
    cin >> number_of_testcases;
    //the following because cin doesnt read the trailing newline at the end.
    getline(cin,dummy);
    getline(cin,dummy);
    vector<submission> submissions;
    while(number_of_testcases--){
        while(1){
            getline(cin,dummy);
            if(dummy==""){
                break;
            }
            istringstream iss(dummy);
            submission s;
            iss >> s.contestant;
            iss >> s.problem_number;
            iss >> s.time;
            iss >> s.L;
            submissions.push_back(s);
        }
        for(int i=0;i<submissions.size();i++){
            cout << submissions[i].contestant << " " << submissions[i].problem_number << " " << submissions[i].L << endl;
        }

    }

    return 0;
}

