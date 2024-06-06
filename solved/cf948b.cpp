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
    ll x,y,zz=0;
    cin>>x;
    y=x;
    
    vector<ll> ans(32,0);
    bool t=0,res=1;
    while (y>0)
    {
        if(y&1){
            if(t){
                res=0;
            }
            else{
                t=1;
            }
        }
        else{
            t=0;
        }
        ans[zz]=y&1;
        y=y>>1;
        zz++;
    }
    // cout << res << endl;
    if(res){
    cout << 32 << endl;
        for(auto i:ans){
            cout << i << " ";
        }
        cout << endl;
        return; 
    }
    int i=0;
    while(i<32){
        int i2=i+1;
        if(ans[i]==1&&i2<31&&ans[i2]==1){
            while (i2<32 && ans[i2]==1)
            {
                i2++;
            }
            ans[i]=-1;
            for (int k = i+1; k < i2 ; k++)
            {
                ans[k]=0;
            }
                ans[i2]=1;
        }
        i=i2;
    }
    cout << 32 << endl;
        for(auto i:ans){
            cout << i << " ";
        }
        cout << endl;
        return; 
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