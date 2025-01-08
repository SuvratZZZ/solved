#include <bits/stdc++.h>
using namespace std;
# define ll int


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


// const ll N = 2000;
// const ll INF = 1000000000000000000;
// const ll M = 998244353;
// const ll mod = 1e9+7;
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
ll dp[5001][5001];
vector<vector<ll>> ent;
vector<vector<ll>> tel;
ll sol(ll str,ll ind,vector<ll> &a,vector<ll>&po2a){
    if(ind==a.size())return 0;
    if(dp[ind][str]!=-1)return dp[ind][str];
    ll res=0;
    ll r2=0;
    ll stren = upper_bound(ent[ind].begin(),ent[ind].end(),str)-ent[ind].begin();
    ll intel = upper_bound(tel[ind].begin(),tel[ind].end(),po2a[a[ind]]-str)-tel[ind].begin();
    // if(intel!=tel[ind].end()){
    //     if((po2a[a[ind]]-str)>=(*intel)){r2++;
    //     cout << po2a[a[ind]]-str-1 << " : +1 at ind : " << ind << " also no 1 : " << *(intel) << endl;}
    // }
        r2+=stren;
        r2+=intel;
        cout << r2 << " : r1 at ind : " << ind << "x" << str  << endl;
    res=r2+sol(str,ind+1,a,po2a);
    // r2=0;
    // // auto stren2 = upper_bound(ent[ind].begin(),ent[ind].end(),str+1);
    // // auto intel2 = upper_bound(tel[ind].begin(),tel[ind].end(),po2a[a[ind]]-str-1);
    // if(stren!=ent[ind].end()){
    //     if((str+1)>=(*stren)){r2++;
    //     cout << str << " : +2 at ind : " << ind << " also no 1 : " << *(stren) << endl;}
    // }
    //     r2+=stren-ent[ind].begin();
    //     r2+=intel-tel[ind].begin();
    //     cout << r2 << " : r2 at ind : " << ind << "x" << str  << endl;
    res=max(res,r2+sol(str+1,ind+1,a,po2a));
    return dp[ind][str]=res;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> a2;
    vector<ll> tem(n,0);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(i==0){
            tem[i]=(a[i]==0?1:0);
        }
        else{
            tem[i]=tem[i-1]+(a[i]==0?1:0);
        }
    }
    ent.resize(m+1);
    tel.resize(m+1);
    ll curr=0;
    for (ll  i = 0; i < n ; i++)
    {
        if(a[i]==0){
            a2.push_back(i);
            curr++;
        }
        else{
            // if(curr!=-1){
                if(a[i]>0)
                tel[curr].push_back(a[i]);
                else
                ent[curr].push_back(-1*a[i]);
            // }
        }
    }
    // dp.clear();
    // dp.resize(m+1);
    // for (ll  i = 0; i < m+1 ; i++)
    // {
    //     dp[i].resize(m+1,-1);
    // }
    for(auto &i:ent){
        sort(i.begin(),i.end());
    }
    for(auto &i:tel){
        sort(i.begin(),i.end());
    }
    // for(auto i:ent){
    //     cout << i.first << " : ";
    //     for(auto j:i.second)
    //     cout << j << " ";
    //     cout << endl;
    // }
    // for(auto i:tel){
    //     cout << i.first << " : ";
    //     for(auto j:i.second)
    //     cout << j << " ";
    //     cout << endl;
    // }
    memset(dp,-1,sizeof(dp));
    cout << sol(0,0,a2,tem) << endl;
    for (ll  i = 0; i < m+1 ; i++)
    {
        for (ll  j  = 0; j  < m+1 ; j ++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main(){
    //clock_t start;  
    //if(JUD)
    //start = clock(); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   //fill_factor();
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    //if(JUD)
    //{
    //	clock_t stop = clock();
    //	double duration = double(stop - start) / CLOCKS_PER_SEC;
    //	cout << "Time taken by function: " << duration << " seconds" << endl;
    //}
    //return 0;
}