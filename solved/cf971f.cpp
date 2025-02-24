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
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    vector<ll> ps(n+1,0);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        ps[i+1]=ps[i]+a[i];
    }
    for (ll  i = 0; i < q ; i++)
    {
        ll l,r,res=0;
        cin>>l>>r;
        l--;r--;
        // ll fe=(l/n)+(l%n!=0),ls=(r/n)+(r%n!=0);
        ll fe=(l/n),ls=(r/n);
        res+=max(0ll,(ls-fe-1))*ps[n];
        l=(l%n);
        r=(r%n);
        if(ls==fe){
            l=(l+fe)%n;
            r=(r+fe)%n;
            if(l<=r)
                res+=(ps[r+1]-ps[l]);
            else
                res+=(ps[n]-ps[l]+ps[r+1]-ps[0]);
        }
        else{
            ll l2=(l+fe)%n;
            ll r2=(n-1+fe)%n;
            if(l2<=r2)
                res+=(ps[r2+1]-ps[l2]);
            else
                res+=(ps[n]-ps[l2]+ps[r2+1]-ps[0]);
            l2=(0+ls)%n;
            r2=(r+ls)%n;
            if(l2<=r2)
                res+=(ps[r2+1]-ps[l2]);
            else
                res+=(ps[n]-ps[l2]+ps[r2+1]-ps[0]);
        }
        cout << res << endl;
    }
    
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