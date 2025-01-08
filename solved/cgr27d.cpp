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
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}

ll ex2(ll &n){
    ll cou=0;
    while (n%2==0&&n!=0)
    {
        n=n/2;
        cou++;
    }
    return cou;
}

bool comp(pair<ll,ll> &pp,ll a, ll c2){
    if(a>pp.first)return true;
    c2+=ex2(a);
    if(a>pp.first)return true;
    while (c2--)
    {
        a=a*2;
        if(a>pp.first)return true;
    }
    return false;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    vector<ll> res(n);
    ll mx=0,sum=0;
    // sg_mx ss(a);
    res[0]=a[0];
    stack<pair<ll,ll>> st;
    sum+=a[0];
    ll t2=ex2(a[0]);
    st.push({a[0],t2});
    for (ll  i = 1; i < n ; i++)
    {
        ll c2=0; 
        ll tem=a[i];
        while ((!st.empty())&&comp(st.top(),a[i],c2))
        {
            // cout << st.top().first << " removed " << st.top().second << endl;
            sum-=(st.top().first*binpow(2,st.top().second))%mod;
            sum=(sum+mod)%mod;
            c2+=st.top().second+ex2(st.top().first);
            sum+=st.top().first;
            st.pop();
        }
        // cout << a[i] << " added " << c2<< endl;
        ll t2=ex2(a[i]);
        st.push({a[i],c2+t2});
        tem=(tem*binpow(2,c2))%mod;
        tem%=mod;
        sum+=tem;
        sum=sum%mod;
        res[i]=sum;
    }
    for(auto i:res)cout << i << " ";
    cout << endl;
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
    return 0;
}