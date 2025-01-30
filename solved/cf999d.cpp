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
const int LLL = 1e6+5;

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
class CHU
{
public:
    vector<ll> prt,siz,ran;
    CHU(ll n){
        prt.resize((ull)n+1);
        siz.resize((ull)n+1,1);
        ran.resize((ull)n+1,1);
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
bool fin(multiset<ll> &a,multiset<ll> &b,ll tem){
    if(a.find(tem)!=a.end()){
        a.erase(a.find(tem));
        return 1;
    }
    else if(tem==1){
        return 0;
    }
    else{
        return fin(a,b,(tem+1)/2)&&fin(a,b,tem/2);
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    multiset<ll> a;
    multiset<ll> b;
    for (ll  i = 0; i < n ; i++)
    {
        ll tem;
        cin>>tem;
        a.insert(tem);
    }
    for (ll  i = 0; i < m ; i++)
    {
        ll tem;
        cin>>tem;
        b.insert(tem);
    }
    for (auto i:b)
    {
        if(!fin(a,b,i)){
            yn(0);
            return;
        }
    }
    yn(a.empty());
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