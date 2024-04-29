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
    ll n,s1,s2;
    cin>>n>>s1>>s2;
    vector<ll> r(n),r1,r2;
    vector<pair<ll,ll>> mm(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>r[i];
        mm[i]={r[i],i+1};
    }
    sort(mm.begin(),mm.end());
    for (auto  it = mm.rbegin(); it != mm.rend() ; it++)
    {
        // cout << it->second << " : sec , fir : " << it->first << endl;
        if ((r1.size()+1)*s1>(r2.size()+1)*s2)
        {
            r2.push_back(it->second);
        }
        else{
            r1.push_back(it->second);
        }
    }
    cout << r1.size() << " " ;
    for(ll i:r1)cout << i << " " ;
    cout << endl;
    cout << r2.size() << " " ;
    for(ll i:r2)cout << i << " " ;
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