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
ll sol(ll ind,ll tak,vector<ll> &zz,vector<vector<ll>> &dp){

}
void solve(){
    ll n;
    cin>>n;
    vector<ll> t(n);
    vector<ll> zz;
    map<ll,ll> mp;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>t[i];
        mp[t[i]]++;
    }
    for(auto i:mp){
        cout << i.first << " : " << i.second << endl;
        zz.push_back(i.second);
    }
    ll mov=mp.size();
    cout << mov << " = m " << endl;
    vector<vector<ll>> dp(zz.size()+1,vector<ll>(mov+2,0));
    for (ll  i =1; i <n ; i++)
    {
        for (ll  j = 0; j <= mov ; j++)
        {
            ll r1=0,r2;
            if(j>=zz[i]){
                if(i+1-dp[i-1][j-zz[i]]>zz[i]){
                    r1=1+dp[i-1][j-zz[i]];
                }
            }
            r2=dp[i-1][j];
            dp[i][j]=max(r1,r2);
        }
    }
    cout << dp[n-1][mov] << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    // THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}