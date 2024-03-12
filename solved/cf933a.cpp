#include <bits/stdc++.h>
using namespace std;
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
    ll n,m,k,count=0;
    cin >> n >> m >> k;
    vector < int> a(n),b(m);

    for (ll  i = 0; i < n ; i++)
    {
        cin >> a[i];
    }
    for (ll  i = 0; i < m ; i++)
    {
        cin >> b[i];
    }
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j  = 0; j  <m ; j ++)
        {
            if (a[i]+b[j]<=k)
            {
                count ++;
            }
            
        }
        
    }
    cout << count << endl;
    
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