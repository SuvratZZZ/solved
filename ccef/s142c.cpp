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
// const int LLL = 1e9+7;
// int sml_fctr[LLL];
// void fill_factor(){
//     for(int i=0;i<=LLL;i++){
//         sml_fctr[i]=i;
//     }
//     for(int i=2;i*i<=LLL;i++){
//         for(int j=i*i;j<=LLL;j=j+i){
//             if(sml_fctr[j]==j){
//                 sml_fctr[j]=i;
//             }
//         }
//     }
// }
// vector<int> fin_factor(int n){
//     // will not have 1 as prime
//     vector<int> res;
//     int tt=n;
//     while(tt!=1){
//         res.push_back(sml_fctr[tt]);
//         tt=tt/sml_fctr[tt];
//     }
//     return res;
// }
// vector<ll> sieve(ll n) {
//     vector<bool> isPrime(n+1, true);
//     vector<ll> primes;
//     for (ll p = 2; p * p <= n; ++p) {
//         if (isPrime[p]) {
//             for (ll i = p * p; i <= n; i += p)
//                 isPrime[i] = false;
//         }
//     }
//     for (ll p = 2; p <= n; ++p)
//         if (isPrime[p])
//             primes.push_back(p);
//     return primes;
// }
bool ime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
void solve(){
    ll x,cou=0;
    cin>>x;
    ll res = 1;
    for (int  i = x; cou < 2; i++)
    {
        if(ime(i)==1){
            res=res*((ll)i);
            cou++;
        }
    }
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
    // fill_factor();
    // vector<ll> pp=sieve(mod);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}