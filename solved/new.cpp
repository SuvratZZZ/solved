#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll tess;
    cin >> tess;
    while(tess--){
        ll length,mexx=0;
    cin>> length;
    set<ll> s11;
    vector<ll> aa(length),ans(length);
    for (ll  i = 0; i < length ; i++)
    {
        cin>> aa[i];
        s11.insert(i);
        // if(i==length-1){
        //     ans[i]=length-aa[i];
        // }
        // else if (aa[i]==1)
        // {
        //     ans[i]=mexx;
        //     mexx++;
        // }
        // else
        //     ans[i]=mexx-aa[i] ;
    }
    set<ll> s22;
    for (ll  i = 0; i < length ; i++)
    {
        if (s11.find(mexx-aa[i])!=s11.end())
        {
            ans[i]=mexx-aa[i];
            s22.insert(mexx-aa[i]);
            s11.erase(mexx-aa[i]);
        }
        else{
            s11.erase(mexx);
            ans[i]=mexx;
            s22.insert(mexx);
        }
        while (s22.find(mexx)!=s22.end())
        {
            mexx++;
        }
        
    }
    
    for (ll  i = 0; i < length ; i++)
    {
        cout << ans[i] << " " ;
    }
    //okay
    cout << endl ;
    }
    return 0;
}