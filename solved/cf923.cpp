#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
    
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
    vector<int> a(n);
    vector<int> ch(n);
    vector<int> chb(n);

    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ch[0]=0;
    for (int i = 1; i < n; i++)
    {
        if (ch[i-1]==ch[i])
        {
            ch.push_back(ch[i-1]);
        }
        else{
            ch.push_back(i);
        }
        
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
