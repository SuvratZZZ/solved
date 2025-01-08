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
void solve(){
    ll n;
    cin>>n;
    ll msb=63-__builtin_clzll(n);
    vector<ll> res;
    map<ll,ll> mp;
    // cout << msb << endl;return;
    if(n%2){
        cout << n << endl;
        if(n==5){
                cout << "2 1 3 4 5 " ;
            cout << endl;return;
        }
        res.push_back(n);
        mp[n]=1;
        res.push_back(n-1);
        mp[n-1]=1;
        res.push_back(3);
        mp[(3)]=1;
        res.push_back(1);
        mp[(1)]=1;

        for (ll  i = 1; i <= n ; i++)
        {
            if(mp[i]==1){
                continue;
            }
            cout << i << " ";
        }
        for(ll i=res.size()-1;i>=0;i--){
            cout << res[i] << " ";
        }
        cout << endl;return;
    }
    cout << (1<<(msb+1))-1 << endl;
    if(n==6){
            cout << "1 2 4 6 5 3 " ;
        cout << endl;return;
    }
    res.push_back(1<<msb);
    mp[(1<<msb)]=1;
    res.push_back((1<<msb)-1);
    mp[(1<<msb)-1]=1;
    res.push_back((1<<msb)-2);
    mp[(1<<msb)-2]=1;
    res.push_back(3);
    mp[(3)]=1;
    res.push_back(1);
    mp[(1)]=1;

    for (ll  i = 1; i <= n ; i++)
    {
        if(mp[i]==1){
            continue;
        }
        cout << i << " ";
    }
    for(ll i=res.size()-1;i>=0;i--){
        cout << res[i] << " ";
    }
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