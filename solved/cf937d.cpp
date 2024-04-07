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

vector <ll> dp(100001,-1);
ll decToBinary(ll n)
{
    ll res=0;
    for (ll i = 9; i >= 0; i--) {
        ll k = n >> i;
        if (k & 1)
            res=res*10+1;
        else
            res=res*10;
    }
    return res;
}
bool isreq(ll n,vector <ll> &dp){
    bool tem=false;
    if (n==1)
    {
        tem=tem|| true;
    }
    if(dp[n]!=-1)return dp[n];
    for (ll i = 2; (i<=(ll)pow(2,6))&&(i<=n) ; i++)
    {
        if (n%decToBinary(i)==0)
        {
            tem=tem|| isreq(n/decToBinary(i),dp);
        }
        
    }

    return dp[n]=tem;
}
void solve(){
    ll n;
    cin >> n;
    if(isreq(n,dp))
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
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