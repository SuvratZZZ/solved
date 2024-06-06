#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <unordered_map>
#include <map>
#include <chrono>
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
unordered_map<string,ll> dp;
ll dpd(ll x,ll mon,ll amo,vector<ll> &c,vector<ll> &h,unordered_map<string,ll> &dp){
    if(mon>=c.size()){
        return 0;
    }
    if(dp[to_string(mon)+','+to_string(amo)]!=0){
        return dp[to_string(mon)+','+to_string(amo)];
    }
    ll r1=0,r2=0;
    if(amo>=c[mon]){
        r1=h[mon]+dpd(x,mon+1,amo+x-c[mon],c,h,dp);
    }
    r2=dpd(x,mon+1,amo+x,c,h,dp);
    dp[to_string(mon)+','+to_string(amo)]=max(r1,r2);
    return dp[to_string(mon)+','+to_string(amo)];
}
void solve(){
    ll m,x;
    cin>>m>>x;
    vector<ll> c(m),h(m);
    for (ll  i = 0; i < m ; i++)
    {
        cin>>c[i]>>h[i];
    }
    ll res=dpd(x,0,0,c,h,dp);
    for (int  i = m-1 ; i>=0 ; i++)
    {
        
    }
    

    cout << res << endl;
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