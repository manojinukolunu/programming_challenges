/*
 * =====================================================================================
 *
 *       Filename:  interpreter.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2012 09:39:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

int execute(vector<int> *, vector<int> *);



int main(int argc,char ** argv){
	string dummy;
	int testcases;
	cin >> testcases ;
	//two are required because of 2 new lines???
	getline(cin,dummy);
	getline(cin,dummy);// for the emptly line that follows the testcases
	while (testcases--){
		vector<int> ram(1000) , registers(10) ;
		fill(ram.begin(),ram.end(),0);
		fill(registers.begin(),registers.end(),0);
		for (int i=0;i<1000;i++){
			string instruction;
			getline(cin,instruction);
			if (instruction==""){
				break;
			}
			istringstream iss(instruction);
			iss>>ram.at(i);
		}
			cout << execute(&ram,&registers);
	}
	


	return 0;
}


//returns the total number of instructions executed
int execute(vector<int> * ram1, vector<int> * registers1){
	vector<int> ram=*ram1;
	vector<int> registers=*registers1;
	int count=1;
	int i=0;
	while (1){
		int inst=ram.at(i);
		int first=inst/100;
		int second =(inst%100)/10;
		int third = inst % 10;
		

		cout<<"First" <<first<<endl<<"Second "<<second<<endl<<"Third "<<third<<endl;
		switch (first){
			case 1:
				return count;
				break;
			case 2:
				registers.at(second)=third;
				count++;
				i++;
				break;
			case 3:
				registers.at(second)+=third;
				registers.at(second)%=1000;
				count++;
				i++;
				break;
			case 4:
				registers.at(second)*=third;
				registers.at(second)%=1000;
				count++;
				i++;
				break;
			case 5:
				registers.at(second)=registers.at(third);
				count++;
				i++;
				break;
			case 6:
				registers.at(second)+=registers.at(third);
				registers.at(second)%=1000;
				count++;
				i++;
				break;
			case 7:
				registers.at(second)*=registers.at(third);
				registers.at(second)%=1000;
				count++;
				i++;
				break;
			case 8:
				registers.at(second)=ram.at(registers.at(third));
				count++;
				i++;
				break;
			case 9:
				ram.at(registers.at(third))=registers.at(second);
				count++;
				i++;
				break;
			case 0:
				if (registers.at(third)==0){
					i++;
				}else{
					i=registers.at(second);
				}
				count++;
				break;
			default:
				return -1;
				break;

		}

	}
	return 0;
}








