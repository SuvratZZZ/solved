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
struct Pt {
    int x, y;
    Pt(int x = 0, int y = 0) : x(x), y(y) {}
};

int cross(const Pt &a, const Pt &b, const Pt &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(const Pt &a, const Pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// Compute the convex hull of a set of points
vector<Pt> hull(vector<Pt> &p) {
    int n = p.size();
    if (n <= 3) return p; // All points are part of the convex hull

    sort(p.begin(), p.end(), cmp); // Sort points lexicographically

    vector<Pt> h;
    h.reserve(2 * n);

    // Build the lower hull
    for (int i = 0; i < n; ++i) {
        while (h.size() >= 2 && cross(h[h.size() - 2], h.back(), p[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(p[i]);
    }

    // Build the upper hull
    int l = h.size();
    for (int i = n - 2; i >= 0; --i) {
        while (h.size() > l && cross(h[h.size() - 2], h.back(), p[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(p[i]);
    }

    h.pop_back(); // Remove the last point (it's the same as the first)
    return h;
}

long double dist(const Pt &a, const Pt &b) {
    return sqrtl((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

long double peri(const vector<Pt> &h) {
    long double p = 0.0;
    int n = h.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        p += dist(h[i], h[j]);
    }
    return p;
}
void solve(){
    ll n,mnx=INT_MAX,mxx=0;cin>>n;
    map<ll,set<ll>> mp;
    vector<Pt> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    vector<Pt> h = hull(p);

    long double p_val = peri(h);

    cout << p_val << endl;

    int ans = static_cast<int>(roundl(p_val));

    cout << ans << endl;
    // for (ll  i = 0; i < n ; i++)
    // {
    //     ll x,y;cin>>x>>y;
    //     mp[y].insert(x);
    //     mnx=min(mnx,x);
    //     mxx=max(mxx,x);
    // }
    // ll pl=((mp.begin()->first));
    // ll pr=((mp.begin()->first));
    // ll l=(*(mp.begin()->second.begin()));
    // ll r=(*(mp.begin()->second.rbegin()));
    // cout << l << r << endl;
    // long double res=r-l;
    // auto itr=mp.begin();
    // itr++;
    // while ((l>mnx||r<mxx)&&itr!=mp.end())
    // {
    //     if((*itr->second.begin())<)
    // }
    
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
    // cin >> t;
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