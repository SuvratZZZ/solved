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
// ll factmod(ll n, ll p) {
//     // vector<ll> f(p);
//     // f[0] = 1;
//     // for (ll i = 1; i < p; i++)
//     //     f[i] = f[i-1] * i % p;

//     ll res = 1;
//     // while (n > 1) {
//     //     if ((n/p) % 2)
//     //         res = p - res;
//     //     res = res * f[n%p] % p;
//     //     n /= p;
//     // }
//     return res;
// }
long long factmod(ll n, ll M) {
    long long res = 1;
    
    for (ll i = 2; i <= n; i++) {
        res = (res * i) % M;
    }
    
    return res;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(2*n);
    for (ll  i = 0; i < 2*n ; i++)
    {
        cin>>a[i];
    }
    ll bda=0,cho=0,both=0;
    for (ll  i = 1; i < 2*n ; i=i+2)
    {
        if((max(a[i-1],a[i])!=0)&&(max(a[i-1],a[i])>(n))&&(min(a[i-1],a[i])==0))bda++;
        else if((max(a[i-1],a[i])!=0)&&(max(a[i-1],a[i])<=(n))&&(min(a[i-1],a[i])==0))cho++;
        else if(a[i-1]==0&&a[i]==0){
            both++;
            bda++;
            cho++;
        }
    }
    // cout << bda << " b c " << cho << " bo " << both << endl;
    // for (ll  i = 1 ; i < 10 ; i++)
    // {
    //     cout << factmod(i,M) << " b c " << endl;
    // }
    ll res=((factmod(bda,M)*factmod(cho,M))%M)*((both==0?1:(2*both)%M))%M;
    res%=M;
    cout << res << endl;
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