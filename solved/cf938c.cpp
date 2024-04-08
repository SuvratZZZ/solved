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
    vector<ll> v;
    ll st=(k+1)/2;
    ll la=k/2;
    for (ll  i = 0; i < n ; i++)
    {
        ll tem;
        cin>>tem;
        if (st>=tem)
        {
            // cout << " de : " << tem;
            st=st-tem;
            // cout << " st : " << st;
        }
        else{
            tem=tem-st;
            st=0;
            // cout << "pushed : " << tem <<  endl;
            v.push_back(tem);
        }
    }
    for (ll  i = (ll)v.size()-1 ; i >=0  ; i--)
    {
        if(la>=v[i]){
            la-=v[i];
            v.pop_back();
        }
        else
        {
            v[i]-la;
            la=0;
        }
    }

    // for (ll i:v)cout << i << " " ;
    cout << n-(ll)v.size() << endl;
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