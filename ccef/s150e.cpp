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
ll fin(const string &s, ll k) {
    if (k <= 0 || s.empty()) return -1;
    ll count = 1;
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            count++;
            if (count == k) {
                return i - k + 1;
            }
        } else {
            count = 1; 
        }
    }
    return -1; 
}
void solve(){
    ll n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    bool lass=1,tw=1;
    // for (ll  i = 0; i < k ; i++)
    // {
    //     if(a[n-1-i]!=b[n-1-i])tw=0;
    //     if(i>0){
    //         if(b[n-1-i]!=b[n-i])lass=0;
    //     }
    // }
    if(a==b){cout << 0 << endl;return;}
    ll at=fin(b,k);
    if(at==-1){
        cout << -1 << endl;
        return ;
    }
    vector<pair<ll,char>> res;
    // cout << at << endl;
    // cout << n-k+1 << endl;
    for (ll  i = n-1; (i>(at+k)); i--)
    {
        res.push_back({i-k+2 , b[i]});
    }
    for (ll  i =0; i<at; i++)
    {
        // cout << " g " << endl;
        res.push_back({i+1 , b[i]});
    }
    res.push_back({at+1,b[at]});
    cout << res.size() << endl;
    for(auto i:res){
        cout << i.first << " " << i.second << endl;
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