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

class Mex {
private:
    map<ll, int> frequency;
    set<ll> missing_numbers;
    vector<ll> A;

public:
    Mex(vector<ll> const& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            missing_numbers.erase(x);
        }
        missing_numbers.erase(0);
    }

    ll mex() {
        return *missing_numbers.begin();
    }

    void update(ll new_value) {
        // if (--frequency[A[idx]] == 0)
        //     missing_numbers.insert(A[idx]);
        // A[idx] = new_value;
        // ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<ll,ll> che;
    vector<ll> b(n,0);
    // set<ll> mex;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    Mex mm(a);
    // auto fin=[&](ll xx)->ll{
    //     ll l=1,r=1e5;
    //     while (l<r)
    //     {
    //         ll mid=(l+r)/2;
    //         auto tem = mex.lower_bound(xx);
    //         if(tem==mex.end()){
    //             r=mid-1;
    //         }
    //         else if((*tem)==mid&&((tem-mex.begin())))
    //     }
        
    // };
    ll idx=n;
    for (ll  i = 0; i < n ; i++)
    {
        if(che[a[i]]==0){
            che[a[i]]=1;b[i]=a[i];
        }
        else{
            b[i]=mm.mex();
            mm.update(b[i]);
            idx++;
        }
    }
    
    for(auto i:b){
        cout << i << " " ;
    }
    cout << endl;
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