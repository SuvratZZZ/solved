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
    string s1,s2;
    cin>>s1>>s2;
    bool flag=1;
    for (ll  i = 0; i < n ; i=i+2)
    {
        if(i+1<n){
        if (s1[i+1]=='<'&&s2[i]=='<')
        {
            cout << "NO" << endl;
            flag=0;
            break;
        }
        }
        if(i-1>=0){
        if (s1[i-1]=='<'&&s2[i]=='<')
        {
            cout << "NO" << endl;
            flag=0;
            break;
        }
        }
        
    }
    if(flag){
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