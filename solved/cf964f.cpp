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
    vector<ll> inv(200000+1);
	vector<ll> fact(200000+1);
	vector<ll> fact_inv(200000+1);

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll co=0,cz=0;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(a[i])co++;
        else cz++;
    }
	auto comb = [&](int n, int k){
		if (n<0 || k<0) return 0LL;
		if (n < k) return 0LL;
		return fact[n]*fact_inv[n-k] % mod * fact_inv[k] % mod;
	};
    ll res=0;
    for (ll  i = (k/2)+1; i <= co && i <= k ; i++)
    {
        res+=comb(co,i)*comb(cz,k-i);
    }
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
	inv[1] = 1;
	for(int i=2; i<200000+1; i++){
		inv[i] = mod - (mod/i) * inv[mod%i] % mod;
	}
	fact[0] = 1; 
	fact_inv[0] = 1; 
	for(int i=1; i<200000+1; i++){
		fact[i] = fact[i-1]*i % mod;
		fact_inv[i] = fact_inv[i-1]*inv[i] % mod;
	}
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}