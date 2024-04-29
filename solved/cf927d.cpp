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
    ll n;
    cin>>n;
    char su;
    cin>>su;
    map<char,vector<ll>> m;
    vector<pair<string,string>> res;
    for (ll  i = 0; i < 2*n ; i++)
    {
        string tem;
        cin>>tem;
        // cout << " t2 is " << t2 << endl; t2
        m[tem[1]].push_back(stoi(tem.substr(0,1)));
    }
    for(auto &i:m){
        sort(i.second.begin(),i.second.end());
        reverse(i.second.begin(),i.second.end());
    }
    ll cou=0;
    // for(auto i:m){
    //     if(i.first==su)cout << " trump : ";
    //     cout << i.first << " : " ;
    //     for(auto j : i.second){
    //         cout << j << " " ;
    //     }
    //     cout << endl;
    // }
    for(auto i=m.begin();i!=m.end();i++){
        if(i->first==su){
            continue;
        }
        while (i->second.size()>1)
        {
            if(i->second.size()<2)break;

            // cout << i->second.size() << " : size " << endl;
            // cout << to_string(i->second[i->second.size()-2])+i->first << " : this " << endl;
            res.push_back({to_string(i->second[i->second.size()-1])+i->first,to_string(i->second[i->second.size()-2])+i->first});
            i->second.pop_back();
            i->second.pop_back();
        }
        if (i->second.size()==1)
        {
            cou++;
        }

            // cout << " cou : " << cou  << endl; 
    }
    if ((m[su].size()>=cou) && (((m[su].size()-cou)%2)==0))
    {
        for(auto &i:m){
            if(i.first==su){
                continue;
            }
            if(i.second.size()==0)continue;
            res.push_back({to_string(i.second[i.second.size()-1])+i.first,to_string(m[su][m[su].size()-1])+su});
            i.second.pop_back();
            m[su].pop_back();
        }
        while (m[su].size()!=0)
        {
            res.push_back({to_string(m[su][m[su].size()-1])+su,to_string(m[su][m[su].size()-2])+su});
            // cout << m[su].size() << " : size " << endl;
            // cout << to_string(m[su][m[su].size()-1])+su << " : this " << endl;
            m[su].pop_back();
            m[su].pop_back();
        }
        for(auto i: res){
            cout << i.first << " " << i.second << endl;
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
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