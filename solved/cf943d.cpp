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
ll dfs(vector<ll> &p,vector<ll> &a,vector<ll> &vis,ll ind,ll co,ll &mx){
    if(co<=0)return 0;
    if(a[ind]==mx)return mx*co;
    if(p[ind]-1==ind)return co*a[ind];
    // cout << ind << " ";
    ll res=co*a[ind];
    if(vis[p[ind]-1]==-1){
        res=max(res,a[ind]+dfs(p,a,vis,p[ind]-1,co-1,mx));
    }
    else
    return res;
}
void solve(){
    ll n,k,pb,ps,mx=INT_MIN;
    cin>>n>>k>>pb>>ps;
    vector<ll> p(n),a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>p[i];
    }
    // map<ll,vector<ll>> m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        // m[a[i]].push_back(i);
        mx=max(mx,a[i]);
    }
    // ll j=1;
    // for(auto i:m){
    //     for(auto k:i.second){
    //         a[k]=j;
    //     }
    //     // mx=max(mx,j);
    //     j++;
    // }
    // for(auto i:a){
    //     cout << i << " ";
    // }
    // cout << endl;
    vector<ll> vis(n,-1);
    ll bb=dfs(p,a,vis,pb-1,k,mx);
    // cout << bb << " : bb " << endl;
    for(ll i=0;i<n;i++){vis[i]=-1;}
    ll ss=dfs(p,a,vis,ps-1,k,mx);
    // cout << ss << " : ss " << endl;
    if(bb>ss){
        cout << "Bodya" << endl;
    }
    else if(bb<ss){
        cout << "Sasha" << endl;
    }
    else{
        cout << "Draw"  << endl;
    }
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