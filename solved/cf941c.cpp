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
    vector<ll> vv(n);
    set<ll> ss;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>vv[i];
        ss.insert(vv[i]);
    }
    if(*ss.rbegin()==ss.size()){
        if(ss.size()%2){
            cout << "Alice" << endl;
            return;
        }
        else{
            cout << "Bob" << endl;
            return;
        }
    }
    ll prev=0;
    for(ll i:ss){
        if(i==prev+1){
            prev=prev+1;
        }
        else{
            break;
        }
    }
    if(prev%2)
    {
            cout << "Bob" << endl;
            return;
    }
    else{
            cout << "Alice" << endl;
            return;
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