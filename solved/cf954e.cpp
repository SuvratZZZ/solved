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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    map<int,int> mp;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    vector<ll> a2;
    for (ll i = 0; i < n ; i++)
    {
        if(mp[a[i]]%2==1){
            a2.push_back(a[i]);
        }
    }
    a=a2;
    sort(a.begin(),a.end());
    // for(auto i:a)cout <<i << " ";
    // cout << " jj " << endl;
    ll res=0;
    for (ll  i = 0; i < 2*(a.size()/2)-1 ; i++)
    {
        bool fin=0;
        for (ll  j  = i+1 ; j  < a.size(); j ++)
        {
            if(abs(a[i]-a[j])%k==0){
                fin=1;
                res+=(abs(a[i]-a[j]))/k;
                a.erase(a.begin()+i);
                a.erase(a.begin()+j-1);
            }
        }
        if(fin==0)
            {cout << -1 << endl;return;}
    }
    cout << res << endl;
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