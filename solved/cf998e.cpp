#include <bits/stdc++.h>
using namespace std;
# define ll long long


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
const int LLL = 1e6+5;

//ll JUD = 0;
//
//#ifdef ONLINE_JUDGE
//# define JUD 0
//#else
//# define JUD 1
//#endif

class CHU
{
public:
    vector<ll> prt,siz,ran;
    CHU(ll n){
        prt.resize(n+1);
        siz.resize(n+1,1);
        ran.resize(n+1,1);
        for (ll i = 0; i < n+1; i++)
        {
           prt[i]=i;
        }
    }
    ll fin_prt(ll n)
    {
        if(prt[n]==n)return n;
        else return prt[n]=fin_prt(prt[n]);
    }
    ll fin_siz(ll n){
        ll pp=fin_prt(n);
        return siz[pp];
    }
    void ubs(ll u,ll v)
    {
        ll pu=fin_prt(u);
        ll pv=fin_prt(v);
        if(pu!=pv){
            if (siz[pu]>siz[pv])
            {
                prt[pv]=pu;
                siz[pu]+=siz[pv];
            }
            else{
                prt[pu]=pv;
                siz[pv]+=siz[pu];
            }
        }
    }
};

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
void solve() {
    ll n, m1, m2;
    cin >> n >> m1 >> m2;

    CHU c1(n), c2(n);
    set<pair<ll, ll>> t1, t2;  // Sets to store edges of F and G
    ll res = 0;

    // Input edges for F
    for (ll i = 0; i < m1; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        t1.insert({a, b});
        c1.ubs(a, b);
    }

    // Input edges for G
    for (ll i = 0; i < m2; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        t2.insert({a, b});
        if (c1.fin_prt(a) != c1.fin_prt(b))
            c2.ubs(a, b);
    }

    // Check edges in G that are missing in F
    for (auto edge : t2) {
        ll u = edge.first, v = edge.second;
        if (c1.fin_prt(u) != c1.fin_prt(v)) {
            // Add this edge to F
            res++;
            c1.ubs(u, v);  // Update connectivity in F
        }
    }

    // Check edges in F that are not in G
    for (auto edge : t1) {
        ll u = edge.first, v = edge.second;
        if (c2.fin_prt(u) != c2.fin_prt(v)) {
            // Remove this edge from F
            res++;
            c2.ubs(u, v);  // Update connectivity in G for consistency
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
   //fill_factor();
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