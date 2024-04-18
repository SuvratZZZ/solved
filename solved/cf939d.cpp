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
    ll n,re1=0,re2=0,l1,l2,r1,r2;
    cin>> n;
    vector<ll> v(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> v[i];
    }
    for (ll  i = 2 ; i <= n ; i++)
    {
        set <ll> ss;
        map<ll,ll> m;
        for (ll  pp = 0; pp < i ; pp++)
        {
            ss.insert(v[i]);
            m[v[i]]++;
        }
        for ( ll j = i; j <n  ; j++)
        {
            for (ll  pp = 0 ; pp < 100 ; pp++)
            {
                if(m[pp]){
                    if(*ss.rbegin()==pp){
                        re1=max(re1,pp);
                    }
                }
                else{
                    break;
                }
            }
            for (ll  pp = 1 ; pp < 100 ; pp++)
            {
                if(m[pp]){
                    if(*ss.rbegin()==pp){
                        re2=max(re2,pp);
                    }
                }
                else{
                    break;
                }
            }
            
            
        }
        
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