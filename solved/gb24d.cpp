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
# define xx first
# define yy second
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
const ll mod = 998244353;
const ll M = 1e9+7;
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
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}
void solve(){
    ll n,q;cin>>n>>q;
    vector<pair<ll,ll>> a(n),b(n);map<ll,ll> mp;
    vector<pair<ll,ll>> a2(n),b2(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i].first;a[i].second=i;
        a2[i].first=a[i].first;
    }
    for (ll  i = 0; i < n ; i++)
    {
        cin>>b[i].first;b[i].second=i;
        b2[i].first=b[i].first;
    }
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    ll pro=1;
    for (ll  i = 0; i < n ; i++)
    {
        pro=(pro*min(a[i].first,b[i].first))%mod;
        a2[a[i].yy].yy=i;
        b2[b[i].yy].yy=i;
    }
    for(auto i:a)cout << i.xx << " a " << i.yy << endl;
    for(auto i:b)cout << i.xx << " b " << i.yy << endl;
    for(auto i:a2)cout << i.xx << " a2 " << i.yy << endl;
    for(auto i:b2)cout << i.xx << " b2 " << i.yy << endl;
    vector<ll> res(q+1);
    res[0]=pro;
    for (ll  i = 0; i < q ; i++)
    {
        ll o,x;cin>>o;cin>>x;x--;
        if(o==1){
            auto che = upper_bound(a.begin(),a.end(),make_pair(a2[x].xx,(ll)1e6));
            che--;
            if(che-a.begin()==a2[x].yy){
                res[i+1]=(pro*(min(a2[x].xx+1,b[a2[x].yy].xx)*binpow(che->xx,mod-2))%mod)%mod;
            }
            else if(b[che-a.begin()].xx>che->xx){
                res[i+1]=(pro*(min(a2[x].xx+1,b[a2[x].yy].xx)*binpow(che->xx,mod-2))%mod)%mod;
                res[i+1]=(pro+(pro*binpow(che->xx,mod-2))%mod)%mod;
                pro=(pro+(pro*binpow(che->xx,mod-2))%mod)%mod;
            }
            else{
                res[i+1]=pro;
            }
            a2[x].xx+=1;
            a[a2[x].yy].xx+=1;
            cout << che-a.begin() << " t2t " << a2[x].yy << endl;
            swap(a2[x].yy,a2[che->yy].yy);
            swap(a[a2[x].yy],a[che-a.begin()]);
        }
        else{
            auto che = upper_bound(b.begin(),b.end(),make_pair(b2[x].xx,(ll)1e6));
            if(che!=b.begin()){
                che--;
            }
            if(a[che-b.begin()].xx>che->xx){
                res[i+1]=(pro+(pro*binpow(che->xx,mod-2))%mod)%mod;
                pro=(pro+(pro*binpow(che->xx,mod-2))%mod)%mod;
            }
            else{
                res[i+1]=pro;
            }
            b2[x].xx+=1;
            b[b2[x].yy].xx+=1;
            cout << che-b.begin() << " t2p-> " << b2[x].yy << endl;
            swap(b2[x].yy,b2[che->yy].yy);
            swap(b[b2[x].yy],b[che-b.begin()]);
        }
    }
    for(auto i:res)cout << i << " ";
    cout << endl;
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