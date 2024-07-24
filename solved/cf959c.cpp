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
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    vector<ll> pr(n+1,0);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        pr[i+1]=pr[i]+a[i];
    }
    ll l=0,r=0,ss=0,ans=0;
    vector<ll> cp(n+1,-1);
    for (ll  i = n-1; i >=0  ; i--)
    {
        ll lef=i;
        ll cou=0;
        // cout << "for i = " << i << endl;
        ll last=i;
        if(cp[last]==-1){
            while(lef<n){
                ll rig=n-1;
                while (lef<rig)
                {
                    ll mid=(lef+rig)/2;
                    if(pr[mid+1]-pr[last]>x){
                        rig=mid;
                    }
                    else{
                        lef=mid+1;
                    }
                }
                if(pr[lef+1]-pr[last]>x){
                    cou++;
                    last=lef+1;
                    if(cp[last]!=-1){
                        cou+=cp[last];
                        // cout << " yo yo " << endl;
                        break;
                    }
                    // cp[last]=lef+1;
                }
                lef++;
            }
        }
        else{
                // if(cp[last]==-2)break;
                // if(pr[cp[last]]-pr[last]>x){
                //     cou++;
                //     last=cp[last];
                //     lef=cp[last]-1;
                // }
                cou=cp[i];
            }
        // if(a[n-1]<=x)cou--;
        // cou--;
            // cout << " rig , cou : " << cou << endl;
        cp[i]=cou;
        ans+=(n-i-cou);
            // cout << ans << " : ans , add : " << (n-i-cou) << endl;
        // cout << endl;
    }
    cout << ans << endl;
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