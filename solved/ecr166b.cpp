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
    ll n,ch=0,sum=0,tem=INT_MAX,s2=0,cu=INT_MAX,t2=0;
    cin>>n;
    vector<ll> a(n),b(n+1),diff(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>> a[i];
    }

    for (ll  i = 0; i <= n ; i++)
    {
        cin>> b[i];
    }
    for (ll  i = 0; i <= n ; i++)
    {
        if(i<n){
            diff[i]=abs(a[i]-b[i]);
            sum+=diff[i];
            s2+=diff[i];
        if(b[n]>=(min(a[i],b[i]))&&b[n]<=(max(a[i],b[i]))){
            // cout << " tt st " << i << endl;
            ch=1;
        }
        else{
            tem=min(tem,abs(b[n]-a[i])+1);
            tem=min(tem,abs(b[n]-b[i])+1);
        }
        }
    }
        // cout << cu << " cu " << sum  << " s " << ch << endl;
    if(ch==1){
        cout << s2+1 << endl;
    }
    else{
        cout << sum+tem << endl;
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