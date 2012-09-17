/*
 * =====================================================================================
 *
 *       Filename:  jolly_jumpers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/18/2012 09:17:48 PM
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
#include <stack>
#include <cmath>

using namespace std;


int main(int argc,char **argv){
	int numintegers;
	cin >> numintegers;
	if (numintegers >3000){
		return 0;
	}
	cout << "Num integers" << numintegers <<endl;
	int first,second,current_absdiff,previous_absdiff;
	numintegers-=1;
	cin >> first;
	cin >> second;
	cout << "First "<< first << endl;
	cout << "second " << second << endl;
	current_absdiff=abs(second-first);
	cout << "Current abs diff outside loop" << current_absdiff << endl;
	bool jolly=true;
	numintegers-=1;
	while(numintegers--){
		previous_absdiff=current_absdiff;
		cout << "Previous abs diff" << previous_absdiff << endl;
		first = second;
		cin >> second;
		cout << "First "<< first << endl;
		cout << "second " << second << endl;
		current_absdiff=abs(first-second);
		cout << "Current abs diff in while loop" << current_absdiff << endl;
		if (!(current_absdiff==previous_absdiff || current_absdiff==previous_absdiff-1)){
			jolly=false;
			break;
		}
	}
	if (jolly){
		cout << "Jolly" << endl;

	}
	else 
		cout << "Not jolly " << endl;
}
