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
    cin>>n;
    vector<int> a(n);
    map<string,int> fir2;
    map<string,int> la2;
    map<string,int> mm2;
    map<string,int> same;
    
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if (i>1)
        {
            string f2=to_string(a[i-2])+','+to_string(a[i-1]);
            string l2=to_string(a[i-1])+','+to_string(a[i]);
            string m2=to_string(a[i-2])+','+to_string(a[i]);
            string s2=to_string(a[i-2])+','+to_string(a[i-1])+','+to_string(a[i]);
            fir2[f2]++;
            la2[l2]++;
            mm2[m2]++;
            same[s2]++;
        }
    }
    // for(auto i:same){
    //     cout << i.first << " j " << i.second << endl;
    // }
    ll res=0;
    for (ll  i = 2; i < n ; i++)
    {
            string f2=to_string(a[i-2])+','+to_string(a[i-1]);
            string l2=to_string(a[i-1])+','+to_string(a[i]);
            string m2=to_string(a[i-2])+','+to_string(a[i]);
            string s2=to_string(a[i-2])+','+to_string(a[i-1])+','+to_string(a[i]);
        res+=(fir2[f2]+la2[l2]+mm2[m2]-(3*same[s2]));
    }
    cout << res/2 << endl;
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