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
    ll n,r,f=0;
    cin>>n;
    vector<int> a(n);
    vector<int> res(n);
    vector<int> r2(n+1);
    vector<pair<int,int>> od;
    vector<pair<int,int>> ev;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(a[i]==n){
            r=(i%2);
        }
        r2[a[i]]=i;
        // if(i>0){
        //     if(a[i-1]==1&&a[i]==n){
        //         f=1;
        //     }
        //     if(a[i-1]==n&&a[i]==1){
        //         f=1;
        //     }
        // }
        if(i%2){
            od.push_back({a[i],i});
        }
        else{
            ev.push_back({a[i],i});
        }
    }
    sort(od.begin(),od.end());
    sort(ev.begin(),ev.end());
    // if(n%2==1&&f==0){
    //     ll tem=n;
    //     for (ll  i = 0; i < od.size(); i++)
    //     {
    //         od[i].second=tem;
    //         res[r2[od[i].first]]=tem;
    //         tem--;
    //     }
    //     for (ll i =0 ; i < ev.size(); i++)
    //     {
    //         ev[i].second=tem;
    //         res[r2[ev[i].first]]=tem;
    //         tem--;
    //     }
    // }
    if(r==1){
        ll tem=n;
        for (ll  i = 0; i < od.size(); i++)
        {
            od[i].second=tem;
            res[r2[od[i].first]]=tem;
            tem--;
        }
        for (ll i =0 ; i < ev.size(); i++)
        {
            ev[i].second=tem;
            res[r2[ev[i].first]]=tem;
            tem--;
        }
    }
    else{
        ll tem=n;
        for (ll  i = 0; i < ev.size(); i++)
        {
            ev[i].second=tem;
            res[r2[ev[i].first]]=tem;
            tem--;
        }
        for (ll i =0 ; i < od.size(); i++)
        {
            od[i].second=tem;
            res[r2[od[i].first]]=tem;
            tem--;
        }
    }
    for (ll  i = 0; i < n ; i++)
    {
        cout << res[i] << " ";
    }
    
    cout << endl;
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