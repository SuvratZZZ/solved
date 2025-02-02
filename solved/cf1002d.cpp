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
    vector<vll> d1;
    vector<vll> d2;
    vector<set<ll>> gr1,gr2;

void comp(ll at,map<ll,ll> &onpa,ll st){
    if(st!=1){
        onpa[at]=1;
    }
    for(auto i:gr1[at]){
        if(gr2[at].find(i)!=gr2[at].end()){
            if(st==1){onpa[at]=1;}
            if(onpa[i]!=1){
                comp(i,onpa,0);
            }
        }
    }
}
void solve(){
    ll n,s1,s2;cin>>n>>s1>>s2;
    ll m1;cin>>m1;
    gr1.clear();
    gr2.clear();
    gr1.resize(n);
    gr2.resize(n);
    for (ll  i = 0; i < m1 ; i++)
    {
        ll a,b;
        cin>>a>>b;a--;b--;
        gr1[a].insert(b);
        gr1[b].insert(a);
    }
    ll m2;cin>>m2;
    for (ll  i = 0; i < m2 ; i++)
    {
        ll a,b;
        cin>>a>>b;a--;b--;
        gr2[a].insert(b);
        gr2[b].insert(a);
    }
    d1.clear();d2.clear();
    d1.resize(n);
    d2.resize(n);
    for(auto &i:d1)i.resize(2);
    for(auto &i:d2)i.resize(2);
    map<ll,ll> onpa;
    for (ll  i = 0; i < n ; i++)
    {
        comp(i,onpa,1);
    }
    
    // for(auto i:onpa){cout << i.first << " = " << i.second << endl;}

    set<vector<ll>> pq;
    vvll dis(n,vll(n,INT_MAX));
    ll ans=INT_MAX;
    pq.insert({0,s1-1,s2-1});
    dis[s1-1][s2-1]=0;
    while (!pq.empty())
    {
        ll x=(*pq.begin())[1];
        ll y=(*pq.begin())[2];
        ll toat=(*pq.begin())[0];
        
        pq.erase(pq.begin());
        if(x==y){
            if(onpa[x]==1)
            {    
                ans=toat;
                break;
            }
        }
        for(auto i:gr1[x]){
            for(auto j:gr2[y]){
                if(dis[i][j]>toat+(abs(i-j))){
                    pq.insert({toat+abs(i-j),i,j});
                    dis[i][j]=toat+abs(i-j);
                }
            }
        }
    }
    // for(auto i:dis){for(auto j:i)cout << j << " ";cout << endl;}
    cout << (ans==INT_MAX?-1:ans) << endl;
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