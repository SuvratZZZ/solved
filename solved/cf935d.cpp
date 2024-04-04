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
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> a[i];
    }
    ll res=0;
    for (ll  i = 0; i < n ; i++)
    {
        cin>> b[i];
        if (i>(m-1))
        {
            res=res+min(a[i],b[i]);
        } 
    }
    ll sol=a[m-1],tem=b[m-1];
    for (ll  i = m-2; i >=0  ; i--)
    {
        
        sol=min(sol,tem+a[i]);
        tem=tem+b[i];
    }
    
    cout << res+sol << endl;
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