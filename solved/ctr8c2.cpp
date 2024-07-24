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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> ve(x);
    vector<ll> co,ce;
    for (ll  i = 0; i < x ; i++)
    {
        cin >> ve[i];
    }
    ll res=0;
    ll cou1=0;
    sort(ve.begin(),ve.end());
    for (ll  i = 1; i < x ; i++)
    {
        if(ve[i]-ve[i-1]>2){
            if((ve[i]-ve[i-1])%2)
            co.push_back(ve[i]-ve[i-1]);
            else
            ce.push_back(ve[i]-ve[i-1]);
        }
        if ((i==x-1)&&((n-ve[i]+ve[0])>2))
        {
            if((n-ve[i]+ve[0])%2)
            co.push_back(n-ve[i]+ve[0]);
            else
            ce.push_back(n-ve[i]+ve[0]);
        }
        if(ve[i]-ve[i-1]==2){
            res++;
        }
        if ((i==x-1)&&((n-ve[i]+ve[0])==2))
        {
            res++;
        }
    }
    sort(co.begin(),co.end());
    sort(ce.begin(),ce.end());
    for(auto i:ce){
        // cout << i << " ";
        if((i-1)/2<=y){
            y-=(i-1)/2;
            res+=(i-1);
        }
        else{
            res+=y*2;
            y=0;
            break;
        }
    }
    for(auto i:co){
        // cout << i << " ";
        if((i-1)/2<=y){
            y-=(i-1)/2;
            res+=(i-1);
        }
        else{
            res+=y*2;
            break;
        }
    }
    res=res+x-2;
    // cout << "res : " << res << endl;
    cout << min(res,n-2) << endl;
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