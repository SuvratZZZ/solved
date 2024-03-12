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
ll dpp(ll ind,vvll v,ll d,ll m,vvll &dp,ll row,ll &c2){
    c2++;
    if (ind<0)
    {
        return INT_MAX;
    }
    if (ind==0)
    {
        return 1;
    }
    if (dp[row][ind]!=-1)
    {
        return dp[row][ind];
    }
    ll mn = INT_MAX;
    for (ll  i = 1; i <= d+1 ; i++)
    {
        mn = min (mn,dpp(ind-i,v,d,m,dp,row,c2));
    }
    return dp[row][ind]=mn+v[row][ind]+1;
}
void solve(){
    ll n,m,k,d,c1=0;
    cin >> n >> m >> k >> d;
    vector<vector<ll>> v(n,vector<ll>(m));
    vector<vector<ll>> dp(n,vector<ll>(m,-1));
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j = 0; j < m ; j++)
        {
            cin >> v[i][j];
            c1++;
        }
    }
    ll res=INT_MAX;
    ll sol=0,c2=0;

    for (ll  i = 0; i < n ; i++)
    {
        ll sfdk=dpp(m-1,v,d,m,dp,i,c2);
    }
    
    for (ll  i = 0; i < k ; i++)
    {
        sol=sol+dp[i][m-1];
    }
    res=sol;
    for (ll  i = 0; i < n-k; i++)
    {
        sol=sol-dp[i][m-1]+dp[i+k][m-1];
        res=min(res,sol);
    }
    cout << res << endl;
    cout << " couu " << c2 << " =c2  c1= " << c1 << endl;
}

void fill(vvll v,ll d,ll m,vvll &dp,ll row){
    multiset<ll> mm;
    dp[row][0]=1;
    mm.insert(1);
    for (ll  i = 1; i < d+1; i++)
    {
        mm.insert(v[row][i]+2);
        dp[row][i]=v[row][i]+2;
    }
    for (ll  i = d+1 ; i < m ; i++)
    {
        ll min = *mm.begin();
        dp[row][i]=min+v[row][i]+1;
        mm.insert(dp[row][i]);
        mm.erase(mm.find(min));
    }
}
void sol2(){
    ll n,m,k,d,c1=0;
    cin >> n >> m >> k >> d;
    vector<vector<ll>> v(n,vector<ll>(m));
    vector<vector<ll>> dp(n,vector<ll>(m,-1));
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j = 0; j < m ; j++)
        {
            cin >> v[i][j];
        }
    }
    for (ll  i = 0; i < n ; i++)
    {
        fill(v,d,m,dp,i);
    }
    ll sum=0,res=0;
    for (ll  i = 0; i < k ; i++)
    {
        sum+=dp[i][m-1];
    }
    for (ll   i = k; i < n ; i++)
    {
        res=min(res,sum);
        sum-=dp[i-k][m-1];
        sum+=dp[k][m-1];
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
        // solve();
        sol2();
    }
    return 0;
}