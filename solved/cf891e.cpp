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
    ll n;
    cin>> n;
    vector<ll> v(n);
    set<ll> s;
    map<ll,ll> m;
    map<ll,ll> res;

    for (ll  i = 0; i < n ; i++)
    {
        cin>>v[i];
        s.insert(v[i]);
        m[v[i]]++;
    }
    ll sum=0,tem;
    for(auto i:s){
        if(i==*s.begin()){
            tem=i;
            continue;
        }
        sum+=((i-tem)*m[i]);
    }
    res[*s.begin()]=sum+n;
    // cout << "sum :" << sum  << endl;
    ll ind=0;
    ll rig=n;
    ll lef=m[*s.begin()];
    for(auto i:s){
        if(i==*s.begin()){
            tem=i;
            continue;
        }
        res[i]=sum+(((2*lef)-n)*(i-tem))+n;
        sum=res[i]-n;
        lef+=m[i];
        tem=i;
    }
    for (ll  i = 0; i < n ; i++)
    {
        cout << res[v[i]] << " " ;
    }
    cout << endl;
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