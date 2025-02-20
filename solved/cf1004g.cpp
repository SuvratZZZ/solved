#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define ull unsigned long long


#ifndef ONLINE_JUDGE
#include <chrono>
#endif
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
const int LLL = 2*1e5;

//ll JUD = 0;
//
//#ifdef ONLINE_JUDGE
//# define JUD 0
//#else
//# define JUD 1
//#endif


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
    ll n;cin>>n;vector<ll>a(n);
    ll res=0,pr=0;
    map<ll,ll> pri,sem;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for (ll  i = 0; i < n ; i++)
    {
        if(sml_fctr[a[i]]==a[i]){
            res+=pr-pri[a[i]];
            // cout << a[i] << " <- added : " << pr-pri[a[i]] << endl;
            pr++;
            pri[a[i]]++;
        }
        else if(sml_fctr[sml_fctr[a[i]]]==sml_fctr[a[i]]&&sml_fctr[a[i]/sml_fctr[a[i]]]==a[i]/sml_fctr[a[i]]){
            sem[a[i]]++;
            res+=sem[a[i]];
            res+=pri[a[i]/sml_fctr[a[i]]];
            if(a[i]/sml_fctr[a[i]]!=sml_fctr[a[i]]){
                res+=pri[sml_fctr[a[i]]];
                // cout << a[i] << " <- added : " << sem[a[i]]+pri[a[i]/sml_fctr[a[i]]]+pri[sml_fctr[a[i]]] << endl;
            }
            else{
                // cout << a[i] << " <- added : " << sem[a[i]]+pri[a[i]/sml_fctr[a[i]]] << endl;
            }
        }
    }
    cout << res << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
        auto start = std::chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    #ifndef ONLINE_JUDGE
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> duration = end - start;
        std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    #endif
    return 0;
}