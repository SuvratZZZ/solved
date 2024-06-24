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
    vector<ll> a(n),ans(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> a[i];
    }
    ll aa=1,tot=0;
    for (ll  i = 0; i < n ; i++)
    {
        aa=aa*(a[i]/__gcd(aa,a[i]));
    }
    for (ll  i = 0; i < n ; i++)
    {
        tot=tot+aa/a[i];
    }
    if(tot>=aa){
        cout << -1 << endl;
        return;
    }
    else{
        for (ll  i = 0; i < n ; i++)
        {
            ans[i]=aa/a[i];
        }
    }
    for(auto i:ans) cout << i << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor()
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}