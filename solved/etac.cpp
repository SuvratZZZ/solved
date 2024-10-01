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
bool areAlmostEqual(long double a, long double b, long double epsilon = 1e-9L) {
    return std::fabs(a - b) < epsilon;
}
void solve(){
    ll n,xs,ys,xt,yt;
    cin>>n;
    vector<vector<ll>> co(n,vector<ll>(2,0));
    long double da,db;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>co[i][0];
        cin>>co[i][1];
    }
    cin>>xs>>ys>>xt>>yt;
    for (ll  i = 0; i < n ; i++)
    {
        long double k = ((long double)((yt-ys) * (co[i][0]-xs)) - (long double)((xt-xs) * (co[i][1]-ys))) / (long double)(pow((yt-ys),2) + pow((xt-xs),2));
        long double x4 = co[i][0] - k * (yt-ys);
        long double y4 = co[i][1] + k * (xt-xs);
        long double t2=sqrt(pow(xs-x4,2)+pow(ys-y4,2));
        long double time;
        if(sqrt(pow(x4-xs,2)+pow(y4-ys,2))+sqrt(pow(x4-xt,2)+pow(y4-yt,2))==sqrt(pow(xt-xs,2)+pow(yt-ys,2))){
            time=sqrt(pow(x4-co[i][0],2)+pow(y4-co[i][1],2));
            cout << "yo\n";
        }
        else{
            time=sqrt(pow(xt-co[i][0],2)+pow(yt-co[i][1],2));
        }
        // cout << time << " : time , t2 : " << t2 << endl;
        ll tt1=(ll)time;
        ll tt2=(ll)t2;
        cout << tt1 << " : time , t2 : " << tt2 << endl;
        if(tt1 <= tt2){
            cout << "NO" << endl;
            return;
        }
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