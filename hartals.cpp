#include <iostream>

using namespace std;
void reset(int * ,int );


int main(int argc,char ** argv){
    int numTestCases;
    cin >> numTestCases;
    while(numTestCases--){
        int numsim,numparties;
        cin >> numsim;
        cin >> numparties;
        int hartals=0;
        int * arr=new int[numsim];
        reset(arr,numsim);
        while(numparties--){
            int hartalparam;
            cin >> hartalparam;
            int i=1;
            while(1){
                if(hartalparam*i>numsim){
                    break;
                }
                if ((hartalparam*i<=numsim)){
                    arr[hartalparam*i-1]=1;
                    i++;
                }
            }
            for (int i=0;i<numsim;i++){
                if (i%7==6||i%7==5){
                    arr[i]=0;
                }
            }

        }
        for (int i=0;i<numsim;i++){
            if (arr[i]==1){
                hartals++;
            }
        }
         cout << hartals;
    }
    return 0;
}
void reset(int * arr,int size){
    for (int i=0;i<size;i++){
        arr[i]=0;
    }
}
