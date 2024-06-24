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
ll poo(ll a,ll n){
    ll tem = 1;
    while (n>0)
    {
        if(n%2==1){
            tem=(tem*a)%mod;
            n--;
        }
        else{
            a=(a*a)%mod;
            n/=2;
        }
    }
    return tem%mod;
}
void solve(){
    ll l,r,k;
    cin>>l>>r>>k;
    ll res=0,too=ceil(10.0/k);
    // cout << res << " r : t " << too << endl;
    res=((too-1)*poo(too,l))%mod;
    // cout << res << " r : aat " << poo(too,l) << endl;
    res=(res*((poo(too,r-l)%mod)+mod-1))%mod;
    // cout << res << " r : +t " << ((poo(too,r-l)%mod)-1) << endl;
    res=(res*poo(too-1,mod-2))%mod;
    // cout << res << " r : //t " <<poo(too-1,mod-2)<< endl;
    
    cout << res << endl;
    // cout << poo(2,2) << endl;
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