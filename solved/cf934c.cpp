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
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> m;
    map<ll, ll> pref;
    ll mx = INT_MIN;
    for (ll  i = 0; i < n ; i++)
    {
        cin >> a[i];
        m[a[i]]++;
        mx=max(mx,a[i]);
    }
    ll temmp=0;
    for ( auto it=m.begin(); it!=m.end();it ++)
    {
        pref[it->first]=it->second+temmp;
        temmp=it->second+temmp;
    }
    
    ll res=0,flag=0;
    for (ll  i = 0; i <= mx+1; i++)
    {
        if (m[i]==0)
        {
            res = i;
            break;
        }
        if((m[i]==1)&&flag){
            res = i;
            break;
            cout << "ff " << i << endl;
        }
        if (m[i]==1)
        {
            flag=1;
        }
        
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