#include <bits/stdc++.h>
using namespace std;
# define ll long long

long long binpow(long long a, long long b) {
    
    return 1ll;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        ll n,k,res=0;cin>>n>>k;
    vector<ll> a(n);
    map<ll,ll> mp;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(mp[k-a[i]]!=0){
            res++;
            res*binpow(a[i],a[i]);
            mp[k-a[i]]--;
        }
        else{
            mp[a[i]]++;
        }
    }
    cout << res <<endl;
    }
    
    return 0;
}