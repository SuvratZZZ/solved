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
    if (n>30)
    {
        res=(n/30)*2;
        res=res+minco2(arr,n%30);
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

void solve2(){
    ll n;
    cin >> n;
    ll arr[5]={1,3,6,10,15};
    ll res=INT_MAX;
    for (ll i = 0; i <= 2; i++)
    {
        for (ll j = 0; j <= 1; j++)
        {
            for (ll k = 0; k <= 4; k++)
            {
                for (ll l = 0; l <= 2; l++)
                {
                    ll tem1=n-i-j*3-k*6-l*10;
                    ll t2=i+j+k+l;
                    if(tem1<0){continue;}
                    if(tem1%15==0){
                        res=min(res,(tem1/15)+t2);
                        cout << tem1 << " " << t2 << " " << res  << endl;
                    }
                }
                
            }
            
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