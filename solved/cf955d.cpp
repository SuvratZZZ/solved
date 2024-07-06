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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> vv(n+1,vector<ll>(m+1));
    vector<vector<ll>> ti(n+1,vector<ll>(m+1));
    vector<vector<ll>> prs(n+1,vector<ll>(m+1,0));
    ll chu=0,cha=0,sum=0;
    for (ll  i = 1; i <= n ; i++)
    {
        for (ll j = 1; j<= m ;j++)
        {
            cin>>vv[i][j];
            sum+=vv[i][j];
        }
    }
    for (ll  i = 1; i <= n ; i++)
    {
        string tem;
        cin>>tem;
        for (ll j = m; j>= 1 ;j--)
        {
            ti[i][j]=tem[j-1]-'0';
            // if(i==0&&j==0){
            //     prs[i][j]=ti[0][0];
            // }
            // else if(i==0){
            //     prs[i][j]=prs[i][j-1]+ti[i][j];
            // }
            // else if(j==0){
            //     prs[i][j]=prs[i][j-1]+ti[i][j];
            // }
            // else{
            // }
            if(ti[i][j]==0){
                chu+=vv[i][j];
                // ti[i][j]=-vv[i][j];
            }
            else{
                cha+=vv[i][j];
                // ti[i][j]=vv[i][j];
            }
        }
    }
    // for(auto i:ti){
    //     for(auto j:i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    for (ll  i = 1; i <= n ; i++)
    {
        for (ll j = 1; j<= m ;j++)
        {
            prs[i][j]=prs[i][j-1]+prs[i-1][j]-prs[i-1][j-1]+ti[i][j];
        }
    }
    ll req=abs(chu-cha);
    if(req==0){
        cout << "YES" << endl;
        return;
    }
    ll roro=0;
    for (ll  i = k; i <= n ; i++)
    {
        for (ll  j = k; j <= m ; j++)
        {
            ll ss=prs[i][j]-prs[i-k][j]-prs[i][j-k]+prs[i-k][j-k];
            // ss=k*k-(2*min((k*k)-ss,ss));
            // cout << "ss : " << ss << " : " << i << " i j " << j << endl;
            if((2*ss!=k*k)){
                roro=__gcd(roro,abs((k*k-ss)-ss));
            }
        }
    }
    cout << req << " : req" << roro << " ro " << endl;
    if(roro==0){
        // if(sum%(n*m)==0){
        //     cout << "YES" << endl;
        //     return ;
        // }
        // else{
            cout << "yNO" << endl;
            return;
        // }
    }
                if(req%roro==0){
                    cout << "YES" << endl;
                    return ;
                }
    cout << "zNO" << endl;
    // if ((roro == 0 && req == 0) || (roro > 0 && req % roro == 0)) {
    //   cout << "YES" << endl;
    // } else {
    //   cout << "NO" << endl;
    // }
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
