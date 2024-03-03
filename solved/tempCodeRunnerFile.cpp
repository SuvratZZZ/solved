#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
//
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ll> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
ll minco(ll arr[], ll tosum) {
    ll n = 5;
    
    vector<ll> prev(tosum + 1, 0);
    vector<ll> cur(tosum + 1, 0);
    
    for (ll i = 0; i <= tosum; i++) {
        if (i % arr[0] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9; 
    }
    
    for (ll ind = 1; ind < n; ind++) {
        for (ll tarr = 0; tarr <= tosum; tarr++) {
            ll nott = prev[tarr];
            
            
            ll tak = 1e9; 
            if (arr[ind] <= tarr)
                tak = 1 + cur[tarr - arr[ind]];
                
            cur[tarr] = min(nott, tak);
        }
        prev = cur;
    }
    
    ll ans = prev[tosum];
    if (ans >= 1e9)
        return -1;
    
    return ans;
}

ll minco2(ll arr[],ll n){
    vector<ll> dp(n+1,INT_MAX);
    dp[0] = 0;

    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<5; j++){
            if (arr[j] <= i)
            {
                ll res = dp[i-arr[j]];
                if (res != INT_MAX && res + 1 < dp[i])
                dp[i] = res + 1;
            }
        }
    }
    return dp[n];
}
void solve(){
    ll n;
    cin >> n;
    ll arr[5]={1,3,6,10,15};
    ll res=0;
    if (n>32000&&n<=320000)
    {
        res=2000;
        res=res+minco2(arr,n-30000);
    }
    else if (n>320000&&n<=3200000)
    {
        res=20000;
        res=res+minco2(arr,n-300000);
    }
    else if (n>3200000&&n<=32000000)
    {
        res=200000;
        res=res+minco2(arr,n-3000000);
    }
    else if (n>32000000&&n<=320000000)
    {
        res=2000000;
        res=res+minco2(arr,n-30000000);
    }
    else if (n>320000000)
    {
        res=20000000;
        res=res+minco2(arr,n-300000000);
    }
    else{
        res=res+minco2(arr,n);
    }
    
    // ll i=4;
    // while (n>0)
    // {
    //     res=res+(ll)(n/arr[i]);
    //     n=n%arr[i];
    //     i--;
    // }
    
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