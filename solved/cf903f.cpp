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
ll bfs(ll ind,vector<vector<ll>> &gra,vector<ll> &hsh,ll &mx){
    cout << " bfs from : " << ind << endl;
    queue<ll> q;
    q.push(ind);
    vector<ll> vis(gra.size(),0);
    vis[ind]=1;
    ll res=0;
    ll lev=1;
    while (!q.empty())
    {
        ll loops=q.size();
        for (ll  i = 0; i < loops; i++)
        {
            ll curr=q.front();
            q.pop();
            // cout << " q.size() ; " << q.size() <<  endl;
            // cout << " at lev : " << curr  << " val lev : " << lev << endl;
            for (ll i = 0; i < gra[curr].size(); i++)
            {
                if (vis[gra[curr][i]]==0&&hsh[gra[curr][i]]==1)
                {
                    q.push(gra[curr][i]);
                    vis[gra[curr][i]]=1;
                    if(lev>res){
                        res=max(lev,res);
                        mx=gra[curr][i];
                    }
                    cout << " curr hsh  : " << gra[curr][i] << " res : " << res << " lev : " << lev << endl;
                }
                
                if (vis[gra[curr][i]]==0)
                {
                    q.push(gra[curr][i]);
                    vis[gra[curr][i]]=1;
                    cout << " curr  : " << gra[curr][i] << " res : " << res << " lev : " << lev << endl;
                }
                
            }
                
        }
        // cout << " loo p endl " << endl;
        lev++;
    }
    
    return res;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> hsh(n+1,0);
    vector<ll> krr(n);
    vector<vector<ll>> gra(n+1);
    for (ll  i = 0; i < k ; i++)
    {
        cin>> krr[i];
        hsh[krr[i]]=1;
    }
    for (ll  i = 0; i < n-1; i++)
    {
        ll t1,t2;
        cin>>t1>>t2;
        gra[t1].push_back(t2);
        gra[t2].push_back(t1);
    }
    ll res=INT_MAX;
    if(k==1){
        cout << 0 << endl;
    }
    else{
        ll mx=0,m2;
            res=bfs(krr[0],gra,hsh,mx);
            res=max(res,bfs(mx,gra,hsh,m2));
        cout << (res+1)/2 << endl;
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