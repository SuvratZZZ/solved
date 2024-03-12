#include <bits/stdc++.h>
using namespace std;
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
ll dpp(ll ind,vvll v,ll d,ll m,vvll &dp,ll row){
    if (ind<0)
    {
        return INT_MAX;
    }
    if (ind==0)
    {
        return 1;
    }
    if (dp[row][ind]!=-1)
    {
        return dp[row][ind];
    }
    ll mn = INT_MAX;
    for (ll  i = 1; i <= d+1 ; i++)
    {
        mn = min (mn,dpp(ind-i,v,d,m,dp,row));
    }
    return dp[row][ind]=mn+v[row][ind]+1;
}
void solve(){
    ll n,m,k,d;
    cin >> n >> m >> k >> d;
    vector<vector<ll>> v(n,vector<ll>(m));
    vector<vector<ll>> dp(n,vector<ll>(m,-1));
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j = 0; j < m ; j++)
        {
            cin >> v[i][j];
        }
    }
    ll res=INT_MAX;
    ll sol=0;
    for (ll  i = 0; i < k ; i++)
    {
        sol=sol+dpp(m-1,v,d,m,dp,i);
    }
    res=sol;
    for (ll  i = 0; i < n-k; i++)
    {
        sol=sol-dp[i][m-1]+dpp(m-1,v,d,m,dp,i+k);
        res=min(res,sol);
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