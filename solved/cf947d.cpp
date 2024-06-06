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
bool dfs2(int ind,int par,vector<vector<int>> &gra,vector<int> &vis,vector<int> &path){
        // cout << ind << " . " ;
    vis[ind]=1;
    if(ind==par){
        path.push_back(ind);
        return 1;
    }
    bool m1=0,m2=0;
    for (int  i = 0; i < gra[ind].size(); i++)
    {
        if(vis[gra[ind][i]]==-1){
            m2=dfs2(gra[ind][i],par,gra,vis,path);
            m1=m2||m1;
            if(m2==1){
                path.push_back(ind);
                // cout << ind << " . " ;
            }
        }
    }
    // cout << "node : " << ind << " , return : " << res-m1+1 << endl;
    return m1||0;
}
int dfs(int ind,vector<vector<int>> &gra,vector<int> &vis){
    vis[ind]=1;
    int m1=0,m2=0;
    for (int  i = 0; i < gra[ind].size(); i++)
    {
        if(vis[gra[ind][i]]==-1){
            m2=dfs(gra[ind][i],gra,vis);
            m1=max(m1,m2);
        }
    }
    // cout << "node : " << ind << " , return : " << res-m1+1 << endl;
    return m1+1;
}
void solve(){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    vector<vector<int>> gra(n+1);
    for (ll  i = 0; i < n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    // for(auto i:gra){
    //     for(auto j:i){
    //         cout << j << " " ;
    //     }
    //     cout << endl;
    // }
    int ans=0,cou=1;
    if(a!=b){
        vector<int> vis(n+1,-1);
        queue<int> q;
        q.push(b);
        vis[b]=1;
        while(!q.empty()){
            int flag=0;
            int lwa=q.size();
            for (int  i = 0; i < lwa ; i++)
            {
                int curr=q.front();
                q.pop();
                for(int j=0;j<(int)gra[curr].size();j++){
                    if(vis[gra[curr][j]]==-1){
                        if(gra[curr][j]==a){
                            ans=cou;
                            flag=1;
                        }
                        q.push(gra[curr][j]);
                        vis[gra[curr][j]]=1;
                    }
                }
            }
            if(flag==1){
                break;
            }
            // cout << "done" << endl;
            cou++;
        }
    }
    vector<int> vis(n+1,-1);
    vector<int> path;
    dfs2(b,a,gra,vis,path);
    vis.clear();
    vector<int> v2(n+1,-1);
    int mi=path[(path.size()-1)/2];
    int a2 = dfs(mi,gra,v2)-1;
    // cout << mi  << " : mi < res: " << a2 << endl;
    // for(auto i:path){
    //     cout << i << ' ';
    // }
    if(ans){
        // cout << (2*((ans+1)/2))+a2 << endl;
    }
    cout << 2*(n-1)-a2+(path.size()/2) << endl;
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