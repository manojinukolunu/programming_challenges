#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <algorithm>


using namespace std;
bool checkSuit(vector <char> suit);
void printvec(vector<char>);
void printvecint(vector <int> vec);
void card_count(int *,vector <int> );
void printarr(int [],int );
void reset(int [],int);
int highcard(vector<int> ,vector <int> );
int process(int [],vector<int> ,vector<char>);
bool pair1(int kind[14]);
bool pair2(int kind[14]);
bool flush(vector<char> suit);
bool straight(vector<int> cards);
bool fullhouse(int kind[14]);
bool straightFlush(vector<int> cards,vector<char> suit);
bool kind4(int kind[14]);
bool kind3(int kind[14]);
