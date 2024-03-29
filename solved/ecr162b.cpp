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
    ll n,k;
    cin >> n >> k;
    vector<ll> hel(n,0);
    vector<ll> pos(n,0);
    map<ll,ll >poshel;
    ll prev=0,curr=0;
    
    for (ll  i = 0; i < n ; i++)
    {
        cin >> hel[i];
    }
    for (ll  i = 0; i < n ; i++)
    {
        cin >> pos[i];
        poshel[abs(pos[i])]+=hel[i];
    }

    ll prevpos=0;
    for(auto it:poshel){
        prev=prev+((it.first-prevpos)*k)-it.second;
        if (prev<0)
        {
            cout << "NO" << endl;
            return;
        }
        prevpos=it.first;
    }
    
    cout << "YES" << endl;
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