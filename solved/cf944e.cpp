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
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(k+1,0),b(k+1,0);
    for (ll  i = 1; i <= k ; i++)
    {
        cin>>a[i];
    }
    for (ll  i = 1; i <= k ; i++)
    {
        cin>>b[i];
    }
    for (ll  i = 0; i < q ; i++)
    {
        ll tem;
        cin>>tem;
        ll re=lower_bound(a.begin(),a.end(),tem)-a.begin();
        if(a[re]==tem){
            cout <<  b[re] << " ";
            continue;
        }
        re=b[re-1]+((b[re]-b[re-1])*(tem-a[re-1]))/(a[re]-a[re-1]);
        cout <<  re << " ";
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