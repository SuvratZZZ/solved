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

class sg_sm {
public:
    vector<vector<ll>> se;
    ll siz;
    sg_sm(vector<vector<ll>>& gra) {
        siz=gra.size();
        se.resize(4*siz+1);
        build(0,siz-1,0,gra);
    }
    
    void dfs(ll l,ll r,ll pa,ll ind,vector<vector<ll>> &gra){
        for(auto i:gra[ind]){
            if(i!=pa)
            dfs(l,r,ind,i,gra);
        }
        
    }
    void build(ll l,ll r,ll ind,vector<vector<ll>> &gra){
        if(l==r){
            se[ind]=gra[l];
            return ;
        }
        ll mid=(l+r)/2;
        build(l,mid,2*ind+1,gra);
        build(mid+1,r,2*ind+2,gra);
        se[ind]=se[2*ind+1]+se[2*ind+2];
        return;
    }

    void driver_up(ll l,ll r, ll ind, ll at, ll val){
        ll mid=(l+r)/2;
        if(l==r&&l==at){
            se[ind]=val;
            return;
        }
        if(mid>=at){
            driver_up(l,mid,2*ind+1,at,val);
            se[ind]=se[2*ind+1]+se[2*ind+2];
        }
        else{
            driver_up(mid+1,r,2*ind+2,at,val);
            se[ind]=se[2*ind+1]+se[2*ind+2];
        }
    }

    void update(ll at, ll val) {
        driver_up(0,siz-1,0,at,val);
    }
    
    ll driver_sum(ll al,ll ar ,ll l,ll r,ll ind){
        if(al>r || ar<l){
            return 0;
        }
        if(al>=l && ar<=r){
            return se[ind];
        }
        else{
            ll mid=(al+ar)/2;
            ll lef=driver_sum(al,mid,l,r,2*ind+1);
            ll rig=driver_sum(mid+1,ar,l,r,2*ind+2);
            return lef+rig;
        }
    }

    ll sumRange(ll l, ll r) {
        return driver_sum(0,siz-1,l,r,0);
    }
};
void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}