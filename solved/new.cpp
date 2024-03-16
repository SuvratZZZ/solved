#include <bits/stdc++.h>
using namespace std;
# define ll long long


int main(){
    ll tes ;
    cin >> tes ;
    while(tes --){
        ll len ;
    cin >> len ;
    vector<ll> vec(len );
    map<ll,ll> mapi;
    ll maxii = INT_MIN;
    for (ll  i = 0; i < len  ; i++)
    {
        cin >> vec[i];
        mapi[vec[i]]++;
        maxii=max(maxii,vec[i]);
    }
    ll ans=0,chec=0;
    for (ll  i = 0; i <= maxii+1; i++)
    {
        if (mapi[i]==0)
        {
            ans = i;
            break;
        }
        if((mapi[i]==1)&&chec){
            ans = i;
            break;
            cout << "ff " << i << endl;
        }
        if (mapi[i]==1)
        {
            chec=1;
        }
        
    }
    // ok
    cout << ans << endl;
    }
    return 0;
}