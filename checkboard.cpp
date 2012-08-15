/*
 * =====================================================================================
 *
 *       Filename:  checkboard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/16/2012 12:50:47 AM
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
#include <vector>
#include <string>
using namespace std;


int main(int argc,char ** argv){
	char board[8][8];// input is direct 8x8 already known
	string dummy;
	while (1){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cin >> board[i][j];
				}
			}
		
	getline(cin,dummy);
	getline(cin,dummy);
	//now we have the chess board check if the king is in check
	int count=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8; j++){
			if (board[i][j]=='.'){
				count++;
			}
		}
	}
	if (count == 64){
		break;
	}
	}
	
	return 0;
	
}
