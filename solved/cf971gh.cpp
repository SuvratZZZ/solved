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
class sg_mx{
    private:
    void build(ll l,ll r,ll ind,vector<ll> &aa){
        if(l==r){
            se[ind]=aa[l];
            return;
        }
        ll mid=(l+r)/2;
        build(l,mid,2*ind+1,aa);
        build(mid+1,r,2*ind+2,aa);
        se[ind]=max(se[2*ind+1],se[2*ind+2]);
    }
    ll driver_mn(ll al,ll ar ,ll l,ll r,ll ind){
        if(al>r || ar<l){
            return INT_MIN;
        }
        if(al>=l && ar<=r){
            return se[ind];
        }
        else{
            ll mid=(al+ar)/2;
            ll lef=driver_mn(al,mid,l,r,2*ind+1);
            ll rig=driver_mn(mid+1,ar,l,r,2*ind+2);
            return max(lef,rig);
        }
    }
    ll driver_up(ll l,ll r, ll ind, ll at, ll val){
        ll mid=(l+r)/2;
        if(l==r&&l==at){
            se[ind]=val;
            return val;
        }
        if(mid>=at){
            ll tem=driver_up(l,mid,2*ind+1,at,val);
            se[ind]=max(se[ind],tem);
            return se[ind];
        }
        else{
            ll tem=driver_up(mid+1,r,2*ind+2,at,val);
            se[ind]=max(se[ind],tem);
            return se[ind];
        }
    }

	public:
    vector<ll> se;
    ll siz;
    sg_mx(vector<ll> &aa){
        siz=aa.size();
        se.resize(4*siz,INT_MIN);
        build(0,siz-1,0,aa);
    }

    ll f_mx(ll l,ll r){
        return driver_mn(0,siz-1,l,r,0);
    }

    void up(ll at,ll val){
        driver_up(0,siz-1,0,at,val);
    }
};

void so(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    sg_mx cc(a);
    ll q ;
    cin>> q;
    for (ll  i = 0; i < q ; i++)
    {
        ll l,r;
        cin>>l>>r;
        cout << cc.f_mx(l,r ) << endl;
    }
    
}
void solve(){
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(n);
    vector<ll> pre;
    for (ll  i = 0; i < n ; i++ )
    {
        cin>>a[i];
        a[i]=a[i]-i;
    }
    map<ll,ll> mp;ll mx=0,me=0;
    multiset<ll> freq;
    for (ll  i = 0; i < n ; i++)
    {
        if(i<k){
            if(mp[a[i]]==0){
                freq.insert(1);
            }
            else{
                freq.erase(freq.find(mp[a[i]]));
                freq.insert(mp[a[i]]+1);
            }
            mp[a[i]]++;
            // if(mp[a[i]]>mx){
            //     mx=mp[a[i]];
            //     me=a[i];
            // }
            if(i==k-1){
                // pre.push_back(mx);
                pre.push_back(*freq.rbegin());
            }
        }
        else{
            freq.erase(freq.find(mp[a[i-k]]));
            mp[a[i-k]]--;
            freq.insert(mp[a[i-k]]);
            if(mp[a[i]]==0){
                freq.insert(1);
            }
            else{
                freq.erase(freq.find(mp[a[i]]));
                freq.insert(mp[a[i]]+1);
            }
            mp[a[i]]++;
            pre.push_back(*freq.rbegin());
        }
    }
    sg_mx cc(pre);
    // for(auto i:a)cout << i << " ";cout << endl;
    for(auto i:pre)cout << i << " ";cout << endl;
    for (ll  i = 0; i < q ; i++)
    {
        ll l,r;
        cin>>l>>r;
        cout << cc.f_mx(l-1,r-k) << endl;
        // cout << k-(min(k,cc.f_mx(l-1,r-k))) << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // game theory jackson lewroy brown
    //
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
        // so();
    }
    return 0;
}