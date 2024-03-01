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
    ll n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    string res;
    res.push_back(s1[0]);
    bool change=1;
    for (ll  i = 1; i < n ; i++)
    {
        if (s1[i]=='1'&&s2[i-1]=='0')
        {
            res.push_back(s2[i-1]);
            change=0;
        }
        if (change)
        {
            res.push_back(s1[i]);
        }
        else{
            res.push_back(s2[i]);
        }

        if ((i==n-1)&&change)
        {
            res.push_back(s2[i]);
        }
        
    }
    
    string temp;
    ll count =0;
    for (ll  i = 0; i < n ; i++)
    {
        temp=s1.substr(0,i+1)+s2.substr(i,n-i);
        if(temp==res){
            count ++;
        }
    }
    
    
    cout << res << endl << count << endl;
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