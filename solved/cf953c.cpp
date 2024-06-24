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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n+1,0);
    vector<ll> res(n+1,0);
    for (ll  i = 1; i < n+1; i++)
    {
        v[i]=((i+1)/2)*(i-1+((i-1)%2));
        res[i]=i;
    }
    if(k>v[n]||k%2==1||(k>v[n-1]&&k<v[n])){
        cout << "NO" << endl;
        return ;
    }
    ll sum=k,ind=1;
    while (sum > 0 )
    {
        auto it =upper_bound(v.begin(),v.end(),sum);
        it--;
        ll tem=it-v.begin();
        if(ind+tem>n+2){
            cout << "NO" << endl;
            return;
        }
        reverse(res.begin()+ind,res.begin()+ind+tem);
        sum-=*it;
        ind+=tem+1;
    }
    cout << "YES" << endl;
    for (ll i = 1; i < n+1; i++)
    {
        cout << res[i] << " ";
    }
    
    cout << endl;
    // cout << *lower_bound(v.begin(),v.end(),6) << endl;
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