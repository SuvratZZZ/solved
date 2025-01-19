#include <bits/stdc++.h>
using namespace std;
# define ll long long

# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        ll n;cin>>n;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    for (ll  i = 0; i < n-1 ; i++)
    {
        ll tem=min(a[i],a[i+1]);
        a[i]-=tem;
        a[i+1]-=tem;
    }
    bool che=1;
    for (ll  i = 0; i < n-1 ; i++)
    {
        if(a[i]>a[i+1]){
            che=0;
        }
    }
    yn(che);
    }
    return 0;
}