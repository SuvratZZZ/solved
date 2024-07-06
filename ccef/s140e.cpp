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
void dfs(queue<ll> &st,vector<ll> &vis,ll ind,vector<vector<ll>> &gra){
    vis[ind]=1;
    for(auto i:gra[ind]){
        if(vis[i]==-1){
            dfs(st,vis,i,gra);
        }
    }
    st.push(ind);
}
void solve(){
    ll n,mmm=INT_MAX,root;
    cin>>n;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(mmm>a[i]){
            mmm=a[i];
            root=i;
        }
    }
    vector<vector<ll>> gra(n);
    for (ll  i = 0; i < n-1; i++)
    {
        ll t1,t2;
        cin>>t1>>t2;
        t1--;t2--;
        gra[t1].push_back(t2);
        gra[t2].push_back(t1);
    }
    queue<ll> st;
    vector<ll> vis(n,-1);
    dfs(st,vis,root,gra);
    cout << n-1 << endl;
    while (st.size()!=1)
    {
        cout << st.front()+1 << " ";
        st.pop();
    }
    cout << endl;
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