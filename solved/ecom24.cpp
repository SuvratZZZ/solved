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
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    for (ll  i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    // auto chu=[&](const ll mm)->bool{
    //     // ll l=0,r=a.size()-1;
    //     vector<ll> mar(a.size(),0);
    //     if(abs(a[0]-b[b.size()-1])<mm) return 0;
    //     for (ll i = 1;i < a.size(); i++)
    //     {
    //         // for (ll  j  = 0; j  < b.size(); j ++)
    //         // {
    //             if((abs(a[i]+mm>=b[j]||a[i]-mm<=b[j])&&mar[j]==0){
    //                 mar[j]=1;
    //                 break;
    //             }
    //             else{
    //                 if(j==(b.size()-1)){
    //                     return 0;
    //                 }
    //             }
    //         // }
            
    //         // auto kk=lower_bound(b.begin(),b.end(),a[i]+mm);
    //         // if(kk==b.end()){
    //         //     auto jj=upper_bound(b.begin(),b.end(),a[i]-mm);
    //         //     if(jj==b.begin()){
    //         //         return 0;
    //         //     }
    //         // }
    //     }
    //         return 1;
    // };
    // cout << chu(2) << endl;
    // auto chu = [&](const ll mm) -> bool {
    //     for (ll i = 0; i < a.size(); ++i) {
    //         auto kk = lower_bound(b.begin(), b.end(), a[i] + mm);
    //         if (kk == b.end() || *kk < a[i] + mm) {
    //             auto jj = upper_bound(b.begin(), b.end(), a[i] - mm);
    //             if (jj == b.begin() || *(--jj) > a[i] - mm) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // };
    ll l=0,r=INT_MIN;
    // while (l<=r)
    // {
    //     ll mid=(l+r)/2;
    //     if(chu(mid)){
    //         l=mid+1;
    //     }
    //     else{
    //         r=mid-1;
    //     }
    // }
    for (ll  i = 0; i < n ; i++)
    {
        ll rr=INT_MAX;
        for (ll  j = 0; j < n ; j++)
        {
            if(i+j<n)
                {
                    rr=min(rr,abs(a[i]-b[i+j]));
                    }
            else{
                rr=min(rr,abs(a[i]-b[n-i-j]));
            }
        }
        r=max(rr,r);
    }
    
    cout << r << endl;
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