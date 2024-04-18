#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main(){
    ll tes;
    cin >> tes;
    while(tes--){
        ll tess;
    cin>>tess;
    vector<ll> arr(tess);
    ll che1=1,che2=1;
    for (ll  i = 0; i < tess ; i++)
    {
        cin>> arr[i];

    }
    ll r1=0,r2=0,finn=INT_MAX,couu=INT_MAX;
    for (ll  i = 1; i < tess ; i++)
    {
        if(arr[i]!=arr[i-1]){
            r1=i;
            break;
        }
    }
    for (ll  i = tess-2; i >= 0 ; i--)
    {
        if(arr[i]!=arr[i+1]){
            r2=tess-i-1;
            break;
        }
    }
    for (ll i = 1; i < tess ; i++)
    {
        if (arr[i]!=arr[0])
        {
            finn=min(couu,finn);
            couu=0;
        }
        else{
            couu++;
        }
    }
    if (r1==0)
    {
        cout << -1 << endl;
    }
    else cout << min(finn,min(r1,r2)) << endl;
    }
    return 0;
}