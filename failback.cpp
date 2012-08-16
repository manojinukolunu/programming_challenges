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

void check(char [][8]);
void print_board(char [][8]);
bool _check(char [][8],int ,int,char);
bool check_left(char [][8],int,int,char);
bool check_right(char [][8],int ,int ,char);
bool check_top(char [][8],int ,int ,char);
bool check_bottom(char [][8] ,int ,int ,char);
bool check_left_top(char [][8],int ,int ,char);
bool check_right_top(char [][8],int ,int,char);
bool check_left_bottom(char[][8],int ,int,char);
bool check_right_bottom(char [][8],int ,int ,char);




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

	//now we have the board check if the king is in check
	
	check(board);

	}
	
	return 0;
	
}

void  check(char board[][8] ){
	//find the position of both kings first
	
	int black_row,black_column,white_row,white_column;
	for(int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (board[i][j]=='k'){//looking for black king first
				black_row=i;
				black_column=j;
			}
			if (board[i][j]=='K'){
				white_row=i;
				white_column=j;
			}
		}
	}
	//now we have both the black and white kings position
	//check if they are in check.
	
	if(_check(board,black_row,black_column,'b')){
		cout << "Black King is in Check" <<endl;
		
	}
	else if(_check(board,white_row,white_column,'w')){
		cout << "White King is in Check " << endl;
	}

}

void print_board(char board[][8]){
	for(int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			cout << board[i][j];
		}
	}
}

bool _check(char board[][8],int row,int column,char type){
	if (type=='b'){
		//we are checking if the black king is in check

		if(check_left(board,row,column,type)){
			return true;
		}
		if (check_right(board,row,column,type)){
			return true;
		}
		if (check_top(board,row,column,type)){
			return true;
		}
		if (check_bottom(board,row,column,type)){
			return true;
		}
		if (check_left_top(board,row,column,type)){
			return true;
		}
		if (check_right_top(board,row,column,type)){
			return true;
		}
		if (check_left_bottom(board,row,column,type)){
			return true;
		}
		if (check_right_bottom(board,row,column,type)){
			return true;
		}
	}
	if (type=='w'){
		//we are checking if the black king is in check

		if(check_left(board,row,column,type)){
			return true;
		}
		if (check_right(board,row,column,type)){
			return true;
		}
		if (check_top(board,row,column,type)){
			return true;
		}
		if (check_bottom(board,row,column,type)){
			return true;
		}
		if (check_left_top(board,row,column,type)){
			return true;
		}
		if (check_right_top(board,row,column,type)){
			return true;
		}
		if (check_left_bottom(board,row,column,type)){
			return true;
		}
		if (check_right_bottom(board,row,column,type)){
			return true;
		}
	}
	return true;
}
//check the left side of the king for check mates from white pieces
bool check_left(char board[][8],int row,int column,char type){
	//checking if the king is in check from the left row
	if (type=='b'){
		//black king will face white pieces
		
		if (column-1>=0){
			if (board[row][column-1]=='K'){
				//this means there is a white king beside the black king towards the left
				return true;
			}
		}
		
		for (int i=column;i>=0;i--){
			if (board[row][i]=='.'){
				continue;
			}
			else if(board[row][i]!='Q' || board[row][i]!='R'){
				return false;
			}
			else {
				return true;
			}
			
		}
	}
	else if (type=='w'){
		//white king will face black pieces
		
		if (column-1>0){
			if (board[row][column-1]=='k'){
				//this means there is a black king beside the white king towards the left
				return true;
			}
		}
		
		for (int i=column;i>=0;i--){
			if (board[row][i]=='.'){
				continue;
			}
			else if(board[row][i]!='q' || board[row][i]!='r'){
				return false;
			}
			else {
				return true;
			}
			
		}
	}
}

