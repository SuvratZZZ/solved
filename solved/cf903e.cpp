#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)

typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;

ll rere(ll ind,ll n, vector<ll> &dp, vector<ll> &a){
    if (ind ==n )
    {
        return  0 ;
    }
    if (ind > n )
    {
        return  INT_MAX ;
    }
    if (dp[ind]!=-1)
    {
        return dp[ind];
    }
    ll n_rem=rere(ind+a[ind]+1,n,dp,a);
    ll rem=1+rere(ind+1,n,dp,a);
    return dp[ind]=min(rem,n_rem);
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for ( ll  i= 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<ll> dp(n,-1);
    ll res = rere(0,n,dp,a);
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