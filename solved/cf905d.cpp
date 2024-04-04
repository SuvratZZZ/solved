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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t;
    cin >> t;
    multiset<ll> sta;
    multiset<ll> end;
    while(t--){
        string s;
        ll st,en;
        cin>>s>>st>>en;
                // cout << "begin : " << *sta.begin() << " end : " << *end.rbegin() << endl;
        if (s=="+")
        {
            sta.insert(st);
            end.insert(en);
            if (*sta.rbegin()<=*end.begin())
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        else
        {
            auto it1=sta.find(st);
            sta.erase(it1);
            auto it2=end.find(en);
            end.erase(it2);
            if (sta.empty())
            {
                cout << "NO" << endl;
            }
            else if (*sta.rbegin()<=*end.begin())
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        // for(auto i:sta)cout << i << " ";
        // cout << "sta "<< endl;
        // for(auto i:end)cout << i << " ";
        // cout << "end "<< endl;
        
        
    }
    return 0;
}