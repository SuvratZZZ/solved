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
    ll n,k;
    cin>>n>>k;
    vector<ll> cos(n);
    vector<ll> cos2(n,-1);
    // vector<ll> cos3(n);
    vector<ll> hsh(n,0);
    vector<vector<ll>> gra(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> cos[i];
    }
    for (ll  i = 0; i < k ; i++)
    {
        ll  tem;
        cin>>tem;
        hsh[tem-1]=1;
    }
    for (ll  i = 0; i < n ; i++)
    {
        ll tem=0;
        cin>>tem;
        ll res=0;
        for (ll j  = 0; j  < tem ; j ++)
        {
            ll tem2;
            cin >> tem2;
            gra[i].push_back(tem2-1);
        }
    }
    vector<ll> vis(n,-1);
    // vector<ll> v2(n,-1);
    // vector<ll> top;
    // function<void(ll)> cc=[&](ll ind)->void{
    //     v2[ind]=1;
    //     for(auto i:gra[ind]){
    //         if(v2[i]==-1)
    //         cc(i);
    //     }
    //     top.push_back(ind);
    // };
    // for (ll  i = 0; i < n ; i++)
    // {
    //     if(v2[i]==-1)
    //     cc(i);
    // }
    function<ll(ll)> che=[&](ll ind)->ll{
        vis[ind]=1;
        if(hsh[ind]==1){
            return cos2[ind]=0;
        }
        if(gra[ind].size()==0){
            return cos2[ind]=cos[ind];
        }
        if(cos2[ind]!=-1)return cos2[ind];
        ll sum =0;
        for(auto i:gra[ind]){
            // if(vis[i]==-1){
                sum+=che(i);
            // }
        }
        // if(sum==0)
        // return cos2[ind]=cos[ind];
        return cos2[ind]=min(sum,cos[ind]);
    };

    for (ll  i = 0; i < n ; i++)
    {
        // cout << top[i] << " ti " << endl;
        if(vis[i]==-1){
            che(i);
        }
    }
    
    for(auto i:cos2){
        cout << i << " ";
    }
    cout << endl;
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