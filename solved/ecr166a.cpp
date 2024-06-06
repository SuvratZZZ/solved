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
    bool s1=0;
    bool s2=0;
    bool fuc=0;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    int i=0;
    while (i<n )
    {
        if(i!=n-1){
            if(s[i]>s[i+1]){
                s1=1;
            }
        }
        i++;
    }
    for (ll  i = 0; i < n ; i++)
    {
        if((int)s[i]>57){
            s2=1;
        }
        else{
            if(s2==1){
                fuc=1;
                break;
            }
        }
    }
    // cout << fuc << " f s " << s1 << endl;
    if((fuc==1)||(s1==1)){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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