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
void print_vec(vector<char>);



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
	if(_check(board,black_row,black_column,'w')){
		cout << "White  King is in Check" <<endl;
		
	}
	

}

void print_board(char board[][8]){
	for(int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			cout << board[i][j];
		}
	}
}

void print_vec(vector<char> vec){
	for (int i=0;i<vec.size();i++){
		cout<< vec[i] << " ";
	}
}

bool _check(char board[8][8],int row,int column,char type){
	//now extract the left,right,top,bottom and both diagnols for the king
	//
	
	vector<char> left,right,top,bottom,left_top_diag,right_top_diag,left_bottom_diag,right_bottom_diag;
	//left side of the king 
	for(int i=column-1;i>=0;i--){
		left.push_back(board[row][i]);
	}
	cout<<"left side of the king";
	print_vec(left);
	cout <<endl;
	//right side of the king
	for(int i=column+1;i<8;i++){
		right.push_back(board[row][i]);
	}
	cout<<"right side of the king";
	print_vec(right);
	cout<<endl;
	//top side of the king
	for (int i=row-1;i>=0;i--){
		top.push_back(board[i][column]);
	}	
	cout<<"top side of the king";
	print_vec(top);
	cout<<endl;
	//bottom side of the king
	for(int i=row+1;i<8;i++){
		bottom.push_back(board[i][column]);
	}
	cout<<"bottom side of the king";
	print_vec(bottom);
	cout<<endl;
	//left upper diagnol to the king
	for(int i=row-1,j=column-1;i>=0,j>=0;i--,j--){
		left_top_diag.push_back(board[i][j]);

	}
	cout<<"left upper diagnol to the king";
	print_vec(left_top_diag);
	cout<<endl;

	//right upper diagnol to the king

	for (int i=row-1,j=column+1;i<8,j<8;i--,j++){
		right_top_diag.push_back(board[i][j]);
	}
	cout<<"right top diagnol to the king";
	print_vec(right_top_diag);
	cout<<endl;

	//left bottom diagnol to the king
	for (int i=row+1,j=column-1;i<8,j>=0;i++,j--){
		left_bottom_diag.push_back(board[i][j]);
	}
	cout<<"left bottom diagnol to the king";
	print_vec(left_bottom_diag);
	cout<<endl;

	//right bottom diagnol to the king
	for (int i=row+1,j=column+1;i<8,j<8;i++,j++){
		right_bottom_diag.push_back(board[i][j]);
	}
	cout<<"right bottom diagnol to the king";
	print_vec(right_bottom_diag);
	cout<<endl;

	//now look at the beginning elements of the vecotors 
	//first check the left side for opposing rook,queen
	if (type=='b'){
		bool check;
		cout<<"in type b"<<endl;
		//check left
		if (!left.empty())
		for(int i=0;i<left.size();i++){
		if (left[0]=='K')
			return true;
			if (left[i]=='.'){
				continue;
			}
			else if( left[i]=='R' || left[i]=='Q')
				return true;
			else 
				check= false;
		}
		//check right
		if (!right.empty())
		for(int i=0;i<right.size();i++){
		if (right[0]=='K')
			return true;
			if(right[i]=='.')
				continue;
			else if(right[i]=='R' || right[i]=='Q')
				return true;
			else 
				check= false;
		}
		//check top
		if (!top.empty())
		for (int i=0;i<top.size();i++){
		if (top[0]=='K')
			return true;
			if (top[i]=='.')
				continue;
			else if(top[i]=='R' || top[i]=='Q')
				return true;
			else
				check= false;
		}
		//check bottom
		if(!bottom.empty())
		for (int i=0;i<bottom.size();i++){
		if (bottom[0]=='K')
			return true;
			if (bottom[i]=='.')
				continue;
			else if(bottom[i]=='R' || bottom[i]=='Q')
				return true;
			else 
				check=false;

		}
		//check left upper diagnol
		if(!left_top_diag.empty())
		for (int i=0;i<left_top_diag.size();i++){
		if (left_top_diag[0]=='K')
			return true;
			if (left_top_diag[i]=='.')
				continue;
			else if (left_top_diag[i]=='B' || left_top_diag[i]=='Q')
				return true;
			else 
				check= false;
		}

		//check right upper diagnol
		if(!right_top_diag.empty())
		for (int i=0;i<right_top_diag.size();i++){
		if (right_top_diag[0]=='K')
			return true;
			if (right_top_diag[i]=='.')
				continue;
			else if(right_top_diag[i]=='B'||left_top_diag[i]=='Q')
				return true;
			else 
				check= false;
		}

		//check lower left diagnol here we have to chec for white pawn as well
		if (!left_bottom_diag.empty())
		for(int i=0;i<left_bottom_diag.size();i++){
		if (left_bottom_diag[0]=='K' || left_bottom_diag[0]=='P')
			return true;
			if (left_bottom_diag[i]=='.')
				continue;
			else if (left_bottom_diag[i]=='B' || left_bottom_diag[i]=='Q')
				return true;
			else
				check= false;
		}

		//check the lower right diagnol here also we have to check for white pawn
		if(!right_bottom_diag.empty())
		for( int i=0;i<right_bottom_diag.size();i++){
		if(right_bottom_diag[0]=='K' || right_bottom_diag[0]=='P')
			return true;

			if (right_bottom_diag[i]=='.')
				continue;
			else if (right_bottom_diag[i]=='B' || left_bottom_diag[i]=='Q')
				return true;
			else 
				check=false;
		}
				


	return check;
	}
	else if(type=='w'){
		bool check;
		cout<<"in type w"<<endl;
		//check left
		if (!left.empty())
		for(int i=0;i<left.size();i++){
		if (left[0]=='k')
			return true;
			if (left[i]=='.'){
				continue;
			}
			else if( left[i]=='r' || left[i]=='q')
				return true;
			else 
				check= false;
		}
		//check right
		if (!right.empty())
		for(int i=0;i<right.size();i++){
		if (right[0]=='k')
			return true;
			if(right[i]=='.')
				continue;
			else if(right[i]=='r' || right[i]=='q')
				return true;
			else 
				check= false;
		}
		//check top
		if (!top.empty())
		for (int i=0;i<top.size();i++){
		if (top[0]=='k')
			return true;
			if (top[i]=='.')
				continue;
			else if(top[i]=='r' || top[i]=='q')
				return true;
			else
				check= false;
		}
		//check bottom
		if(!bottom.empty())
		for (int i=0;i<bottom.size();i++){
		if (bottom[0]=='k')
			return true;
			if (bottom[i]=='.')
				continue;
			else if(bottom[i]=='r' || bottom[i]=='q')
				return true;
			else 
				check=false;

		}
		//check left upper diagnol
		if(!left_top_diag.empty())
		for (int i=0;i<left_top_diag.size();i++){
		if (left_top_diag[0]=='k' || left_top_diag[0]=='p')
			return true;
			if (left_top_diag[i]=='.')
				continue;
			else if (left_top_diag[i]=='b' || left_top_diag[i]=='q')
				return true;
			else 
				check= false;
		}

		//check right upper diagnol
		if(!right_top_diag.empty())
		for (int i=0;i<right_top_diag.size();i++){
		if (right_top_diag[0]=='k' || right_top_diag[0]=='p')
			return true;
			if (right_top_diag[i]=='.')
				continue;
			else if(right_top_diag[i]=='b'||left_top_diag[i]=='q')
				return true;
			else 
				check= false;
		}

		//check lower left diagnol here we have to chec for white pawn as well
		if (!left_bottom_diag.empty())
		for(int i=0;i<left_bottom_diag.size();i++){
		if (left_bottom_diag[0]=='k' )
			return true;
			if (left_bottom_diag[i]=='.')
				continue;
			else if (left_bottom_diag[i]=='b' || left_bottom_diag[i]=='q')
				return true;
			else
				check= false;
		}

		//check the lower right diagnol here also we have to check for white pawn
		if(!right_bottom_diag.empty())
		for( int i=0;i<right_bottom_diag.size();i++){
		if(right_bottom_diag[0]=='k' )
			return true;

			if (right_bottom_diag[i]=='.')
				continue;
			else if (right_bottom_diag[i]=='b' || left_bottom_diag[i]=='q')
				return true;
			else 
				check=false;
		}
				


	return check;
	}
}
