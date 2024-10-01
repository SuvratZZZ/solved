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
vector<bool> isPrime(251,true);
vector<ll> sieve(ll n) {
    vector<ll> primes;
    // isPrime.resize(n+1, true);
    for (ll p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (ll i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
    for (ll p = 2; p <= n; ++p)
        if (isPrime[p])
            primes.push_back(p);
    return primes;
}
void solve(vector<ll> &pr){
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<ll,vector<ll>> hsh;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        hsh[a[i]].push_back(i);
    }
        // cout << j << " ";
        for (ll  i = 1; i < 101 ; i++)
        {
            for (ll  j  = 1; j  < 101; j ++)
            {
                if(i==j){
                    if(hsh[i].size()>=2&&isPrime[i+j]==0){
                        cout << hsh[i][0]+1 << " " << hsh[i][1]+1 << endl;
                        return;
                    }
                    continue;
                }
                if(hsh[i].size()>0&&hsh[j].size()>0)
                {
                    if(isPrime[i+j]==0){
                        cout << hsh[i][0]+1 << " " << hsh[j][0]+1 << endl;
                        return;
                    }
                    continue;
                }
                
            }
        }
    cout << -1 << endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    vector<ll> pr=sieve(250);
    ll t=1;
    cin >> t;
    while(t--){
        solve(pr);
    }
    return 0;
}