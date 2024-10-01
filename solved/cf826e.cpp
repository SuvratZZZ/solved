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
# define fall(f) for(auto i:f){cout << i << " ";}cout << endl
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
    ll n;
    cin>>n;
    vector<ll> b(n);
    vector<bool> sp(n,0);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>b[i];
    }
    if(b[0]<n){
        sp[b[0]]=1;
    }
    for (ll  i = 1; i < n ; i++)
    {
        if(b[i]-i==0){
            sp[i]=1;
            if(i+1<n){if(i+1+b[i+1]<n)
            sp[i+1+b[i+1]]=1;}
        }
        if(i-b[i]-1>=0){
            sp[i]=sp[i]|sp[i-b[i]-1];
        }
        if(sp[i]==1){
            if(i+1<n){if(i+b[i+1]+1<n){
                sp[i+b[i+1]+1]=1;
            }}
        }
    }
    // for (ll  i = 1; i < n ; i++)
    // {
    //     if(b[i]-i==0){
    //         sp[i]=1;
    //         if(i+b[i+1]+1<n)
    //         sp[i+b[i+1]+1]=1;
    //     }
    //     if(i-b[i]-1>=0){
    //         sp[i]=sp[i]|sp[i-b[i]-1];
    //     }
    //     if(sp[i]==1){
    //         if(i+b[i+1]+1<n){
    //             sp[i+b[i+1]+1]=1;
    //         }
    //     }
    // }
    fall(sp);
    yn(sp[n-1]); 
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