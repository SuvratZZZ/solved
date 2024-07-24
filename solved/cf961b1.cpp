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
    map<ll,ll> mp;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    ll res = INT_MIN;
    // for(auto it=mp.begin();it!=mp.end();it++){
    //     auto i2=it;
    //     i2++;
    //     if(i2==mp.end())break;
    //     if(i2->first-it->first>1){
    //         ll r2=it->first*it->second;
    //             if(ceil((r2-(1.0*m))/it->first)<=it->second){
    //                 r2-=ceil((r2-(1.0*m))/it->first);
    //             }
    //                 res=max(res,r2);
    //         continue;
    //     }
    //     if(it->first*it->second+i2->first*i2->second<=m){
    //         res=max(res,it->first*it->second+i2->first*i2->second);
    //     }
    //     else{
    //         ll r2=it->first*it->second+i2->first*i2->second;
    //         ll cou1=it->second;
    //         ll cou2=i2->second;
    //             if(ceil((r2-(1.0*m))/it->first)<=it->second){
    //                 r2-=ceil((r2-(1.0*m))/it->first);
    //                 continue;
    //             }
    //             else{
    //                 r2-=it->first*it->second;
    //             }
    //                 r2-=ceil((r2-(1.0*m))/i2->first);
    //                 res=max(res,r2);
    //     }
    // }

    ll l=0,r=0;
    ll sum=0;ll curr=a[0];
    sort(a.begin(),a.end());
    vector<ll> br;
    for (ll  i = 1; i < n ; i++)
    {
        if(a[i]!=curr){
            br.push_back(i-1);
        }
    }
    
        while (l<n&&r<n)
        {
            sum+=a[r];
            r++;
            while (sum>m||a[r-1]-a[l]>1 )
            {
                sum-=a[l];
                l++;
            }
            if(a[r-1]-a[l]<=1){
                res=max(res,sum);
            }
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