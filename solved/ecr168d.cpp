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
const ll INF = 10000000000000000;
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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// pair<ll,ll> dfs(ll ind,ll pr,vector<ll> &a,vector<vector<ll>> &gr){
//     ll che=0;
//     ll dis=1;
//     ll r1=INT_MAX;

//     if(gr[ind].size()>1 && ind==0){
//         for(auto i:gr[ind]){
//             pair<ll,ll> tt;
//             if(i!=pr){
//                 tt=dfs(i,ind,a,gr);
//                 if(tt.first!=0){
//                     r1=min(r1,tt.second/tt.first);
//                 }
//             }
//         }
//     }
//     else if(gr[ind].size()==1 && ind==0){
//         for(auto i:gr[ind]){
//             pair<ll,ll> tt;
//             if(i!=pr){
//                 tt=dfs(i,ind,a,gr);
//                 dis=tt.first+1;
//                 r1=min(r1,tt.second);
//             }
//         }
//     }
//     else if(gr[ind].size()>2 && ind!=0){
//         for(auto i:gr[ind]){
//             pair<ll,ll> tt;
//             if(i!=pr){
//                 tt=dfs(i,ind,a,gr);
//                 if(tt.first!=0){
//                     r1=min(r1,tt.second/tt.first);
//                 }
//             }
//         }
//     }
//     else{
//         for(auto i:gr[ind]){
//             pair<ll,ll> tt;
//             if(i!=pr){
//                 tt=dfs(i,ind,a,gr);
//                 dis=tt.first+1;
//                 r1=min(r1,tt.second);
//             }
//         }

//     }

//     if((gr[ind].size()==1&&ind!=0)||(gr[ind].size()==0&&ind==0)){
//         r1=0;
//     }
//     // if(r1==INT_MAX)r1=0;
//     return {dis,r1+a[ind]};
// }

bool dfs(ll val,ll ind,ll pr,vector<vector<ll>> &g,vector<ll> &a){
    if(g[ind].size()==1&&pr!=-1){
        // cout << "leaf node " << ind+1 << endl;
        return val<=a[ind];
    }
    bool res=1;
    if(pr==-1){
        if(a[ind]>=val){
            // cout << "grtr prnt " << ind+1 << endl;
            return 1;
        }
        for(auto i:g[ind]){
            // cout << "exec for prnt " << i << " at ind : " << ind << endl;
            res=res&&dfs(val-a[ind],i,ind,g,a);
        }
        return res;
    }
    for(auto i:g[ind]){
            // cout << "exec for prnt 2 " << i+1 << endl;
        if(i!=pr){
            if(a[ind]<val)
            res=res&&dfs(min(INF,2*val-a[ind]),i,ind,g,a);
            else
            res=res&&dfs(val,i,ind,g,a);
        }
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<vector<ll>> gr(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    for (ll  i = 1; i < n ; i++)
    {
        ll tem;
        cin>>tem;
        tem--;
        gr[i].push_back(tem);
        gr[tem].push_back(i);
    }
    // pair<ll,ll> res=dfs(0,-1,a,gr);
    ll l=0,r=1e10;
    while (l<r)
    {
        ll mid=(l+r+1)/2;
        bool tem=dfs(mid,0,-1,gr,a);
        // cout << mid << " mid  res = >> " << tem << endl;
        if(tem){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << l << endl;
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