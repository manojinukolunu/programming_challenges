#include "poker.h"
int main(int argc,char ** argv){
    char c,suit;
    string st="--23456789TJQKA";
    while (1){
        vector <char> white_suit,black_suit;
        vector <int> black_card,white_card;
        int count =0;
        while((c=getchar())!='\n'){
            if (c!=' '){
                string str(1,c);
                count++;
                if (count>5){
                    white_card.push_back(int(st.find(str)));
                    suit=getchar();
                    white_suit.push_back(suit);
                }
                else{
                    black_card.push_back(int(st.find(str)));
                    suit=getchar();
                    black_suit.push_back(suit);
                }
            }
        }
         //Now we have both the cards and suits in the vectors
         //get the card counts in the arrays
        int black_kind[14],white_kind[14];//these arrays are used to determine the kind
        reset(black_kind,14);
        reset(white_kind,14);
        card_count(black_kind,black_card);
        card_count(white_kind,white_card);
        sort(black_card.begin(),black_card.end());
        sort(white_card.begin(),white_card.end());
        int * black=process(black_kind,black_card,black_suit);
        int * white=process(white_kind,white_card,white_suit);
    }
    return 0;
}


vector <int>  processnew(int kind[14],vector <int> cards ,vector <char> suit) {
	//first check for flush and straight flush
	vector <int> returnVector;
	if (straightFlush(cards,suit){
		returnVector.push_back(8);
		returnVector.push_back(cards.back());
		return returnVector;
	}
	if (kind4(kind)){
		returnVector.push_back(7);
		for (int i=0;i<14;i++){
			if (kind[i]==14){
				returnVector.push_back(i);
				return returnVector;
			}
		}
	}
	if (fullhouse(kind)){
		returnVector.push_back(6)
		for (int i=0;i<14;i++){
			if (kind[i]==3){

			}
			if (kind[i]==2){

			}

		}

	}
	if(flush(cards,suit)){
		returnVector.push_back(5);
		returnVector.insert(returnVector.end(),cards.begin(),cards.end());
	}
	if(straight(cards)){
		returnVector.push_back4);
		returnVector.insert(returnVector.end(),cards.begin(),cards.end());
	}

}


vector <int> cardsofkind(int n, int kind[14],vector <int> cards){
    //lets first examine 2 pair and pair
    int paircount=0;
    if (n==2){//2 of a kind
        for (int i=0;i<14;i++){
            if (kind[i]==2 && paircount==2){
                returnVector.push_back(i);
            }
            else if(kind[i]==2 && paircount==1){
                returnVector.push_back(i);
            }
        }
        if (paircount==1){
            returnVector.insert(0,1);
        }
        else if(paircount==2){
            returnVector.insert(0,2);
        }
        for (int i=0;i<5;i++){
            if (kind[cards[i]]!=2){
                returnVector.push_back(cards[i]);
            }
        }
        return returnVector;
    }
    vector <int> returnVector;
    for (int i=0;i<14;i++){
        if (kind[i]==n){
            returnVector.push_back(i);
        }
    }

}




int * process(int kind[14],vector <int> cards,vector <char> suit){
    if (straightFlush(cards,suit)){
        cout << "Straight flush " <<endl;
        printvecint(cards);
        return 8;
    }
    else if(kind4(kind)){
        cout << "4 of a kind"<<endl;
        printarr(kind,14);
        return 7;
    }
    else if (fullhouse(kind)){
        cout << "Full house" << endl;
        printarr(kind,14);
        return 6;
    }
    else if (flush(suit)){
        cout << "Flush" << endl;
        printvec(suit);
        return 5;
    }
    else if (straight(cards)){
        cout << "straight" << endl;
        printvecint(cards);
        return 4;
    }
    else if(kind3(kind)){
        cout << "3 of a kind" << endl;
        printarr(kind,14);
        return 3;
    }
    else if (pair2(kind)){
        cout << "2 pair" << endl;
        printarr(kind,14);
        return 2;
    }
    else if (pair1(kind)){
        cout <<"pair" << endl;
        printarr(kind,14);
        return 1;
    }
    else {
        //means none of the above unlucky hand
        // compare with high card only
        return -1;
    }

}
bool pair1(int kind[14]){
    for (int i=0;i<14;i++){
        if (kind[i]==2){
            return true;
        }
    }
    return false;
}
bool pair2(int kind[14]){
    int count=0;
    for (int i=0;i<14;i++){
        if (kind[i]==2){
            count++;
        }
    }
    if (count == 2){
        return true;
    }
    else {
        return false;
    }
}
bool flush(vector<char> suit){
    if (checkSuit(suit)){
        return true;
    }
    else {
        return false;
    }
}
bool straight(vector<int> cards){
    // the cards are already sorted
    if((cards.back()-cards.front())==5){
        return true;
    }
    else{
        return false;
    }
}
bool fullhouse(int kind[14]){
    //cout << " In Full House" << kind3(kind) << pair1(kind) << endl;
    if (kind3(kind) && pair1(kind)){
      //  cout << "True" << endl;
        return true;
    }
    else {
        return false;
    }
}
bool straightFlush(vector<int> cards,vector<char> suit){
    //the cards are already sorted
    if (checkSuit(suit)&&((cards.back()-cards.front())==5)){
        return true;
    }
    else{
            return false;
    }
}
bool kind4(int kind[14]){
    for(int i=0;i<14 ;i++){
        if(kind[i]==4){
            return true;
        }
    }
    return false;
}
bool kind3(int kind[14]){
    for(int i=0;i<14;i++){
        if (kind[i]==3){
            return true;
        }
    }
    return false;
}
bool checkSuit(vector <char> suit){
    char su=suit[0];
    for (int i=0;i<suit.size();i++){
        if (suit[i]!=su){
            return false;
        }
    }
    return true;
}
void card_count(int  kind[14],vector <int> card){
    for (int i=0;i<card.size();i++){
            if (kind[card[i]]!=0){
                kind[card[i]]++;
            }
            else{
                kind[card[i]]=1;
            }
        }

}

void printvec(vector <char> vec){
    for (int i=0;i<vec.size();i++){
        cout << vec[i];
    }
    cout << endl;

}
void printvecint(vector <int> vec){
    for (int i=0;i<vec.size();i++){
        cout << vec[i];
    }
    cout << endl;

}

void printarr(int arr[],int size){
    for (int i=0;i<size;i++){
        cout << arr[i] ;
    }
    cout << endl;

}
void reset(int arr[],int size){
    for (int i=0;i<size;i++){
        arr[i]=0;
    }

}
int highcard(vector <int>black,vector <int> white){
    //returns the hights card after all comparisions
    reverse(black.begin(),black.end());
    reverse(white.begin(),white.end());
    printvecint(black);
    printvecint(white);
    for (int i=0;i<black.size();i++){
        if (black[i]==white[i]){
            continue;
        }
        else if (black[i]>white[i]){
            return 1;
        }
        else if(black[i]<white[i]){
            return 2;
        }

    }
}
