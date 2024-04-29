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
ll ncr(ll n,ll r){
    if(n<r)return 0;
    double res=1;
    ll cou=1;
    for (ll  i = max(r+1,n-r+1); i <= n; i++)
    {
        res=res*((double)i)/(double)cou;
        cou++;
    }
    return (ll)res;
}
void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> cor(n);
    map<ll,ll> xmy;
    map<ll,ll> xpy;
    map<ll,ll> hor;
    map<ll,ll> ver;
    for (ll  i = 0; i < n ; i++)
    {
        ll t1,t2;
        cin>> t1>> t2;
        cor[i]={t1,t2};
        xmy[t1-t2]++;
        xpy[t1+t2]++;
        hor[t1]++;
        ver[t2]++;
    }
    ll res=0;
    for(auto i:xmy){
        res=res+ncr(i.second,2);
    }
    for(auto i:xpy){
        res=res+ncr(i.second,2);
    }
    for(auto i:hor){
        res=res+ncr(i.second,2);
    }
    for(auto i:ver){
        res=res+ncr(i.second,2);
    }
    cout << 2*res << endl;
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
        // ll n, r;
        // cin>>n>>r;
        // cout << ncr(n,r) << endl;
    }
    return 0;
}