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
const ll mod = 1e9+7;
const int LLL = 1e6+5;
int sml_fctr[LLL];
void fill_factor(){
    for(int i=0;i<=LLL;i++){
        sml_fctr[i]=i;
    }
    for(int i=2;i*i<=LLL;i++){
        for(int la=i*i;la<=LLL;la=la+i){
            if(sml_fctr[la]==la){
                sml_fctr[la]=i;
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
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    ll la=0,rr=n-1;
    ll sum=0,res=0;
    
    la=0;rr=0;
    sum=0;ll res2=0;
    
    for (ll  i = 0; i < n ; i++)
    {
        sum+=a[i];
        if(sum>=l&&sum<=r){
            res2++;
            sum=0;
            la=i+1;
        }
        else if(sum>r){
            for (; la <=i && sum>r ; la ++)
            {
                sum-=a[la];
                if(sum>=l&&sum<=r){
                    res2++;
                    sum=0;
                    la=i+1;
                    break;
                }
            }
        }
    }
    

    cout << res2 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}