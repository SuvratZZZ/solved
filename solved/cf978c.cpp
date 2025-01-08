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

ll hel(vector<vector<ll>> &dp,ll ind,ll ta,string &s1,string &s2){
    if(ind>=dp.size())return 0;
    if(ind==(dp.size()-1))return INT_MAX;
    if(dp[ind][ta]!=-1)return dp[ind][ta];
    ll res=INT_MIN,c1=0,c2=0;
    if(ta==0){
        if(ind+2<dp.size()){
            c1=0;
            c2=0;
            for(ll i=0;i<3;i++){c1+=(ll)(s1[ind+i]=='A');c2+=(ll)(s2[ind+i]=='A');}
            res=max(res,(c1>1)+(c2>1)+hel(dp,ind+3,0,s1,s2));
        }   
        c1=0+(ll)(s1[ind]=='A')+(s2[ind]=='A')+(s1[ind+1]=='A');
        res=max(res,(c1>1)+hel(dp,ind+1,1,s1,s2));
        c2=0+(ll)(s1[ind]=='A')+(s2[ind]=='A')+(s2[ind+1]=='A');
        res=max(res,(c2>1)+hel(dp,ind+1,2,s1,s2));
    }
    if(ta==1){
        if(ind+3<dp.size()){
            c1=0;
            c2=0;
            for(ll i=0;i<3;i++){c1+=(s1[ind+i+1]=='A');c2+=(ll)(s2[ind+i]=='A');}
            res=max(res,(c1>1)+(c2>1)+hel(dp,ind+3,ta,s1,s2));
        }   
        c1=0+(s2[ind]=='A')+(s2[ind+1]=='A')+(s1[ind+1]=='A');
        res=max(res,(c1>1)+hel(dp,ind+2,0,s1,s2));
    }
    if(ta==2){
        if(ind+3<dp.size()){
            c1=0;
            c2=0;
            for(ll i=0;i<3;i++){c1+=(ll)(s1[ind+i]=='A');c2+=(s2[ind+i+1]=='A');}
            res=max(res,(c1>1)+(c2>1)+hel(dp,ind+3,ta,s1,s2));
        }   
        c1=0+(ll)(s1[ind]=='A')+(s1[ind+1]=='A')+(s2[ind+1]=='A');
        res=max(res,(c1>1)+hel(dp,ind+2,0,s1,s2));
    }
    return dp[ind][ta]=res;
}
void solve(){
    ll n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<ll>> dp(n,vector<ll>(3,-1));
    cout << hel(dp,0,0,s1,s2) << endl;
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
    cin >> t;
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