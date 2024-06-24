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
    ll n,k,mst=0,msb=0,cou=2,tem;
    cin>>n>>k;
    string s,s2="";
    cin>>s;
    tem=k;
    for (ll  i = 1; i < n ; i++)
    {

        if(cou<0){
            cout << -1 << endl;
            return;
        }
        if(s[i]!=s[i-1]){
            if(tem==0){
                tem=k-1;
            }
            else{
                cou--;
                tem=k-1;
                msb=s[i]-'0';
                mst=i;
            }
        }
        else{
            tem--;
        }
    }
    cout << mst << " i " << msb << endl;
    // if(cou<0){
    //         cout << -1 << endl;
    //         return ;
    // }
    // if(cou==1){
    //         cout << k << endl;
    //         return ;
    // }
    // else{
    //     if(s[0]!=s[n-1]||){
    //         cout << -1 << endl;
    //         return;
    //     }
    // }
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