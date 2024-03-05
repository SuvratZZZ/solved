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

ll hcf(ll n,ll m){      
    if (n%m==0)
    {
        return m;
    }
    else
    {
        return hcf(m,n%m);
    }
    
}

void solve(){
    ll n ,mx=INT_MIN,res,diff,ans;
    cin >> n ;
    vector<ll> a(n);
    // cout << hcf(n,m);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        mx=max(mx,a[i]);
    }
    if(n==1){
        cout << 1 << endl; 
        return;
    }
    res=__gcd(mx-a[0],mx-a[1]);
    // cout << res << endl;
    diff=mx-a[0]+mx-a[1];
    for (ll  i = 2; i < n ; i++)
    {
        // cout << mx-a[i] << "ai \n" ;
        res=__gcd(res,mx-a[i]);
        diff=diff+mx-a[i];
    }
    // cout << res << ' ' << diff << endl;
        if(res*((n*(n-1))/2)==diff){
            cout << (diff/res)+(n) << endl;
            return;
        }
    sort(a.begin(),a.end());
    for (ll  i = n-2; i >= 0 ; i--)
    {
        if(a[i+1]-a[i]!=res){
            diff=diff+mx-a[i+1]+res;
            cout << diff/res << endl;
            return;
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