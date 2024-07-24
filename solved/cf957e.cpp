#include <bits/stdc++.h>
using namespace std;
# define ll long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
const ll mod = 1e9+7;
const int LLL = 1e6+5;
int sml_fctr[LLL];
void fill_factor(){
    for(int i=0;i<=LLL;i++){
        sml_fctr[i]=i;
    }
    for(int i=2;i*i<=LLL;i++){
        for(int j=i*i;j<=LLL;j=j+i){
            if(sml_fctr[j]==j){
                sml_fctr[j]=i;
            }
        }
    }
}
vector<int> fin_factor(int n){
    // will not have 1 as prime
    vector<int> res;
    int tt=n;
    while(tt!=1){
        res.push_back(sml_fctr[tt]);
        tt=tt/sml_fctr[tt];
    }
    return res;
}
tuple<bool, long long, int> isPower(long long n) {
    if (n <= 1) return {true, n, 1}; // 0 and 1 are powers of any number

    for (int b = 2; b <= log2(n) + 1; b++) {
        double a = pow(n, 1.0 / b);
        long long intA = round(a); // round to nearest integer
        
        // Check if intA^b == n
        if (pow(intA, b) == n) {
            return {true, intA, b};
        }
    }
    return {false, -1, -1};
}
void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    unordered_map<ll,ll> mp;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    tuple<bool, long long, int> tt = isPower(x);
    for (ll  i = 0; i < n ; i++)
    {
        ll tem=a[i];
        if(a[i]%x==0){
            while (tem!=1)
            {
                tem=tem/x;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}