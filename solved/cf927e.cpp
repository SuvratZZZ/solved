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
    ll n;
    // cout << (int)'0';
    cin >> n;
    ll tem=n;
    vector<ll> pre(n+1,0);
    string s;
        cin>>s;
        // cout << s << endl;
    for (ll i  = 0; i < n ; i++)
    {
        pre[i+1]=(int)s[i]-48+pre[i];
    }
    // cout << pre[n-1] << endl;
    ll car=0;
    for (ll  i = n-1; i >=0 ; i--)
    {
        pre[i+1]=pre[i]+(int)s[i]-48+car;
        car=pre[i+1]/10;
        pre[i+1]=pre[i+1]%10;
    }
    bool ch = false;
    if (car > 0) {
        cout << car;
    } else {
        ch = true;
    }
    for (ll  i = 1; i <=n ; i++)
    {
        if((pre[i]==0)&&(ch==true)){
            // cout << pre[i] << " jfjf ";
            continue;
        }
        else{
            ch=false;
            cout << pre[i];
        }
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