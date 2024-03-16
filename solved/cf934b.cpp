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
    cin >> n >> k ;
    vector <ll > a(2*n);
    set<ll> sss;
    for (ll  i = 0; i < 2*n ; i++)
    {
        cin >> a[i];
        sss.insert(a[i]);
    }
    
    vector<ll> re1,re2;
    ll cou =0;
    for (ll  i = 1; i <=n && cou<2*k ; i++)
    {
        if ((sss.find(i)!=sss.end()) && (sss.find(n+i)!=sss.end()))
        {
            re1.push_back(i);
            re2.push_back(n+i);
            cou+=2;
        }
        else if((sss.find(i)!=sss.end()) && (cou < k)){
            re1.push_back(i);
            cou++;
        }
    }
    
    for(ll i:re1){
        cout << i << " ";
    }
    cout << endl;
    for(ll i:re2){
        cout << i << " ";
    }
    cout << endl;
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