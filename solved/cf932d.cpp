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
    ll n,c,odd=0,eve=0;
    cin >> n >> c ;
    vector<ll> s(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin >> s[i];
        if (s[i]%2==1)
        {
            odd++;
        }
        else{
            eve++;
        }
    }
    // cout << odd << " o e " << eve << endl;
    ll res=1ll*(c+1)*(c+2)/2;
    // cout << res << " rs1 " << endl;
    for (ll  i = 0; i < n ; i++)
    {
        // if (s[i]<=c)
            res=res-(s[i]/2)+1;
        // if (s[i]/2<=c)  
            res=res-c+s[i]-1;
    }
    // cout << res << " rs2 " << endl;
    res=res+(odd*(odd+1)/2);
    res=res+(eve*(eve+1)/2);
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