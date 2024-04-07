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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> vec(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> vec[i];
    }
    sort(vec.begin(),vec.end());
    ll req=(k+m-1)/m;
    ll res=0;
    if ((k%m)==0 )
    {
        for (ll  i = 0; i < req ; i++)
        {
            res+=m*vec[i];
        }
        res+=(((ll)pow(m,2)*req*(req-1))/2);
    }
    else{
        ll i=0;
        for (  i = 0; i < req-1 ; i++)
        {
            res+=m*vec[i];
        }
        res+=(k%m)*vec[i];
        res+=(((ll)pow(m,2)*(req-1)*(req-2))/2);
        res+=(req-1)*m*(k%m);
    }
    cout << res << endl;
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