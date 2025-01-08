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
void solve(){
    string s;cin>>s;
    ll sta=0,l=1,r=s.length(),a=1,b=s.length(),che=0,cou=0;
    for (ll  i = 0; i < s.length(); i++)
    {
        if(s[i]=='1'){
            che=1;
            break;
        }
    }
    if(che==0){
        cout << l << " " <<  r << " " << a << " " << b << endl;
        return;
    }
    che=0;
    for (ll  i = 0; i < s.length(); i++)
    {
        if(s[i]=='0'){
            che=1;
            break;
        }
    }
    if(che==0){
        cout << l << " " <<  r << " " << 1 << " " << 1 << endl;
        return;
    }
    for (ll  i = 0; i < s.length() ; i++)
    {
        if(s[i]=='0'&&sta==1){
            b=i;
            sta++;
        }
        else if(s[i]=='1'&&sta==0){
            l=i+1;
            a=i+1;
            sta++;
        }
        else if(sta==2){
            if(s[i]=='0'){
                cou++;
            }
            else{
                a=b-cou;
                a=max(l,a);
                break;
            }
        }
    }
    if(sta==1){
        cout << l << " " <<  r << " " << 1 << " " << 1 << endl;
        return;
    }
    ll len=s.length()-b,pr=0,mpr=0;
    b=a+len-1;
        cout << l << " " <<  r << " " << a << " " << b << endl;
    
    
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