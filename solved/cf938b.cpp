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
    ll n,c,d,mn=INT_MAX;
    cin>>n>>c>>d;
    map<ll,ll> m;
    for (ll  i = 0; i < n*n ; i++)
    {
        ll tem=0;cin>>tem;
        m[tem]++;
        mn=min(tem,mn);
    }
    ll tem=mn,check=1;
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j  = 0; j  < n ; j ++)
        {
            if (m[tem+(j*d)]==0)
            {
                // cout << "not fou" << tem+(j*d) << endl;
                check=0;
            }
            if (m[tem+(j*d)]>0)
            {
                m[tem+(j*d)]--;
            }
            
        }
        tem=tem+c;
    }
    if (check==1)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
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