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
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
ll exp( vector<ll>& arr) {
    ll n = arr.size();
    if (n < 2) {
        return 0; 
    }
    ll ts = 0; 
    // ll ts = accumulate(arr.begin(), arr.end(), 0LL); 

    for (ll  i = 0; i < n ; i++)
    {
        ts+=(arr[i]%mod);
        ts%mod;
    }
    ll ssq = 0;
    for (ll  i = 0; i < n ; i++) {
        ssq += ((arr[i]%mod)*(arr[i]%mod))%mod;
        ssq%=mod;
    }
    // ll sop = (ts*ts-ssq)/2;
    // ll top = ((n)*(n-1))/2;
    // ll expp=((sop)%mod*(top)%mod)%mod;
    // ll topi = mod_exp(top, mod - 2, mod);
    // ll rr = sop * topi % mod;

    ll inverse_2 = mod_exp(2, mod - 2, mod);
    ll sop = (((ts * ts )% mod )- ssq + mod) % mod;
    sop = (sop * inverse_2 )% mod;

    ll top = (((n)%mod * (n - 1))%mod * inverse_2) % mod;
    ll topi = mod_exp(top, mod - 2, mod); 
    ll rr = sop * topi % mod;

    return rr;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    cout << exp(a) << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //
    //
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}