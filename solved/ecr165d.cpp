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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
void solve(){
    ll n,k,ps=0;
    cin>>n>>k;
    vector<ll> a(n),b(n);
    vector<pair<ll,ll>> dff(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    for (ll  i = 0; i < n ; i++)
    {
        cin>>b[i];
        dff[i]={b[i],i};
    }
    sort(dff.begin(),dff.end());
    reverse(dff.begin(),dff.end());
    ll ans=0,res=0,i=0;
    for (i = 0; i < k ; i++)
    {
        res=res-a[dff[i].second];
    }
    for (; i < n ; i++)
    {
        res=res+dff[i].first;
        ans=max(ans,res);
    }
    cout << ans << endl;
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