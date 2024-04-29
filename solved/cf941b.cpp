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
    ll n,m;
    cin>>n>>m;
    vector<string> vv(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>vv[i];
    }
    if (vv[0][0]==vv[n-1][m-1])
    {
        cout << "YES" << endl;
    }
    else if(vv[0][m-1]==vv[n-1][0])
    {
        cout << "YES" << endl;
    }
    else{
        bool ra =0,ra1=0,ra2=0;
        for (ll  i = 0; i < n ; i++)
        {
            if (vv[0][0]!=vv[i][0])
            {
                ra1=1;
                break;
            }
            
        }
        for (ll  i = 0; i < m ; i++)
        {
            if (vv[0][i]!=vv[0][0])
            {
                ra2=1;
                break;
            }
            
        }
        if((ra1==1)&&(ra2==1)){
            cout << "YES" << endl;
            return;
        }
        ra =0;ra1=0;ra2=0;
        for (ll  i = 0; i < n ; i++)
        {
            if (vv[n-1][m-1]!=vv[i][m-1])
            {
                ra1=1;
                break;
            }
            
        }
        for (ll  i = 0; i < m ; i++)
        {
            if (vv[n-1][i]!=vv[n-1][m-1])
            {
                ra2=1;
                break;
            }
            
        }
        if((ra1==1)&&(ra2==1)){
            cout << "YES" << endl;
            return;
        }
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