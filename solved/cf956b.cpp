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
# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<vector<ll>> b(n,vector<ll>(m));
    for (ll  i = 0; i < n ; i++)
    {
        string s;
        cin>>s;
        for (ll  j = 0; j < m ; j++)
        {
            a[i][j]=s[j]-'0';
        }
        
    }
    for (ll  i = 0; i < n ; i++)
    {
        string s;
        cin>>s;
        for (ll  j = 0; j < m ; j++)
        {
            b[i][j]=s[j]-'0';
        }
    }
    for (ll  i = 0; i < n; i++)
    {
        for(ll j=0;j<m;j++){
            if(i==n-1){
                   if(j==m-1){
                        if((a[i][j]==0&&b[i][j]==2)||(a[i][j]==1&&b[i][j]==0)||(a[i][j]==2&&b[i][j]==1)){
                        a[i][j]+=2;
                        a[i][j]%=3;
                        a[i-1][j]+=1;
                        a[i-1][j]%=3;
                        a[i][j-1]+=1;
                        a[i][j-1]%=3;
                        a[i-1][j-1]+=2;
                        a[i-1][j-1]%=3;
                        }
                        else if((a[i][j]==0&&b[i][j]==1)||(a[i][j]==1&&b[i][j]==2)||(a[i][j]==2&&b[i][j]==0)){
                        a[i][j]+=1;
                        a[i][j]%=3;
                        a[i-1][j]+=2;
                        a[i-1][j]%=3;
                        a[i][j-1]+=2;
                        a[i][j-1]%=3;
                        a[i-1][j-1]+=1;
                        a[i-1][j-1]%=3;
                        }
                        continue;
                    }
                if(a[i][j]!=b[i][j]){
                    if((a[i][j]==0&&b[i][j]==2)||(a[i][j]==1&&b[i][j]==0)||(a[i][j]==2&&b[i][j]==1)){
                        a[i][j]+=2;
                        a[i][j]%=3;
                        a[i-1][j]+=1;
                        a[i-1][j]%=3;
                        a[i][j+1]+=1;
                        a[i][j+1]%=3;
                        a[i-1][j+1]+=2;
                        a[i-1][j+1]%=3;
                    }
                    if((a[i][j]==0&&b[i][j]==1)||(a[i][j]==1&&b[i][j]==2)||(a[i][j]==2&&b[i][j]==0)){
                        a[i][j]+=1;
                        a[i][j]%=3;
                        a[i-1][j]+=2;
                        a[i-1][j]%=3;
                        a[i][j+1]+=2;
                        a[i][j+1]%=3;
                        a[i-1][j+1]+=1;
                        a[i-1][j+1]%=3;
                    }
                continue;
                }
            }
            else if(j==m-1){
                if((a[i][j]==0&&b[i][j]==2)||(a[i][j]==1&&b[i][j]==0)||(a[i][j]==2&&b[i][j]==1)){
                    a[i][j]+=2;
                    a[i][j]%=3;
                    a[i+1][j]+=1;
                    a[i+1][j]%=3;
                    a[i][j-1]+=1;
                    a[i][j-1]%=3;
                    a[i+1][j-1]+=2;
                    a[i+1][j-1]%=3;
                }
                if((a[i][j]==0&&b[i][j]==1)||(a[i][j]==1&&b[i][j]==2)||(a[i][j]==2&&b[i][j]==0)){
                    a[i][j]+=1;
                    a[i][j]%=3;
                    a[i+1][j]+=2;
                    a[i+1][j]%=3;
                    a[i][j-1]+=2;
                    a[i][j-1]%=3;
                    a[i+1][j-1]+=1;
                    a[i+1][j-1]%=3;
                }
                continue;
            }
            else if(a[i][j]!=b[i][j]){
                if((a[i][j]==0&&b[i][j]==2)||(a[i][j]==1&&b[i][j]==0)||(a[i][j]==2&&b[i][j]==1)){
                    a[i][j]+=2;
                    a[i][j]%=3;
                    a[i+1][j]+=1;
                    a[i+1][j]%=3;
                    a[i][j+1]+=1;
                    a[i][j+1]%=3;
                    a[i+1][j+1]+=2;
                    a[i+1][j+1]%=3;
                }
                if((a[i][j]==0&&b[i][j]==1)||(a[i][j]==1&&b[i][j]==2)||(a[i][j]==2&&b[i][j]==0)){
                    a[i][j]+=1;
                    a[i][j]%=3;
                    a[i+1][j]+=2;
                    a[i+1][j]%=3;
                    a[i][j+1]+=2;
                    a[i][j+1]%=3;
                    a[i+1][j+1]+=1;
                    a[i+1][j+1]%=3;
                }
            }
        }
    }
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j = 0; j < m ; j++)
        {
            // cout << a[i][j] << "=" << b[i][j] << ",";
            if(a[i][j]!=b[i][j])
            {
                cout << "NO" << endl;
                return;
            }
        }
        // cout << endl;
    }
    cout << "YES" << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}