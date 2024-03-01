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

ll ncr(ll n, ll r){
    double sol=1;
    for (double i = 1; i <= r; i++)
    {
        sol=sol*((n-r+i)/i);
        // cout << n-r+i << " solution is " << sol << endl;
    }
    return (ll)sol;
}

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
long long lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
} 
void solve(){
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    ll res=0;
    map<pair<int,int>,int> mp;
    for (ll i = 0; i < n ; i++)
    {
        cin >> v[i];
        if(mp[{(x-v[i]%x)%x,v[i]%y}]){
            res=res+mp[{(x-v[i]%x)%x,v[i]%y}];

        }
        mp[{v[i]%x,v[i]%y}]++;
    }
        cout << res << endl;    
}
// void solve(){
//     ll n,x,y;
//     cin >> n >> x >> y;
//     ll tem = lcm(x,y);
//     map<int ,int> m;
//     map<int,int> cou ;
//     vector<ll> v(n);
//     // cout << tem << " tem " << endl;
//     for (ll i = 0; i < n ; i++)
//     {
//         cin >> v[i];
//         m[v[i]%tem]++;
//         cou[v[i]]++;
//     }
//     ll res=0;
//     for(auto it=m.begin(); it!=m.end(); it++ ){
//         if(m[tem-(it->first)]&&it->second){
//                 // cout << it->second << " it m  " << m[tem-(it->first)] << endl;
//             res=res+m[tem-(it->first)]*it->second;
//                 // cout << res  << endl;
//         }
//     }
 
//         // cout << "res 1 " <<  res << endl;

//     res=(res/2);
//     for(auto it=cou.begin(); it!=cou.end(); it++ ){
//         if((it->second>1)&&(it->first%tem!=0)&&(it->first%x==0)){
//                 // cout << it->second << " it m  " << endl;
//             res=res+ncr(it->second,2);
//                 // cout << res  << endl;
//         }
//     }

//         // cout << ncr(3,2) << endl;
//         // cout << "res 2 " <<  res << endl;

//     if (m[0])
//     {
//         cout << res << endl;
//         return;
//     }
    
//     res=res+(ncr(m[0],2));
//     cout << res << endl;
// }
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