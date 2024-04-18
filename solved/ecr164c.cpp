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
    string x,y;
    cin>>x>>y;
    ll mn=x.length();
        for (ll  i = 0; i <mn ; i++)
        {
                // cout << int(y[i]) << " yi xi " << int(x[i]) << endl;
            if (int(y[i])>int(x[i]))
            {
                swap(x,y);
                break;
            }
            else if(int(x[i])>int(y[i])){
                break;
            }
        }
        bool check=1;
    for (ll  i = 0; i < mn ; i++)
    {
        if(int(x[i])>int(y[i])&&check==0){
                // cout << y[i] << " yi xi " << x[i] << endl;
            swap(x[i],y[i]);
        }
        if (int(x[i])>int(y[i])&&check==1)
        {
            check=0;
        }
    }
    cout << x << endl << y << endl;
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