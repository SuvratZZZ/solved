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
// const ll M = 1e9+7;
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
ll poo(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res*a)%M;
            n--;
        }
            a=(a*a)%M;
            n/=2;
    }
    return res;
}
void sol2(){
    cout << poo(2,50) << endl;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> pri(n+1);
    vector<ll> sml;
    pri[0]=0;
    ll mn=0,cm=0,c=0;
    ll res=1,r2;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        c+=a[i];
        if(c==mn&&mn!=0){
            cm++;
            sml.push_back(i);
        }
        else if(c<mn){
            mn=c;
            cm=1;
            sml.clear();
            sml.push_back(i);
        }
        if(c>=0)
        {
            res=(res*2)%M;
        }
        if(a[i]>=0){
            pri[i+1]=pri[i];
        }
        else{
            pri[i+1]=pri[i]+1;
        }
    }
    if(cm<=1){
        cout << res << endl;
        return ;
    }
    r2=res;
    res=0;
    for (ll  i = 0; i < cm ; i++)
    {
        res=(res+(r2*(poo(2,pri[n]-pri[sml[i]+1]))%M))%M;
    }
    // res=(((cm*2)%M)*res)%M;
    // res+=M;
    // res-=r2;
    // res%=M;
    cout << res << endl;
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
        // sol2();
    }
    return 0;
}