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
    int n,m;
    cin>>n;
    vector<int> a(n),b(n);
    map<int ,int > ma,mb,dd;
    for (int  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    
    for (int  i = 0; i < n ; i++)
    {
        cin>>b[i];
        if(a[i]!=b[i]){
            mb[b[i]]++;
        }
        else
        ma[a[i]]++;
    }
    int las=0;
    cin>>m;
    vector<int> d(m);
    for (int  i = 0; i < m ; i++)
    {
        cin>>d[i];
    }
    
    if (mb.empty()&&ma[d[m-1]]!=0)
    {
        cout << "YES" << endl;
            return ;    
    }
    for (int  i = m-1; i >=0  ; i--)
    {
        if(mb[d[i]]){
            mb[d[i]]--;
            if(las==0){
                las=i;
            }
        }
    }
        if(las!=m-1&&ma[d[m-1]]==0){
            cout << "NO" << endl;
            return ;
        }
    for(auto i:mb){
        // cout << i.first <<  " jj " << i.second << endl;
        if(i.second!=0){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
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