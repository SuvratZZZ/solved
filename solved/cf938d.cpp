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
    ll n,m,k;
    cin>>n>>m>>k;
    map<ll,ll> m1;
    map<ll,ll> m2;
    vector<ll> a(n),b(m);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> a[i];
    }
    for (ll  i = 0; i < m ; i++)
    {
        cin>> b[i];
        m1[b[i]]++;
    }
    ll res=0;
    ll have=0;
    for (ll  i = 0; i < m ; i++)
    {
        if (m1[a[i]]!=0)
        {
            if ((m2[a[i]]<m1[a[i]]))
            {
                have++;    
            }
            m2[a[i]]++;
        }
    }
    if(have>=k) res++;
    for (ll  i = m; i < n ; i++)
    {
        if (m1[a[i-m]]!=0)
        { 
            if (m2[a[i-m]]<=m1[a[i-m]])
            {
                have--; 
                // cout << "h dec " ;
            }
            m2[a[i-m]]--;
            // cout << " for " << a[i] << " m : " << m2[a[i-m]] << endl;
        }
        if ((m1[a[i]]!=0))
        {
            if ((m2[a[i]]<m1[a[i]]))
            {
                // cout << "h inc " ;
                have++;    
            }
            // cout << " for " << a[i] << " m : " << m2[a[i]] << endl;
            m2[a[i]]++;
        }
        if(have>=k) res++;
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