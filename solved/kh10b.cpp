#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main(){
    ll tt;
    cin>> tt;
    while(tt--){
        ll k,m;
        cin>>k>>m;
        if(m%(3*k)>=(2*k)){
            cout << 0 << endl;
        }
        else{
            cout << (2*k)-m%(3*k) << endl;
        }
    }
    return 0;
}