bool check_right(char board[][8],int row,int column,char type){
		if (type=='b'){
		//black king will face white pieces
		if (column+1<8){
			if (board[row][column+1]=='K'){
				//this means there is a white king beside the black king towards the left
				return true;
			}
		}
		for (int i=column;i<8;i++){
			if (board[row][i]=='.'){
				continue;
			}
			else if(board[row][i]!='Q' || board[row][i]!='R'){
				return false;
			}
			else {
				return true;
			}
		}
	}
	else if (type=='w'){
		//white king will face black pieces
		if (column+1<8){
			if (board[row][column+1]=='k'){
				//this means there is a black king beside the white king towards the left
				return true;
			}
		}
		for (int i=column;i<8;i++){
			if (board[row][i]=='.'){
				continue;
			}
			else if(board[row][i]!='q' || board[row][i]!='r'){
				return false;
			}
			else {
				return true;
			}
		}
	}
}
bool check_top(char board[][8] ,int row,int column,char type){
	if (type=='b'){
		//black king will face white pieces
		if (row-1>=0){
			if (board[row-1][column]=='K'){
				//this means there is a white king beside the black king towards the left
				return true;
			}
		}
		for (int i=row;i>=0;i--){
			if (board[i][column]=='.'){
				continue;
			}
			else if(board[i][column]!='Q' || board[i][column]!='R'){
				return false;
			}
			else {
				return true;
			}
		}
	}
	else if (type=='w'){
		//white king will face black pieces
		if (row-1>=0){
			if (board[row-1][column]=='k'){
				//this means there is a black king beside the white king towards the left
				return true;
			}
		}
		for (int i=row;i>=0;i--){
			if (board[i][column]=='.'){
				continue;
			}
			else if(board[i][column]!='q' || board[i][column]!='r'){
				return false;
			}
			else {
				return true;
			}
		}
	}
	return true;
}

bool check_bottom(char board[][8] , int row,int column,char type){
	if (type=='b'){
		//black king will face white pieces
		if (row+1<8){
			if (board[row+1][column]=='K'){
				//this means there is a white king beside the black king towards the left
				return true;
			}
		}
		for (int i=row;i<8;i++){
			if (board[i][column]=='.'){
				continue;
			}
			else if(board[i][column]!='Q' || board[i][column]!='R'){
				return false;
			}
			else {
				return true;
			}
		}
	}
	else if (type=='w'){
		//white king will face black pieces
		if (row+1<8){
			if (board[row+1][column]=='k'){
				//this means there is a black king beside the white king towards the left
				return true;
			}
		}
		for (int i=row;i<8;i++){
			if (board[i][column]=='.'){
				continue;
			}
			else if(board[i][column]!='q' || board[i][column]!='r'){
				return false;
			}
			else {
				return true;
			}
		}
	}

}

bool check_left_top(char board[][8] ,int row,int column,char type){
	if (type=='b'){
		//we check for white pieces checking the black king
		if (row-1>=0 || column-1 >=0){
			if (board[row-1][column-1]=='K' || board[row-1][column-1]=='B' || board[row-1][column-1]=='Q'){
				//we have a checkmate
				return true;
			}
		}
		for (int i=row,j=column;i>=0,j>=0;i--,j--){
			if (board[i][j]=='.'){
				continue;
			}
			else if(board[i][j]!='B' || board[i][j]!='Q'){
				return false;
			}
			else{
				return true;
			}
		}
	}
	else if (type=='w'){
		if (row-1 >=0 && column-1>=0){
			if (board[row-1][column-1]=='k' || board[row-1][column-1]=='b' || board[row-1][column-1]=='q' || board[row-1][column-1]=='p'){
				//checkmate white

				return true;
			}
			
		}
		for (int i=row,j=column;i>=0,j>=0;i--,j--){
			if (board[i][j]=='.'){
				continue;
			}
			else if(board[i][j]!='b' || board[i][j]!='q'){
				return false;
			}
			else {
				return true;
			}	
		}

	}
}
bool check_left_bottom(char board[][8] ,int row,int column,char type){
	return true;
}
bool check_right_top(char board[][8],int row,int column,char type){
	return true;
}
bool check_right_bottom(char board[][8],int row,int column,char type){
	return true;
}



