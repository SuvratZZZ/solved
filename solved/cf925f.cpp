#include <bits/stdc++.h>
using namespace std;
# define ll long long


#ifndef ONLINE_JUDGE
#include <chrono>
#endif
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
# define rfall(f) reverse(f.begin(),f.end());for(auto i:f){cout << i << " ";}cout << endl
# define fall(f) for(auto i:f){cout << i << " ";}cout << endl
# define ftd(f) for(auto i:f){for(auto j:i){cout << j << " ";}cout << endl;}


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

//ll JUD = 0;
//
//#ifdef ONLINE_JUDGE
//# define JUD 0
//#else
//# define JUD 1
//#endif


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
struct lil{
    ll val;
    ll und;
    lil* nex;
    lil* pev;
    lil(ll a,ll b,lil* tt){
        val=a;
        und=b;
        nex=NULL;
        pev=tt;
    }
};
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> a(k,vector<ll>(n));
    set<pair<ll,ll>> st;
    bool che=1;
    for (ll  i = 0; i < k ; i++)
    {
        for (ll  j  = 0; j  < n; j ++)
        {
            cin>>a[i][j];
        }
    }
    if(k==1){cout << "YES" << endl;return;}
    lil* root=new lil(a[0][1],(a[0][1]==a[1][0]?-1:1),NULL);
    lil* curr=root->nex;
    lil* pv=root;
    ll pr=a[0][0];
    ll done=0;
        for (ll  j  = 2; j  < n; j ++)
        {
            curr=new lil(a[0][j],(a[0][j]==a[1][0]?-1:1),pv);
            curr=curr->nex;
            pv=curr;
        }
    lil* tem=NULL;
    for (ll  i = 1; i < k ; i++)
    {
        curr=root;
        for (ll j = 1; j < n; j++)
        {
            cout << i << " - " << j << endl;
            if(done==0){
                if(a[i][j]==pr){
                    if(curr->und==-1){
                        done=-1;
                    }
                    else{
                        done=1;
                    }
                        tem=new lil(pr,(done==1?1:-1),curr);
                        curr->pev->nex=tem;
                        tem->nex=curr;
                        tem->pev=curr->pev;
                        curr->pev=tem;
                    if(curr->und==-1){
                        curr=curr->nex;
                    }
                }
                else{
                    if(curr->val==a[i][0]){
                        curr=curr->nex;
                        curr->und=1;
                        done=1;
                    }
                    if(curr->val!=a[i][j]){
                        cout << "0-2NO" << endl;return;
                    }
                    else{
                        curr=curr->nex;
                    }
                }
            }
            else if(done==-1){
                if(curr->und==-1&&a[i][j]==pr){
                    curr->und=1;
                    curr->nex->und=1;
                    done=1;
                    if(curr->val==a[i][0]){
                        curr=curr->nex;
                    }
                }
                else if(curr->und==-1&&a[i][j]==a[1][0]){
                    tem->nex=curr->nex;
                    curr->nex->pev=tem;
                    tem->pev=curr;
                    curr->nex=tem;
                    curr->und=1;
                    done=1;
                    curr=curr->nex;
                }
                else{
                    if(curr->val==a[i][0]){
                        curr=curr->nex;
                        curr->und=1;
                        done=1;
                    }
                    if(curr->val!=a[i][j]){
                        cout << "-1-2NO" << endl;return;
                    }
                    else{
                        curr=curr->nex;
                    }
                }
            }
            else{
                    if(curr->val==a[i][0]){
                        curr=curr->nex;
                    }
                    if(curr->val!=a[i][j]){
                        cout << "11NO" << endl;return;
                    }
                    else{
                        curr=curr->nex;
                    }
            }
        }
    }
    cout << "YES" << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
        auto start = std::chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    #ifndef ONLINE_JUDGE
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> duration = end - start;
        std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    #endif
    return 0;
}