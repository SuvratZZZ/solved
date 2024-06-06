#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,k,i,i2;
    cin>>n>>k;
    for ( i = 0; i <= n ; i++)
    {
        if(((ll)1<<i)&k){
            // cout << 1;
            i2=i;
            break;
        }
        else{
            // cout << 0;
        }
    }
    // cout << endl;
    cout << n-i2 << endl;
    }
    return 0;
}