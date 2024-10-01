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
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
        if (n % 2 == 0) {
            map<char, int> ecc;
            map<char, int> occ;

            for (int i = 0; i < s.length(); i++) {
                if (i % 2 == 0) {
                    ecc[s[i]]++;
                } else {
                    occ[s[i]]++;
                }
            }

            char emc = ' ';
            int emcou = 0;
            for (const auto& pair : ecc) {
                if (pair.second > emcou) {
                    emcou = pair.second;
                    emc = pair.first;
                }
            }

            char omc = ' ';
            int omcou = 0;
            for (const auto& pair : occ) {
                if (pair.second > omcou) {
                    omcou = pair.second;
                    omc = pair.first;
                }
            }

            int res = n / 2 - emcou + n / 2 - omcou;
            cout << res << endl;
        } else {
            if (n == 1) {
                cout << 1 << endl;
                return;
            }
            int rr = INT_MAX;
            unordered_map<char, int> ecc;
            unordered_map<char, int> occ;

            for (int i = 0; i < n - 1; i++) {
                if (i % 2 == 0) {
                    ecc[s[i]]++;
                } else {
                    occ[s[i]]++;
                }
            }

            unordered_map<char, int> ecaf;
            unordered_map<char, int> ocaf;

            char emc = ' ';
            int emcou = 0;
            for (const auto& pair : ecc) {
                if (pair.second > emcou) {
                    emcou = pair.second;
                    emc = pair.first;
                }
            }

            char omc = ' ';
            int omcou = 0;
            for (const auto& pair : occ) {
                if (pair.second > omcou) {
                    omcou = pair.second;
                    omc = pair.first;
                }
            }

            rr = min(rr, n / 2 - emcou + n / 2 - omcou);

            for (int i = n - 2; i >= 0; i--) {
                if (i % 2 == 0) {
                    ecc[s[i]]--;
                    ecaf[s[i + 1]]++;
                } else {
                    occ[s[i]]--;
                    ocaf[s[i + 1]]++;
                }

                unordered_map<char, int> ecomer = ecc;
                for (const auto& pair : ecaf) {
                    ecomer[pair.first] += pair.second;
                }

                unordered_map<char, int> ocmer = occ;
                for (const auto& pair : ocaf) {
                    ocmer[pair.first] += pair.second;
                }

                emcou = 0;
                for (const auto& pair : ecomer) {
                    if (pair.second > emcou) {
                        emcou = pair.second;
                    }
                }

                omcou = 0;
                for (const auto& pair : ocmer) {
                    if (pair.second > omcou) {
                        omcou = pair.second;
                    }
                }

                rr = min(rr, n / 2 - emcou + n / 2 - omcou);
            }

            if (n < 2) {
                cout << rr + 2 << endl;
            } else {
                cout << rr + 1 << endl;
            }
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //
    //
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}