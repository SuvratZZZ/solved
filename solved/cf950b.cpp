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
    ll n,f,k,rr;
    cin>>n>>f>>k;
    vector<int> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    rr=a[f-1];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll lb=-1,ub=-1;
    for (ll  i = 0; i < n ; i++)
    {
        if(a[i]==rr&&lb==-1){
            lb=i+1;
        }
        if(a[i]==rr){
            ub=i+1;
        }
    }
    if(k<lb){
        cout << "NO" << endl;
    }
    else if(k>=ub){
        cout << "YES" << endl;
    }
    else{
        cout << "MAYBE" << endl;
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