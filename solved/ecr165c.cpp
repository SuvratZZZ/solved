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

ll re(vector<ll> &v,ll todo,ll ind,vector<vector<ll>> &dp){
    if((ind>=(ll)v.size())){
        return 0;
    }
    if(dp[ind][todo]!=-1)return dp[ind][todo];
    ll res=1e18,me=v[ind];
        for (ll  i = 0; (i <= todo)&&(ind+i<v.size()); i++)
        {
            me=min(me,v[ind+i]);
            res=min(res,re(v,todo-i,ind+i+1,dp)+(me*(i+1)));
        }
    return dp[ind][todo]=res;
}

void solve(){
    ll n,k,ss=0,dd=0;
    cin>>n>>k;
    vector<ll> v(n);
    vector<ll> v2(n);
    vector<ll> diff(n-1);
    if(n==1){
        cin>>v[0];
        cout << v[0] << endl;
        return;
    }
    for (ll  i = 0; i < n ; i++)
    {
        cin>> v[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    // vector<vector<ll>> dp2(n,vector<ll>(k+1,-1));
    // cout << re(v,k,0,dp2) << endl;
    for (ll  p = n-1; p >=0  ; p--)
    {
        for (ll  todo  = 0; todo  <=k ; todo ++)
        {
            ll res=1e18,me=v[p];
            for (ll  i = 0; (i <= todo)&&(p+i<v.size()); i++)
            {
                me=min(me,v[p+i]);
                res=min(res,dp[p+i+1][todo-i]+(me*(i+1)));
            }
            dp[p][todo]=res;
        }
    }
    cout << dp[0][k] << endl;
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