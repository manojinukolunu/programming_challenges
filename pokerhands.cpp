
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
        int black_kind[15],white_kind[15];//these arrays are used to determine the kind

        reset(black_kind,15);
        reset(white_kind,15);
        card_count(black_kind,black_card);
        card_count(white_kind,white_card);
        cout << endl;
        printarr(black_kind,15);
        cout << endl;
        printarr(white_kind,15);
        cout << endl;
        sort(black_card.begin(),black_card.end());
        sort(white_card.begin(),white_card.end());
        int black=process(black_kind,black_card,black_suit);
       // cout << "After black " << endl;
        //printarr(black_kind,15);
        int white=process(white_kind,white_card,white_suit);
        //cout << "After WHite " << white << endl;

        if (black > white){
            //cout << "black after process" << black << endl;
            cout << "Black wins" << endl;
        }
        else if(black < white){
            //cout << "white after process" <<
            //white  << endl;
            cout << "White wins" << endl;
        }
        else if(black==white){
            //cout << "Black equal" << black<<endl;
            if (black==-1){
                int card=highcard(black_card,white_card);
                if (card==1)
                    cout << "Black wins "<<endl;
                else if (card==2)
                    cout << "White wins "<< endl;
                else
                    cout << "Tie" << endl;
            }
            switch (black){
                int card;
                case 1:
                    //pair
                    int black_pair;
                    int white_pair;
                    int black_pair_index;
                    int white_pair_index;
                    for (int i=0;i<15;i++){
                        if (black_kind[i]==2){
                            black_pair=black_card[i];
                            black_pair_index=i;
                        }
                        if (white_kind[i]==2){
                            white_pair=white_card[i];
                            white_pair_index=i;
                        }
                    }

                    if(black_pair>white_pair){
                        cout << "Black wins" << endl;
                    }
                    else if(white_pair > black_pair){
                        cout << "White wins" << endl;
                    }
                    else {
                        for (int i=black_pair_index,j=white_pair_index;i<5,j<5;i++,j++){
                            if (black_card[i]>white_card[j]){
                                cout << "Black wins" << endl;
                                break;
                            }
                            else if(black_card[i]< white_card[j]){
                                cout << "White wins" << endl;
                                break;
                            }
                        }
                    }
                    break;
                case 2:
                    int first_paircard_black,second_paricard_white,second_paricard_black,other_card_black,other_card_white;
                    int first_paircard_white,paircount_black,paircount_white;
                    for (int i=0;i<15;i++){
                        if(black_kind[i]==2){
                            first_paircard_black=i;
                            paircount_black++;
                        }
                        if (white_kind[i]==2){
                            first_paircard_white=i;
                            paircount_white++;
                        }
                        if (paircount_black==2 && black_kind[i]==2){
                            second_paricard_black=i;
                        }
                        if(paircount_white==2 && white_kind[i]==2){
                            second_paricard_white=i;
                        }
                        if (white_kind[i]==1)
                            other_card_white=i;
                        if (black_kind[i]==1)
                            other_card_black=i;
                    }
                    if (first_paircard_white>first_paircard_black){
                        cout << "White wins" << endl;
                    }
                    else if(first_paircard_white<first_paircard_black){
                        cout << "Black wins" <<endl;
                    }
                    else {
                        if (second_paricard_black>second_paricard_white){
                            cout << "Black Wins" << endl;
                        }
                        else if(second_paricard_black<second_paricard_white){
                            cout << "White Wins" << endl;
                        }
                        else {
                            if (other_card_black>other_card_white){
                                cout << " Black Wins " << endl;
                            }
                            else if(other_card_white> other_card_black){
                                cout << " Black Wins"<< endl;
                            }
                            else
                                cout << "Tie" << endl;
                        }
                    }

                    break;
                case 3:
                    int black_3_kind,white_3_kind;
                    for (int i=0;i<15;i++){
                        if (black_kind[i]==3)
                            black_3_kind=i;
                        if (white_kind[i]==3)
                            white_3_kind=i;
                    }
                    if (black_3_kind>white_3_kind){
                        cout << "Black Wins" << endl;
                    }
                    else if(white_3_kind>black_3_kind){
                        cout << "White wins" << endl;
                    }
                    else {
                        cout << "Tie" << endl;
                    }
                    break;
                case 4:
                    if (white_card.back()>black_card.back()){
                        cout << "White wins" << endl;
                    }
                    else if(black_card.back() > white_card.back()){
                        cout << "Black wins" << endl;
                    }
                    else
                        cout << "Tie" << endl;
                    break;
                case 5 :
                    card=highcard(black_card,white_card);
                    if (card==1)
                        cout << "Black wins "<<endl;
                    else if (card==2)
                        cout << "White wins "<< endl;
                    break;
                case 6:
                    for (int i=0;i<15;i++){
                        if (black_kind[i]==3)
                            black_3_kind=i;
                        if (white_kind[i]==3)
                            white_3_kind=i;
                    }
                    if (black_3_kind>white_3_kind){
                        cout << "Black Wins" << endl;
                    }
                    else if(white_3_kind>black_3_kind){
                        cout << "White wins" << endl;
                    }
                    else {
                        cout << "Tie" << endl;
                    }
                    break;
                case 7:
                    int black_4_kind,white_4_kind;
                    for (int i=0;i<15;i++){
                        if (black_kind[i]==4){
                            black_4_kind=i;
                        }
                        if (white_kind[i]==4){
                            white_4_kind=i;
                        }
                    }
                    if (black_4_kind>white_4_kind){
                        cout << "Black Wins" << endl;
                    }
                    else if(white_4_kind>black_4_kind){
                        cout << "White wins" << endl;
                    }
                    else {
                        cout << "Tie" << endl;
                    }
                    break;
                case 8:
                    if( black_card[4] == white_card[4]){
                        cout << "Tie" <<endl;
                    }
                    else if(black_card[4]>white_card[4]){
                        cout << "Black WIns" <<endl;
                    }
                    else if(white_card[4]>black_card[4]){
                        cout << "White wins" << endl;
                    }
                    break;


            }
        }


    }
    return 0;
}
int process(int kind[15],vector <int> cards,vector <char> suit){
    if (straightFlush(cards,suit)){
        cout << "Straight flush " <<endl;
        printvecint(cards);
        return 8;
    }
    else if(kind4(kind)){
        cout << "4 of a kind"<<endl;
        printarr(kind,15);
        return 7;
    }
    else if (fullhouse(kind)){
        cout << "Full house" << endl;
        printarr(kind,15);
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
        printarr(kind,15);
        return 3;
    }
    else if (pair2(kind)){
        cout << "2 pair" << endl;
        printarr(kind,15);
        return 2;
    }
    else if (pair1(kind)){
        cout <<"pair" << endl;
        printarr(kind,15);
        return 1;
    }
    else {
        //means none of the above unlucky hand
        // compare with high card only
        return -1;
    }

}
bool pair1(int kind[15]){
    for (int i=0;i<15;i++){
        if (kind[i]==2){
            return true;
        }
    }
    return false;
}
bool pair2(int kind[15]){
    int count=0;
    for (int i=0;i<15;i++){
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
bool fullhouse(int kind[15]){
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
bool kind4(int kind[15]){
    for(int i=0;i<15 ;i++){
        if(kind[i]==4){
            return true;
        }
    }
    return false;
}
bool kind3(int kind[15]){
    for(int i=0;i<15;i++){
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
void card_count(int  kind[15],vector <int> card){
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
