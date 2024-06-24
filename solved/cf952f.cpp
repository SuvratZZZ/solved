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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
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
    ll h,n,lc=1,tod=0,tom=0;
    cin>>h>>n;
    vector<ll> hh(n),cc(n);
    vector<pair<ll,ll>> oo(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>hh[i];
    }
    for (ll  i = 0; i < n ; i++)
    {
        cin>>cc[i];
        if(cc[i]>tod){
            tod=cc[i];
            tom=i;
        }
    }
    lc=((h/hh[tom])+1)*cc[tom];
    auto chec=[&](ll mm)->bool{
        ll hel=0;
        for (ll i = 0; i < n ; i++)
        {
            hel+=hh[i]*((mm+cc[i]-1)/cc[i]);
            cout << hel << " : for " << mm << endl;
            if(hel>=h)return 1;
        }
        return hel>=h;
    };
    ll lo=0,hi=lc;
    // ll lo=0,hi=1e18;
    while (lo<hi)
    {
        ll mid=(lo+hi)/2;
        if(chec(mid)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    cout << lo << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor()
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}