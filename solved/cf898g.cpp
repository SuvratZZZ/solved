#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
    string s;
    cin>> s;
    ll res=0,coua=0,tem=0;
    ll mina=INT_MAX,bb=0;
    for (ll  i = 0; i < s.length(); i++)
    {
        if(s[i]=='B'&&s[i+1]=='B'){
            bb=1;
        }
        if (s[i]=='A')
        {
            // cout << " enter a " << endl;
            coua++;
            tem++;
        }
        if (s[i]=='B')
        {

            // cout << " enter b " << endl;
            mina=min(mina,tem);
            tem=0;
        }
    }
        // cout << "end b :  " << (s[s.size()-1]=='B') << endl;
        // cout << "start b :  " << (s[0]=='B') << endl;
        // cout << "bb : " << bb << endl;
        // cout << "coua    : " <<  coua   << endl;
        // cout << "mina : " << mina << endl;
        if ((s[0]=='B')||(s[s.length()-1]=='B')||bb)
        {
            cout << coua << endl;
        }
        else
        cout << coua-min(mina,tem) << endl;
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
