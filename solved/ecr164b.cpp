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
    vector<ll> v(n);
    ll flag1=1,flag2=1;
    for (ll  i = 0; i < n ; i++)
    {
        cin>> v[i];

    }
    ll ind1=0,ind2=0,dis=INT_MAX,cou=INT_MAX;
    for (ll  i = 1; i < n ; i++)
    {
        if(v[i]!=v[i-1]){
            ind1=i;
            break;
        }
    }
    for (ll  i = n-2; i >= 0 ; i--)
    {
        if(v[i]!=v[i+1]){
            ind2=n-i-1;
            break;
        }
    }
    for (ll i = 1; i < n ; i++)
    {
        if (v[i]!=v[0])
        {
            dis=min(cou,dis);
            cou=0;
        }
        else{
            cou++;
        }
    }
    
    // cout << ind1 << " ins1 2 " << ind2 << endl;
    if (ind1==0)
    {
        cout << -1 << endl;
    }
    else cout << min(dis,min(ind1,ind2)) << endl;
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