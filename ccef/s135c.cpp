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
int fact[LLL];
void fill_fact(){
    for(int i=0;i<=LLL;i++){
        fact[i]=i;
    }
    for(int i=2;i*i<=LLL;i++){
        for(int j=i*i;j<=LLL;j=j+i){
            if(fact[j]==j){
                fact[j]=i;
            }
        }
    }
}
vector<int> fin_fact(int n){
    // will not have 1 as prime
    vector<int> res;
    int tt=n;
    while(tt!=1){
        res.push_back(fact[tt]);
        tt=tt/fact[tt];
    }
    return res;
}
void solve(){
    ll n,k,sum=0,s2=0;
    cin>>n>>k;
    vector<int> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(i>0){
            sum=sum+abs(a[i]-a[i-1]);
        }
    }
    for (ll  i = 0; i < n ; i++)
    {   
        if(i==0)
        {
            s2=max(s2,sum-abs(a[i]-a[i+1])+abs(k-a[i+1]));
        }
        else if(i==n-1){
            s2=max(s2,sum-abs(a[i]-a[i-1])+abs(k-a[i-1]));
        }
        else{
            s2=max(s2,sum-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(k-a[i+1])+abs(k-a[i-1]));
        }
    }
    for (ll  i = 0; i < n ; i++)
    {   
        if(i==0)
        {
            s2=max(s2,sum-abs(a[i]-a[i+1])+abs(1-a[i+1]));
        }
        else if(i==n-1){
            s2=max(s2,sum-abs(a[i]-a[i-1])+abs(1-a[i-1]));
        }
        else{
            s2=max(s2,sum-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(1-a[i+1])+abs(1-a[i-1]));
        }
    }
    cout << s2 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_fact()
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}