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
    ll n,m,d;
    cin>>n>>m>>d;
    vector<ll> vec(m);
    for (ll  i = 0; i < m ; i++)
    {
        cin>>vec[i];
    }
    vector<ll> prec(m);
    prec[0]=((vec[0]>1)*(1))+1+((vec[0]-2)/d);
    vector<ll> brec(m);
    brec[m-1]=1+(n-vec[m-1])/d;
    for (ll  i = 1; i < m ; i++)
    {
        prec[i]=prec[i-1]+1+((vec[i]-vec[i-1]-1)/d);
    }
    for (ll  i = m-2; i >= 0; i--)
    {
        brec[i]=brec[i+1]+1+((vec[i+1]-vec[i]-1)/d);
    }
    // cout << "prec : " ;
    // for(auto i:prec) cout << i << ' ';
    // cout << endl;
    // cout << "brec : " ;
    // for(auto i:brec) cout << i << ' ';
    // cout << endl;
    ll r1=0,r2=INT_MAX;
    for (ll  i = 0; i < m ; i++)
    {
        ll tem=0;
        if (i==0)
        {
            tem+=brec[i+1];
            tem+=(1+((vec[i+1]-2)/d));
            // cout << "tem : " << tem  << " added 1 : " << (1+((vec[i+1]-2)/d))  << endl;
        }
        else if (i==(m-1))
        {
            tem+=prec[i-1];
            tem+=((n-vec[i-1])/d);
            // cout << "tem : " << tem  << " added 3 : " << ((n-vec[i-1])/d)  <<  endl;
        }
        else {
            tem+=brec[i+1];
            tem+=prec[i-1];
            tem+=((vec[i+1]-vec[i-1]-1)/d);
            // cout << "tem : " << tem  << " added 2 : " << ((vec[i+1]-vec[i-1]-1)/d) << endl;
        }
        if(tem<r2){
            r2=tem;
            r1=1;
        }
        else if(r2==tem){
            r1++;
        }
    }
    cout << r2 << " " << r1 << endl;
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