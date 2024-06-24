#include <bits/stdc++.h>
using namespace std;
# define ll long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
const ll mod = 1e9+7;
const int LLL = 1e6+5;
int sml_fctr[LLL];
void fill_factor(){
    for(int i=0;i<=LLL;i++){
        sml_fctr[i]=i;
    }
    for(int i=2;i*i<=LLL;i++){
        for(int j=i*i;j<=LLL;j=j+i){
            if(sml_fctr[j]==j){
                sml_fctr[j]=i;
            }
        }
    }
}
vector<int> fin_factor(int n){
    // will not have 1 as prime
    vector<int> res;
    int tt=n;
    while(tt!=1){
        res.push_back(sml_fctr[tt]);
        tt=tt/sml_fctr[tt];
    }
    return res;
}
ll dfs(ll ind,vector<vector<ll>> &tri,vector<ll> &vis,vector<ll> &chu){
    vis[ind]=1;
    if(chu[ind]!=-1)return chu[ind];
    bool res=0;
    for(auto i:tri[ind]){
        if(vis[i]==-1){
            res=res|(!dfs(i,tri,vis,chu));
        }
    }
    cout << ind << " at i , val : " << res << endl;
    return chu[ind]=res ;
}
void solve(vector<vector<ll>> &tri,vector<ll> &chu){
    ll n=tri.size()-1,t;
    cin >> t;
    vector<ll> vis(n+1,-1);
    if(chu[t]==-1)
    {
        if(dfs(t,tri,vis,chu)==1)
            cout <<"Ron" << endl;
        else
            cout <<"Hermione" << endl;
    }
    else{
        bool res=0;
        for(auto i:tri[t]){
            res=res|(!chu[i]);
        }
        if(res==1)
            cout <<"ggRon" << endl;
        else
            cout <<"ggHermione" << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    //fill_factor()
    ll t=1,n;
    cin >> n >> t;
    vector<vector<ll>> tri(n+1);
    vector<ll> chu(n+1,-1);
    for (ll  i = 0; i < n-1; i++)
    {
        ll t1,t2;
        cin>>t1>>t2;
        tri[t1].push_back(t2);
        tri[t2].push_back(t1);
    }
    while(t--){
        solve(tri,chu);
    }
    return 0;
}