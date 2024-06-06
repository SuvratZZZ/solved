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

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
long long lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

void solve(){
    ll n,lc=1;
    cin>>n;
    vector<ll> v(n);
    map<ll,ll> m;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>v[i];
        m[v[i]]++;
        lc=lcm(lc,v[i]);
    }
    // cout << lc << endl;
    ll res=n;
    while (m[lc]!=0)
    {
        if(m[lc]!=-1){
            res=res-m[lc];
        }
        m[lc]=INT_MAX;
        // cout << lc << "= lc 1 ," << endl;
        lc=1;
        for (ll  i = 0; i < n ; i++)
        {
            if(m[v[i]]==INT_MAX){
                // cout << v[i] << " = no , " ;
                continue;
            }
            else
            {
                lc=lcm(lc,v[i]);
            }
        }
        // cout << lc << " = lc 2," << endl;
    }
    cout << res << endl;
    
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