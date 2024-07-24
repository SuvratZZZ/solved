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
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> msb(n);
    vector<ll> bb(32,0);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        for (ll  j = 0; j < 32; j++)
        {
            if(a[i]&(1<<j)){
                bb[j]=1;
                msb[i]=j;
            }
        }
    }
    ll up=0,res=0;
    for (ll i = 0; i < 32; i++)
    {
        // cout << i << " i BB " << bb[i] << endl;
        if(bb[i]!=1){
            break;
        }
        else{
            up=i;
        }
    }
    // cout << "up : " << up << endl;
    for (ll i = 0; i < n ; i++)
    {
        if(msb[i]>up){
            res++;
        }
        // cout << a[i] << " a,msb : " << msb[i] << endl;
    }
    cout << res << endl;
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