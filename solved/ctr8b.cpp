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
// ll mee(set<ll> &s){
//     ll res=0;
//     while (s.find(res)!=s.end())
//     {
//         res++;
//     }
//     return res;
// }
void solve(){
    ll n,meee=0;
    cin>> n;
    set<ll> tem;
    vector<ll> v(n),res(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> v[i];
        tem.insert(i);
        // if(i==n-1){
        //     res[i]=n-v[i];
        // }
        // else if (v[i]==1)
        // {
        //     res[i]=meee;
        //     meee++;
        // }
        // else
        //     res[i]=meee-v[i] ;
    }
    set<ll> s;
    for (ll  i = 0; i < n ; i++)
    {
        if (tem.find(meee-v[i])!=tem.end())
        {
            res[i]=meee-v[i];
            s.insert(meee-v[i]);
            tem.erase(meee-v[i]);
        }
        else{
            tem.erase(meee);
            res[i]=meee;
            s.insert(meee);
        }
        while (s.find(meee)!=s.end())
        {
            meee++;
        }
        
    }
    
    for (ll  i = 0; i < n ; i++)
    {
        cout << res[i] << " " ;
    }
    cout << endl ;
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