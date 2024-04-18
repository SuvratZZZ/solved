#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
//
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> cos(n);
    vector<ll> cos2(n);
    vector<ll> cos3(n);
    vector<ll> hsh(n,0);
    vector<vector<ll>> gra(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> cos[i];
    }
    for (ll  i = 0; i < k ; i++)
    {
        ll  tem;
        cin>>tem;
        hsh[tem-1]=1;
    }
    for (ll  i = 0; i < n ; i++)
    {
        ll tem=0;
        cin>>tem;
        ll res=0;
        for (ll j  = 0; j  < tem ; j ++)
        {
            ll tem2;
            cin >> tem2;
            gra[i].push_back(tem2-1);
            if(hsh[tem2-1]==0){
                res=res+cos[tem-1];
            }
        }
        if (tem==0)
        {
            cos2[i]=INT_MAX;
        }
        else{
            cos2[i]=res;
        }
    }
    for (ll  i = 0; i < n ; i++)
    {
        ll tem=gra[i].size();
        ll res=0;
        for (ll j  = 0; j  < tem ; j ++)
        {
            gra[i].push_back(tem2-1);
            if(hsh[tem2-1]==0){
                res=res+cos[tem-1];
            }
        }
        if (tem==0)
        {
            cos2[i]=INT_MAX;
        }
        else{
            cos2[i]=res;
        }
    }
    for (ll i = 0; i < n ; i++)
    {
        if(hsh[i]==1){
            cout << 0 << ' ';
        }
        else{
            cout << min(cos[i],cos2[i]) << " " ;
        }
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}