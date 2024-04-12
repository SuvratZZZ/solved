#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
vector<vector<ll>> divi(200001);

void fill(){
    for (ll  i = 1; i <= 200000; i++)
    {
        for (ll  j  = i; j  <= 200000; j=j+i )
        {
            divi[j].push_back(i);
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    // for(ll i:divi[n])cout << i << endl;
    for (ll  i = 0; i < divi[n].size(); i++)
    {
        ll count=0,j;
        // cout << " divisor : " << divi[n][i] << endl;
        for (  j = 0; j < n && count<=1 ; j++)
        {
            if (s[j]!=s[j%divi[n][i]])
            {
                count ++;
                // cout << s[j%divi[n][i]] << " : not loo 1 equal : " << s[j] << " for index " << j << endl; 
            }
            
        }
        if (j==n&&count<=1)
        {
            cout << divi[n][i] << endl;
            break;
        }
        count=0;
        for (  j = 0; j < divi[n][i]&& count<=1; j++)
        {
            if (s[j]!=s[j+divi[n][i]])
            {
                count ++;
                // cout << s[j+divi[n][i]] << " : not loo 2 equal : " << s[j] << " for index " << j << endl; 
            }
            
        }
        for (j = divi[n][i]; j < n && count<=1 ; j++)
        {
            if (s[j]!=s[(j%divi[n][i])+divi[n][i]])
            {
                count ++;
                // cout << s[(j%divi[n][i])+divi[n][i]] << " : not loo 3 equal : " << s[j] << " for index " << j << endl; 
            }
            
        }
        if (j==n&&count<=1)
        {
            cout << divi[n][i] << endl;
            break;
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    fill();
    while(t--){
        solve();
    }
    return 0;
}