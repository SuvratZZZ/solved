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
    ll n,k,my,fir=0,sec=0,change=0,pos=0,okok=1;
    cin>>n>>k;
    vector<ll>cow(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>cow[i];
    }
    my=cow[k-1];
    for (ll  i = 0; i < n ; i++){
        if((cow[i]<my)&&(change==0)){
            fir++;
        }
        if(cow[i]>my){
            change++;
            if ((change==1)&&(okok==1))
            {
                pos=i;
                okok=0;
            }
        }
        if ((change==1)&&(cow[i]<my)&&(i<k-1)){
            sec++;
        }
    }
    if (k==1||n==2){
        cout << fir << endl;
    }
    else if(pos+1>k){
        cout << fir << endl;
    }
    else{
        cout << max(fir-1,sec+1) << endl;
    }
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