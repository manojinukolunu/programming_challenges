#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctype.h>

using namespace std;

struct node
{
	char data;
	node* left;
	node*right;
	int precedence;
};

node* newNode(char data)
{
	node* nwnd=(node*) malloc(sizeof(struct node));
	nwnd->data=data;
	nwnd->left=NULL;
	nwnd->right=NULL;
	nwnd->precedence=0;

	return nwnd;
}

bool isOpr(char data)
{
	if(data==NULL) return false;
	if(data== '*'||'/'||'-'||'+')
		return true;
}

node* insert(node* root, char data)
{
	if (root==NULL) return newNode(data);
	node* nwnd = newNode(data);
	if( data<=root->data) root->left=insert(root->left,data);
	else root->right=insert(root->right,data);

	return root;
}

int cmbint (char n1, char n2)
{
	int in1=n1-'0';
	int in2=n2-'0';

	return (in1*10)+in1;
}

char cmbop (char o1, char o2)
{
	return o1+o2;
}

int main()
{
	node *ops=(node*)malloc(sizeof(struct node));
	string exprsn;
	getline(cin,exprsn);
	cout << exprsn[1];

	for (int i=0; i<exprsn.length();i++)
	{
		if(isdigit(exprsn[i]))
		{
			insert(ops->left, exprsn[i]);
			//cout<< "test" <<inp;
		}
		else if(isOpr(exprsn[i]))
		{
			if(exprsn[i]=='(')
			{

			if(isOpr(exprsn[i+1]))
			{
				char unryOp=cmbop (exprsn[i+1],exprsn[i]);
				i++;
			}
			else
			{
				char binOp=exprsn[i];
			}
		}
		else
		{
			cout<<"you entered the wrong expression we cant add alphabets... if you want so, I can rewrite the code for you" << endl;
			return 0;
		}
	}



	return 0;
}

}
