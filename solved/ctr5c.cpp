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
ll sol(ll ind,vector<ll> &dp,vector<ll> &v,vector<ll> &mx){
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    ll a1,a2;
    a1=sol(ind-1,dp,v,mx);
    if(mx[v[ind]]==INT_MIN){
        a2=a1;
        mx[v[ind]]=a1-(ind);
        // cout << ind << " : for ind , ele : " << v[ind] << " mx of vind : " << mx[v[ind]] << " a1l1 : " << a1  << endl;
    }
    else{
        a2=ind+1+mx[v[ind]];
        mx[v[ind]]=max(mx[v[ind]],a1-(ind));
        // cout << ind << " : for ind , ele : " << v[ind] << " mx of vind : " << mx[v[ind]] << " a1 : " << a1 << " a2 : " << a2  << endl;
    }
    return dp[ind]=max(a1,a2);
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>v[i];
    }
    vector<ll> dp(n,-1);
    vector<ll> mx(n+1,INT_MIN);
    cout << sol(n-1,dp,v,mx) << endl;
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