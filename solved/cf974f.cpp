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
# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
# define rfall(f) reverse(f.begin(),f.end());for(auto i:f){cout << i << " ";}cout << endl
# define fall(f) for(auto i:f){cout << i << " ";}cout << endl
# define ftd(f) for(auto i:f){for(auto j:i){cout << j << " ";}cout << endl;}
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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
vector<vector<ll>> dp;
ll dfs(ll ind,ll ta,ll c,ll pr,vector<vector<ll>> &tr,vector<ll> &a){
    if(dp[ind][ta]!=-1)return dp[ind][ta];
    ll res=0;
    ll sub=(ta==1?c:0);
    for(auto i:tr[ind]){
        if(i!=pr){
            res+=max(dfs(i,0,c,ind,tr,a)+sub,dfs(i,1,c,ind,tr,a)-sub)-sub;
        }
    }
    return dp[ind][ta]=ta==1?res+a[ind]:res;
}
void solve(){
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    vector<vector<ll>> gra(n);
    dp.clear();
    dp.resize(n);
    for(auto &i:dp){
        i.resize(2,-1);
    }
    for (ll  i = 0; i < n-1 ; i++)
    {
        ll p,q;
        cin>>p>>q;
        p--;q--;
        gra[p].push_back(q);
        gra[q].push_back(p);
    }
    cout << max(dfs(0,0,c,-1,gra,a),dfs(0,1,c,-1,gra,a)) << endl; 
    // for(auto i:dp){
    //     cout << i[0] << " ";
    // }
    //     cout << endl;
    // for(auto i:dp){
    //     cout << i[1] << " ";
    // }
    //     cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //DNP;
    //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}