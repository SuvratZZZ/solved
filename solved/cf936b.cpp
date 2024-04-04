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
const int INF=1e6+5;
const int Mod=1e9+7;
ll n,a[INF],k;
void solve() {
	cin>>n>>k;ll sum3=0;
	for (ll i=1;i<=n;i++) cin>>a[i],sum3+=a[i],sum3%=Mod;
	ll Max=0,sum=0;
	for (ll i=1;i<=n;i++) {
		sum=max(0ll,sum);
		sum+=a[i];
		Max=max(Max,sum);
	}
	for (ll i=1;i<=k;i++) {
		sum3+=Max;
		Max*=2;Max%=Mod;
		sum3%=Mod;
	}
	cout<<(sum3%Mod+Mod)%Mod<<"\n";
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