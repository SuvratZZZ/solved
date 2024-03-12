#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
//
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
void sss(){
    
    int t = 1;
    std::cin >> t;
    while (t--) {
        int n, L;
        std::cin >> n >> L;
        std::vector<std::pair<int, int>> v(n);
        for (int i = 0 ; i < n ; i++) {
            std::cin >> v[i].second >> v[i].first;
        }
        sort(v.begin(), v.end());

        int ans = 0;
        for (int l = 0 ; l < n ; l++) {
            multiset<int> s;
            int cur = 0;
            for (int r = l ; r < n ; r++) {
                s.insert(v[r].second);
                cur += v[r].second;
                while (!s.empty() && v[r].first - v[l].first + cur > L) {
                    int max_value = *s.rbegin();
                    cur -= max_value;
                    auto it = s.end();
                    it--;
                    s.erase(it);
                }
                ans = std::max(ans, (int) s.size());
            }
        }
        cout << ans << endl;
    }
}
void solve(){
    ll n,l;
    cin >> n >> l;
    vector<pair<ll,ll>> ma(n);
    for (ll i = 0; i < n; i++)
    {
        ll t1,t2;
        cin>>t1>>t2;
        ma[i]={t2,t1};
    }
    sort(ma.begin(),ma.end());
    ll sum=0,cut=n;
    ll mi=INT_MAX,mx=0;
    for (ll  l = 0; l < n ; l++)
    {
            multiset<ll> s;
            ll cnt=0;
        for (ll  r = l; r < n ; r++)
        {
            s.insert(ma[r].second);
            cnt=cnt+ma[r].second;
            while (!s.empty()&&ma[r].first-ma[l].first+cnt>l)
            {
                ll mxv=*s.rbegin();
                cnt=cnt-mxv;
                auto it=s.end();
                it--;
                s.erase(it);
            }
            mx=max(mx,(ll)s.size());
        }
        
    }
    cout << mx << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        sss();
    return 0;
}