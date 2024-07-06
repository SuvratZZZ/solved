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
class CHU
{
public:
    vector<ll> prt,siz,ran;
    CHU(ll n){
        prt.resize(n+1);
        siz.resize(n+1,1);
        ran.resize(n+1,1);
        for (ll i = 0; i < n+1; i++)
        {
           prt[i]=i;
        }
    }
    ll fin_prt(ll n)
    {
        if(prt[n]==n)return n;
        else return prt[n]=fin_prt(prt[n]);
    }
    ll fin_siz(ll n){
        ll pp=fin_prt(n);
        return siz[pp];
    }
    void ubs(ll u,ll v)
    {
        ll pu=fin_prt(u);
        ll pv=fin_prt(v);
        if(pu!=pv){
            if (siz[pu]>siz[pv])
            {
                prt[pv]=pu;
                siz[pu]+=siz[pv];
            }
            else{
                prt[pu]=pv;
                siz[pv]+=siz[pu];
            }
        }
    }
};
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
void dfs(ll x,ll y,vector<string>&v,vector<vector<ll>>&vis,ll &cou,CHU &cha){
    vis[x][y]=1;
    cou++;
    ll dx[4]={0,-1,0,1};
    ll dy[4]={-1,0,1,0};
    for (ll  i = 0; i < 4 ; i++)
    {
        ll nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&nx<vis.size()&&ny>=0&&ny<vis[0].size()){
            if(vis[nx][ny]==0&&v[nx][ny]=='#'){
                cha.ubs((x*vis[0].size())+y,(nx*vis[0].size())+ny);
                dfs(nx,ny,v,vis,cou,cha);
            }
        }
    }
    vis[x][y]=cou;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<string> v(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>v[i];
    }
    vector<vector<ll>> vis(n,vector<ll>(m,0));
    vector<pair<ll,ll>> all;
    CHU cha(n*m+2);
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j = 0; j < m ; j++)
        {
            if(v[i][j]=='#'){
                all.push_back({i,j});
            }
        }
    }
    for(auto i:all){
        ll cou = 0;
        if(vis[i.first][i.second]==0){
            dfs(i.first,i.second,v,vis,cou,cha);
        }
    }
    // for(int i=0;i<n*m+1;i++){
    //     cout << cha.siz[i] << " seet prt " << cha.prt[i] << " for i = " << i << endl;
    // }
    // cout << "done";
    ll res=INT_MIN;
    for (ll  i = 0; i < n ; i++)
    {
        ll coo=0;
        set<ll> stt;
        // CHU tt=cha;
        for (ll  j  = 0; j  < m ; j ++)
        {
            if(v[i][j]=='.'){
                // tt.ubs(i*m+j,n*m+1);
                coo++;
            }
            else if (v[i][j] == '#') {
                // tt.ubs(i * m + j, n * m + 1);
                stt.insert(cha.fin_prt(i*m+j));
            }
            if (i > 0) {
                if (v[i - 1][j] == '#') {
                    // tt.ubs((i - 1) * m + j, n * m + 1);
                    stt.insert(cha.fin_prt((i-1)*m+j));
                }
            }
            if (i < n - 1) { 
                if (v[i + 1][j] == '#') {
                    // tt.ubs((i + 1) * m + j, n * m + 1);
                    stt.insert(cha.fin_prt((i+1)*m+j));
                }
            }
        }
        for(auto i:stt){
            coo+=cha.fin_siz(i);
        }
        res=max(res,coo);
        // cout << i << " for i res : " << coo << endl;
    }
    for (ll  j  = 0; j  < m ; j ++)
    {
        ll coo=0;
        set<ll> stt;
        // CHU tt=cha;
        for (ll  i = 0; i < n ; i++)
        {
            if(v[i][j]=='.'){
                // tt.ubs(i*m+j,n*m+1);
                coo++;
            }
            else if (v[i][j] == '#') {
                // tt.ubs(i * m + j, n * m + 1);
                stt.insert(cha.fin_prt(i*m+j));
            }
            if (j > 0) {
                if (v[i][j - 1] == '#') {
                    // tt.ubs(i * m + j - 1, n * m + 1);
                    stt.insert(cha.fin_prt(i*m+j-1));
                }
            }
            if (j < m - 1) {
                if (v[i][j + 1] == '#') {
                    // tt.ubs(i * m + j + 1, n * m + 1);
                    stt.insert(cha.fin_prt(i*m+j+1));
                }
            }
        }
        for(auto i:stt){
            coo+=cha.fin_siz(i);
        }
        res=max(res,coo);
        // res=max(res,tt.fin_siz(n*m+1)-1);
        // cout << j << " for jj res : " << coo << endl;
    }
    cout << res << endl;
    // 1 17
    // #.##....########.
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}