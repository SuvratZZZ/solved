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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    // map<ll,ll> mp;
    ll r=0;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        r+=a[i];
        // mp[a[i]]++;
    }
    // a.clear();
    // for(auto i:mp){
    //     a.push_back(i.second);
    // }
    sort(a.rbegin(),a.rend());
    r+=k;
    auto che=[&](const ll mid)->bool{
        ll res=0;
        for (ll  i = 0; i < n ; i++)
        {
            res+=max(0ll,(ll)ceil(((n+mid-1-i)*1.0)/n)-a[i]);
        // cout << "a[i]: " << a[i] << ", r: " << max(0ll,(ll)ceil(((n+mid-2-i)*1.0)/n)-a[i])<< ", mid: " << mid << endl;
        }
        return res<=k;
    };
    ll l=0;
    while (l<r)
    {
        ll mid=(l+r+1)/2;
        if(che(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << l << endl;
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