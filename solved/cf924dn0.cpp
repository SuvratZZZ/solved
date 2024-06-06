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
    ll n,k,st,en;
    cin>>n>>k;
    vector<ll> vv(n-2);
    for (ll  i = 0; i < n ; i++)
    {
        if(i==0)cin>>st;
        else if(i==n-1)cin>>en;
        else cin>>vv[i];
    }
    sort(vv.begin(),vv.end());
    ll i=0,mx=1;
    while (k>0)
    {
        if(i<n-2){
            if(st>=((vv[i+1]/2)+1)&&en>=(vv[i+1]+1)/2){
                mx=vv[i]+min(k,(vv[i+1]-vv[i]));
                k=max((ll)0,k-(vv[i+1]-vv[i]));
                i++;
            }
            if(st<((vv[i]/2)+1)){

            }
            if(en<(vv[i]+1)/2){

            }
            vv[i]
        }
        
    }
    
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