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
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<pair<ll,ll>> bb(n);
    map<ll,ll> mp;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for (ll  i = 0; i < n ; i++)
    {
        ll tem;
        cin>>tem;
        bb[i]={a[i],tem};
    }
    ll res = INT_MIN;
    ll curr=a[0];
    sort(bb.begin(),bb.end());
    for (ll  i = 0; i < n-1 ; i++)
    {
        if(bb[i+1].first-bb[i].first>1){
            // if(bb[i].first*bb[i].second<=m){
                res=max(res,min(bb[i].first*(m/bb[i].first),bb[i].first*bb[i].second));
                // cout << bb[i].first << " for " <<  bb[i].first*bb[i].second       << endl;
            // }
            // else{
            //     res=max(res,);
            //     // cout << bb[i].first << " for " <<  bb[i].second*(m/bb[i].first) << endl;
            // }
            continue;
        }
        ll sum=0;
        ll cr1=bb[i].first;
        ll co1=bb[i].second;
        ll cr2=bb[i+1].first;
        ll co2=bb[i+1].second;
        sum=cr1*min(m/cr1,co1);
        ll ta2 = min((m-sum)/cr2,co2);
        sum+=cr2*min((m-sum)/cr2,co2);
        res=max(res,sum+min(min(m/cr1,co1),min(co2-ta2,m-sum)));
                // cout << bb[i].first << " for " << sum+min(min(m/cr1,co1),min(co2-ta2,m-sum)) << endl;
    }
            // if(bb[n-1].first*bb[n-1].second<=m){
                res=max(res,min(bb[n-1].first*(m/bb[n-1].first),bb[n-1].first*bb[n-1].second));
                // cout << bb[n-1].first << " for " << bb[n-1].first*bb[n-1].second << endl;
            // }
            // else{
            //     res=max(res,);
            //     // cout << bb[n-1].first << " for " << bb[n-1].second*(m/bb[n-1].first) << endl;
            // }
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