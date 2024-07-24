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
// void solve(){
//     ll n,x;
//     cin>>n>>x;
//     vector<ll> a(n);
//     for (ll  i = 0; i < n ; i++)
//     {
//         cin>>a[i];
//     }
//     ll res=0;
//     for (ll  i = 0; i < n ; i++)
//     {
//         for (ll  j = i+1; j < n ; j++)
//         {
//             if((a[i]+a[j]>=pow(10,x-1))&&(a[i]+a[j]<pow(10,x))){
//                 // cout << i << " res " << j << endl;
//                 res+=n-1-(j-i-1);
//             }
//         }
//     }
//     cout << res << endl;
// }
void solve() {
    ll n, x;
    cin >> n >> x;
    vll a(n);
    fl(i, n) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll res = 0;
    ll ld = pow(10, x-1);
    ll ud = pow(10, x) - 1;

    for (ll i = 0; i < n; i++) {
        ll target_low = ld - a[i];
        ll target_high = ud - a[i];

        auto it_low = lower_bound(a.begin() + i + 1, a.end(), target_low);
        auto it_high = upper_bound(a.begin() + i + 1, a.end(), target_high);

        res += distance(it_low, it_high)+n-1;
    }

    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}