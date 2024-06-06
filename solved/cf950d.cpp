#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,arr,arr2) for(ll i=arr;i<arr2;i++)
//
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;

int gcd(int aaa, int bbb) 
{ 
    int resss = min(aaa, bbb); 
    while (resss > 0) { 
        if (aaa % resss == 0 && bbb % resss == 0) { 
            break; 
        } 
        resss--; 
    } 
    return resss; 
}
void solve(){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        std::vector<int> arr2(n - 1);
        for (int i = 0; i < n - 1; i++) {
            arr2[i] = __gcd(arr[i], arr[i + 1]);
        }

        int iii = -1;
        for (int i = 0; i < n - 2; i++) {
            if (arr2[i] > arr2[i + 1]) {
                iii = i;
                break;
            }
        }

        if (iii == -1) {
            cout << "YES" << endl;
            return;
        }

        int rrr = gcd(1,2);
        // cout << r << endl;
        vector<int> xx, yy, zz;
        for (int i = 0; i < n; i++) {
            if (i != iii + 1) {
                xx.push_back(arr[i]);
            }
            if (i != iii + 2) {
                yy.push_back(arr[i]);
            }
            if (i != iii) {
                zz.push_back(arr[i]);
            }
        }

        vector<int> b1(xx.size() - 1), b2(yy.size() - 1), b3(zz.size() - 1);
        for (int i = 0; i < xx.size() - 1; i++) {
            b1[i] = __gcd(xx[i], xx[i + 1]);
        }
        for (int i = 0; i < yy.size() - 1; i++) {
            b2[i] = __gcd(yy[i], yy[i + 1]);
        }
        for (int i = 0; i < zz.size() - 1; i++) {
            b3[i] = __gcd(zz[i], zz[i + 1]);
        }

        bool f1 = true;
        for (int i = 0; i < b1.size() - 1; i++) {
            if (b1[i] > b1[i + 1]) {
                f1 = false;
                break;
            }
        }
        bool f2 = true;
        for (int i = 0; i < b2.size() - 1; i++) {
            if (b2[i] > b2[i + 1]) {
                f2 = false;
                break;
            }
        }
        bool f3 = true;
        for (int i = 0; i < b3.size() - 1; i++) {
            if (b3[i] > b3[i + 1]) {
                f3 = false;
                break;
            }
        }
        // cout << iii << " i" ;
        if (!(f1 || f2 || f3)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}