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
void solve(){
    ll n,m,h;
    cin>>n>>m>>h;
    vector<ll> ho(n,0);
    vector<vector<ll>> disl(n,vector<ll>(2,LLONG_MAX));
    vector<vector<ll>> diso(n,vector<ll>(2,LLONG_MAX));
    for (ll  i = 0; i < h ; i++)
    {
        ll tem;
        cin>>tem;
        tem--;
        ho[tem]++;
    }
    vector<vector<vector<ll>>> gra(n);
    for (ll  i = 0; i < m ; i++)
    {
        ll  p,q,r;
        cin>>p>>q>>r;
        p--;q--;
        gra[p].push_back({q,r});
        gra[q].push_back({p,r});
    }
    set<vector<ll>> qq;
    qq.insert({0,0,(ho[0]==0)?1:2});
    diso[0][0]=0;
    if(ho[0])
        diso[0][1]=0;
    while (!qq.empty())
    {
        vector<ll> tem=*qq.begin();
        ll toat=tem[0];
        ll at=tem[1];
        ll gho=tem[2];
        qq.erase(qq.begin());
        for(auto i:gra[at]){
            if(gho==2||ho[i[0]]!=0){
                if(diso[i[0]][1]>toat+(i[1]/gho)){
                    qq.erase({diso[i[0]][1],i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                    diso[i[0]][1]=toat+(i[1]/gho);
                    qq.insert({toat+(i[1]/gho),i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                }
            }
            else
            {   
                if(diso[i[0]][0]>toat+(i[1]/gho)){
                    qq.erase({diso[i[0]][0],i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                    diso[i[0]][0]=toat+(i[1]/gho);
                    qq.insert({toat+(i[1]/gho),i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                }
            }
        }
    }
    qq.clear();
    qq.insert({0,n-1,ho[n-1]==0?1:2});
    disl[n-1][0]=0;
    if(ho[n-1])
        disl[n-1][1]=0;
    while (!qq.empty())
    {
        vector<ll> tem=*qq.begin();
        ll toat=tem[0];
        ll at=tem[1];
        ll gho=tem[2];
        qq.erase(qq.begin());
        for(auto i:gra[at]){
            if(gho==2||ho[i[0]]!=0){
                if(disl[i[0]][1]>toat+(i[1]/gho)){
                    qq.erase({disl[i[0]][1],i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                    disl[i[0]][1]=toat+(i[1]/gho);
                    qq.insert({toat+(i[1]/gho),i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                }
            }
            else
            {   
                if(disl[i[0]][0]>toat+(i[1]/gho)){
                    qq.erase({disl[i[0]][0],i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                    disl[i[0]][0]=toat+(i[1]/gho);
                    qq.insert({toat+(i[1]/gho),i[0],(ho[i[0]]!=0||gho!=1)?2:1});
                }
            }
        }
    }

    ll ans=LLONG_MAX;
    for (ll  i = 0; i < n ; i++)
    {
        ans=min(ans,max(min(diso[i][0],diso[i][1]),min(disl[i][0],disl[i][1])));
    }
    // cout << " 00 : " << endl;
    // for(auto i:diso)
    // cout << i << " ";
    // cout << endl;
    // cout << " ll : " << endl;
    // for(auto i:disl)
    // cout << i << " ";
    // cout << endl;
    if(ans==LLONG_MAX)ans=-1;
    cout << ans << endl;
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