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
const ll M = 1000000007;

// ll ncr(ll n, ll r){
//     double sol=1;
//     for (ll i = 1; i <= r; i++)
//     {
//         sol=sol*((n-r+i)/i);
//     }
//     return (ll)sol;
// }

ll sol(ll n,vector<ll> &dp){
    if(n<=1)return 1;
    if(dp[n]!=-1)return dp[n];
    ll res=(sol(n-1,dp)%M+2*(n-1)*sol(n-2,dp)%M)%M;
    return dp[n]=res%M;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    set<ll> s;
    for (ll  i = 0; i < k ; i++)
    {
        ll r,c;
        cin>>r>>c;
        s.insert(r);
        s.insert(c);
    }
    vector<ll> dp(n+1,-1);
    ll ress=sol(n-s.size(),dp);
    cout << ress << endl;
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