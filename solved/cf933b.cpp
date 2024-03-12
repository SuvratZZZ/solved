#include <bits/stdc++.h>
using namespace std;
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
    cin>> n;
    vector<ll> v(n);
    for(ll i=0 ; i<n ;i++)cin >> v[i];
    ll i;
    for (  i = 0; i < n-2 ; i++)
    {
        if(v[i]<0)break;
        v[i+1]-=(2*v[i]);
        v[i+2]-=v[i];
        v[i]=0;
        // cout << v[i+1] << " V V " << v[i+2] << endl;
    }
    if (i==n-2&&v[n-2]==0&&v[n-1]==0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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