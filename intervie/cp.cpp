#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++)
    {
        cin>> arr[i];
    }
    
    int lar1=0,lar2=0,smal1=1e6+1,smal2=1e6+1;


    for(auto &i:arr){
        if(i>=lar1){
            lar2=lar1;
            lar1=i;
        }
        else if(i>lar2){
            lar2=i;
        }

        if(i<=smal1){
            smal2=smal1;
            smal1=i;
        }
        else if(i<smal2){
            smal2=i;
        }
    }

    cout << max({lar1-smal2,lar2-smal1}) << endl;
    return 0;
}