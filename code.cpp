#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc,char ** argv){
    int numTestCases;
    cin >> numTestCases;
    while(numTestCases--){
        int N;
        cin >> N;
        int * arr=new int[N];
        for (int i=0;i<N;i++){
            cin >> arr[i];
        }
        sort(arr,arr+N);
        cout << arr[1]-arr[0];
    }
}
