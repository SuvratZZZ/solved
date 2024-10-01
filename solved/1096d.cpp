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
# define fall(f) for(auto i:f){cout << i << " ";}cout << endl
# define ftd(f) for(auto i:f){for(auto j:i){cout << j << " ";}cout << endl;}cout << endl
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
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(4,0));
    dp[0][1]=1e9;dp[0][2]=1e9;dp[0][3]=1e9;
    for (ll  i = 0; i < n ; i++)
    {
            if(s[i]=='h'){
                dp[i+1][0]=dp[i][0]+a[i];
                dp[i+1][1]=min(dp[i][1],dp[i][0]);
                dp[i+1][2]=dp[i][2];
                dp[i+1][3]=dp[i][3];
                continue;
            }
            if(s[i]=='a'){
                dp[i+1][0]=dp[i][0];
                dp[i+1][1]=dp[i][1]+a[i];
                dp[i+1][2]=min(dp[i][2],dp[i][1]);
                dp[i+1][3]=dp[i][3];
                continue;
            }
            if(s[i]=='r'){
                dp[i+1][0]=dp[i][0];
                dp[i+1][1]=dp[i][1];
                dp[i+1][2]=dp[i][2]+a[i];
                dp[i+1][3]=min(dp[i][3],dp[i][2]);
                continue;
            }
            if(s[i]=='d'){
                dp[i+1][0]=dp[i][0];
                dp[i+1][1]=dp[i][1];
                dp[i+1][2]=dp[i][2];
                dp[i+1][3]=dp[i][3]+a[i];
                continue;
            }
                dp[i+1][0]=dp[i][0];
                dp[i+1][1]=dp[i][1];
                dp[i+1][2]=dp[i][2];
                dp[i+1][3]=dp[i][3];
    }
    cout << *min_element(dp[n].begin(),dp[n].end()) << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}