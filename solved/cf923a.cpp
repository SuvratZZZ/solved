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
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res=0,star=0,end=-1;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='B')
        {
            star=i;
            break;
        }
        
    }
    for (int i = n-1; i >=0 ; i--)
    {
        if (s[i]=='B')
        {
            end=i;
            break;
        }
        
    }
    if (star==0&&end==-1)
    {
        cout << 0 << endl;
    }
    
    cout << end-star+1 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
