#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll tess;
    cin >> tess;
    while(tess>0){
        ll lenn;
    cin>>lenn;
    vector<ll> arr(lenn);
    set<ll> shetty;
    for (ll  i = 0; i < lenn ; i++)
    {
        cin>>arr[i];
        shetty.insert(arr[i]);
    }
    if(*shetty.rbegin()==shetty.size()){
        if(shetty.size()%2){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
    else{
    ll tatt=0;
    for(ll i:shetty){
        if(i==tatt+1){
            tatt=tatt+1;
        }
        else{
            break;
        }
    }
    if(tatt%2==0)
    {
            cout << "Alice" << endl;
    }
    else{
            cout << "Bob" << endl;
    }
    }
    tess--;
    }
    return 0;
}