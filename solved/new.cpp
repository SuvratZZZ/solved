#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll tess;
    cin >> tess;
    while(tess--){
        ll len1,len2,kee;
    cin>>len1>>len2>>kee;
    map<ll,ll> mapi;
    map<ll,ll> macho;
    vector<ll> arr(len1),brr(len2);
    for (ll  i = 0; i < len1 ; i++)
    {
        cin>> arr[i];
    }
    for (ll  i = 0; i < len2 ; i++)
    {
        cin>> brr[i];
        mapi[brr[i]]++;
    }
    ll ans=0;
    ll yaya=0;
    for (ll  i = 0; i < len2 ; i++)
    {
        if (mapi[arr[i]]!=0)
        {
            if ((macho[arr[i]]<mapi[arr[i]]))
            {
                yaya++;    
            }
            macho[arr[i]]++;
        }
    }
    if(yaya>=kee) ans++;
    for (ll  i = len2; i < len1 ; i++)
    {
        if (mapi[arr[i-len2]]!=0)
        { 
            if (macho[arr[i-len2]]<=mapi[arr[i-len2]])
            {
                yaya--; 
            }
            macho[arr[i-len2]]--;
        }
        if ((mapi[arr[i]]!=0))
        {
            if ((macho[arr[i]]<mapi[arr[i]]))
            {
                yaya++;    
            }
            macho[arr[i]]++;
        }
        if(yaya>=kee) ans++;
    }
    // okk
    cout << ans << endl;
    }
    return 0;
}