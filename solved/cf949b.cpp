#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
# define ll long long
# define pb push_back
# define fl(i,nn) for(ll i=0; i< nn ;i++)
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
    ll nn=1,mm=1,r1,r2,r3,mx,att,prev=0;
    cin>>nn>>mm;
    r1=nn+mm;
    r2=max(0ll,nn-mm);
    ll res=0;
    for ( ll i = 0; i <= 32 ; i++)
    {
        if((r1/(1<<i))%2==1||(r2/(1<<i))%2==1){
            res=res|(1<<i);
        }
        else if((r1/(1<<i))!=(r2/(1<<i))){
            res=res|(1<<i);
        }
    }
    cout << res << endl ;
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