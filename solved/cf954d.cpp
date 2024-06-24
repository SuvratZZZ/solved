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
ll sol(ll i,string &s,vector<ll> &dp){
    if(dp[i]!=-1)return dp[i];
    if(i==s.length()-1){
        string aa=s.substr(i,1);
        return stoll(aa);
    }
    ll res=INT_MAX;
    string aa=s.substr(i,1);
    res=min(res,stoll(aa)+sol(i+1,s,dp));
    res=min(res,stoll(aa)*sol(i+1,s,dp));
    return dp[i]=res;
}

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll mn = LLONG_MAX;

    if(n==2){
        cout << stoll(s) << endl;
        return; 
    }
    for (ll i = 0; i < n - 1; i++) {
        string tem = s;
        tem.erase(i, 2);

        // Ensure the substring is valid and non-empty
    vector<ll> dp(n,-1);
        if(i < s.length() - 1) {
            string at = s.substr(i, 2);
            if(!at.empty()) {
                mn = min(mn, stoll(at) + sol(0, tem,dp));
                mn = min(mn, stoll(at) * sol(0, tem,dp));
            }
        }
    }
    
    cout << mn << endl;
}
// void solve2(){
//     ll n;
//     cin>>n;
//     string s;
//     cin>>s;
//     ll cz=0;
//     ll mn=INT_MAX;
//     for (ll  i = 0; i < n-1 ; i++)
//     {
//         string tem=s;
//         tem.erase(i,2);
//         string at=s.substr(i,2);
//         mn=min(mn,stoll(at)+sol(0,tem));
//         mn=min(mn,stoll(at)*sol(0,tem));
//         // if(s[i]=='0'){
//         //     cz=1;
//         // }
//         // if(i>1){
//         //     string tem=s.substr(i-1,2);
//         //     if(mn>stoll(tem)){
//         //         mn=stoll(tem);
//         //         at=tem;
//         //     }
//         //     cout << tem << " tem " << endl;
//         // }
//     }
//     // if(cz==1){
//     //     cout << 0 << endl;
//     //     return ;
//     // }
//     // ll sum=0;
//     // for (ll  i = 0; i < n ; i++)
//     // {
//     //     string tem=s.substr(i,1);
//     //     sum+=stoll(tem);
//     // }
//     // cout << at << " at " << sum << endl;
//     // string aa=at.substr(0,1),aaa=at.substr(1,1);
//     // sum=sum+stoll(at)-stoll(aa)-stoll(aaa);
//     cout << mn << endl;
// }
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