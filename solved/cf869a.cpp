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
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    vector<ll> prc(n+1,0);
    vector<ll> dec(n+1,0);
    prc[0]=1;
    // prc[1]=1;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>v[i];
    }
    ll chan=0;
    for (ll  i = 1; i < n-1; i++)
    {
        // if(v[i]<=v[i-1]){
        //     chan++;
        // }
        // else{
        //     chan=0;
        // }
        if (v[i]<=v[i-1]&&v[i]>=v[i+1])
        {
            prc[i]=prc[i-1]+1;
        }
        else
        {
            prc[i]=prc[i-1];
        }
    }
    // prc[n]=prc[n-1];
    // for(ll i:prc){
    //     cout << i << " ";
    // }
    // cout << endl;

    for (ll  i = 0; i < q ; i++)
    {
        ll t1,t2;
        cin>> t1 >> t2;
        if (t2-t1<2)
        {
            cout << t2-t1+1 << endl;
        }
        // else if(t1==1)
        // {
        //     cout << t2-t1+1-(prc[t2-1]) << endl;
        // }
        else{
            cout << max(2ll,t2-t1+1-(prc[t2-2]-prc[t1-1])) << endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}