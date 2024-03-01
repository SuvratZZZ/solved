#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
    cin >> n;
    ll ans=1;
    while (ans<=n )
    {
        ans=ans*2;
    }
    ans=ans/2;
    cout << ans << endl;
    }
    return 0;
}