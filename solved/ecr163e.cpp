#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
//
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll re=0,mxi=INT_MIN;
    vector<ll> v,res;
    for (ll  i = 0; i < n ; i++)
    {
        v.push_back((i/k)+1);
        mxi=max(v[i],mxi);
        res.push_back(i+1);
    }
    // for(ll i:res){cout << i << " ";}cout << endl;
    // cout << mxi << endl;
    // for(ll i:v){cout << i << " ";}cout << endl;
    for (ll  i = 1; i <= mxi ; i++)
    {
        ll lef=(i-1)*k;
        ll rig=min(n-1,(i*k)-1);
        ll mid= (lef+rig)/2;
        // cout << lef << " : l R : " << rig << " MID: " << mid << endl;
        reverse(res.begin()+lef,res.begin()+mid+1);
        reverse(res.begin()+mid+1,res.begin()+rig+1);
    }
    for(ll i:res){cout << i << " ";}cout << endl;
    cout << mxi << endl;
    for(ll i:v){cout << i << " ";}cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}