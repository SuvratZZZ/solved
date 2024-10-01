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
// long long binpow(long long a, long long b) {
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a;
//         a = a * a;
//         b >>= 1;
//     }
//     return res;
// }

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll moe(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
    if (M == 1)
        return 0;

    while (A > 1) {
        ll q = A / M;
        ll t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
void solve(){
    string s;
    cin>>s;
    ll hsh1=0,hsh2=0,at=-1;
    ll n = s.length();
    for (ll  i = 0; i < n ; i++)
    {
        hsh1*=10;
        hsh1%=M;
        hsh1+=(ll)(s[i]-'a');
        hsh1%=M;
    }
    hsh2=hsh1;

    for (ll  i = 0; i < (n-1)/2 ; i++)
    {
        ll tem=(s[i]-'a');
        tem*=binpow(10,n-1-i,M);
        tem%=M;
        hsh1-=tem;
        hsh1+=M;hsh1%=M;
        hsh2-=(s[n-1-i]-'a');
        hsh2+=M;hsh2%=M;
        hsh2*=moe(10,M);hsh2%=M;
        hsh2+=M;hsh2%=M;
        if(hsh1==hsh2){
            at=i+1;
            break;
        }
        cout << i << " i hsh1 : " << hsh1 << " , hsh 2 : " << hsh2 << endl;
    }
    
    if(at!=-1){
        cout << "YES" << endl;
        for (ll  i = at; i < n ; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //DNP;
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}