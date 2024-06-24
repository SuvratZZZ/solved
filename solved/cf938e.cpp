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
void solve(){
    ll n,cou=0;
    cin >> n;
    string s;
    cin >> s;
    for (ll  i = n ; i >= 1 ; i--)
    {
        vector<ll> inv(n+1,0);
        for(ll j=0;j<(n-i)+1;j++){
            if(j==0){
                if(s[0]=='0')
                {   inv[0]++;inv[i]--;}
                }
            else{
                inv[j]+=inv[j-1];
                if((s[j]-'0'+inv[j])%2==0){
                    inv[j]++;inv[j+i]--;
                }
            }
        }
        ll che=1;
        for (ll  j = n-i+1; j < n ; j++)
        {
            inv[j]+=inv[j-1];
                // cout << j << " : at , res : " << ((ll)(s[j]-'0')+inv[j]) << endl;
                if(((ll)(s[j]-'0')+inv[j])%2==0){
                    che=0;
                }    
        }
        if(che==1){
            cout << i << endl;return;
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