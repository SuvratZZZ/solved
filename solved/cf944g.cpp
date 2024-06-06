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
    vector<int> arr(n);
    vector<int> a2(n);
    map<int,vector<int>> a;
    for (ll  i = 0; i < n ; i++)
    {
        cin>> arr[i];
        a2[i]=arr[i]/4;
        a[arr[i]/4].push_back(arr[i]);
    }
    for(auto it=a.begin();it!=a.end();it++){
        sort(it->second.begin(),it->second.end());
        reverse(it->second.begin(),it->second.end());
    }
    for (ll  i = 0; i < n ; i++)
    {
        ll tem=arr[i];
        arr[i]=*a[tem/4].rbegin();
        a[tem/4].pop_back();
    }
    for (ll  i = 0; i < n ; i++)
    {
        cout << arr[i] << " " ;
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