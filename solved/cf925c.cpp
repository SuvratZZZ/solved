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
    vector<ll> v(n);
    ll mx=0,cou=1;
    bool chop=0;
    for (ll i = 0; i < n ; i++)
    {
        cin>> v[i];
        if(chop){mx++;}
        if (i>0&&(!chop))
        {

            if(v[i-1]!=v[i])
            {
                mx++;
                chop=1;
            }
            
        }
    }
    for (int i = n-1; i >0 ; i--)
    {
        if (v[i]==v[i-1])
        {
            cou++;
        }
        else break;
        
    }
    // cout << mx << " mx cou " << cou << endl;
    mx=n-mx;
    if(cou==n){
        cout << 0 << endl;
        return;
    }
    if (v[0]==v[n-1])
    {
    cout << n-(mx+cou) << endl;
        
    }
    else
    cout << n-max(mx,cou) << endl;
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