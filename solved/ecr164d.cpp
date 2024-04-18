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
ll sol(vector<ll> v,vector<vector<ll>> &dp,ll ind,ll ball,ll &ans, ll maxel){
    if (ind<0)
    {
        return 0;
    }
    if (dp[ind][ball]!=-1)
    {
    cout << ind << " : ind " << ball << " : ball " << " added :" << dp[ind][ball] << endl;
        return dp[ind][ball];
    }
    ll notake=sol(v,dp,ind-1,ball-v[ind],ans,(ind>0?v[ind-1]:0));
    ll take=sol(v,dp,ind-1,ball,ans,maxel);
    if (maxel>take )
    {
        ans+=v[ind];
    cout << ind << " : ind " << ball << " : ball " << " added :" << v[ind] << " take : " << take<<  endl;
    }
    else{
        ans+=(v[ind]+take+1)/2;
    cout << ind << " : ind " << ball << " : ball " << " added :" << (v[ind]+take+1)/2 << " take : " << take<<  endl;
    }
    return dp[ind][ball]=take+v[ind];
}
void solve(){
    ll n,sum=0,ans=0;
    cin>>n;
    vector<ll> v(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> v[i];
        sum+=v[i];
    }
    sort(v.begin(),v.end());
    vector<vector<ll>> dp(n,vector<ll>(sum+1,-1));
    sol(v,dp,n-1,sum,ans,v[n-1]);
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}