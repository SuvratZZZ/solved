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

ll dfs(ll ind, string s, vector<ll> tre[]){
    if(tre[ind].empty()){
        // cout << ind << " is terminal " << endl;
        return 0;
    }
    ll r1 = INT_MAX;
    ll r2=INT_MAX,r3=INT_MAX;
    if (s[ind-1]=='U')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+dfs(tre[ind][0],s,tre);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+dfs(tre[ind][1],s,tre);
        }
        r1=min(r2,r3);
        // cout << "called U" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='L')
    {
        if (tre[ind][0]!=0)
        {
            r2=0+dfs(tre[ind][0],s,tre);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+dfs(tre[ind][1],s,tre);
        }
        r1=min(r2,r3);
        // cout << "called L" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='R')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+dfs(tre[ind][0],s,tre);
        }
        if (tre[ind][1]!=0)
        {
            r3=0+dfs(tre[ind][1],s,tre);
        }
        r1=min(r2,r3);
        // cout << "called R" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    return r1;
}
void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> tre(n+1);
    for (ll  i = 1; i <= n ; i++)
    {
        ll tem1,tem2;
        cin >> tem1 >> tem2;
        if (tem1==0&&tem2==0)
        {
            // cout << "empty " << i << " ";
            continue;
        }
        tre[i].push_back(tem1);
        tre[i].push_back(tem2);
    }
    
    // cout << " is 0 empty " << tre[0].empty() << endl;
    
    auto dfs2 = [&](auto self,ll ind)-> ll {
        if(tre[ind].empty()){
        // cout << ind << " is terminal " << endl;
        return 0;
    }
    ll r1 = INT_MAX;
    ll r2=INT_MAX,r3=INT_MAX;
    if (s[ind-1]=='U')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+self(self,tre[ind][0]);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+self(self,tre[ind][1]);
        }
        r1=min(r2,r3);
        // cout << "called U" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='L')
    {
        if (tre[ind][0]!=0)
        {
            r2=0+self(self,tre[ind][0]);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+self(self,tre[ind][1]);
        }
        r1=min(r2,r3);
        // cout << "called L" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='R')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+self(self,tre[ind][0]);
        }
        if (tre[ind][1]!=0)
        {
            r3=0+self(self,tre[ind][1]);
        }
        r1=min(r2,r3);
        // cout << "called R" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    return r1;
    }; 
    ll ans=dfs2(dfs2,1);
    // cout << dfs(1,s,tre) << endl;
    cout << ans << endl;
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