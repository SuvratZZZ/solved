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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,vector<ll>> mp;
    for (ll  i = 0; i < n ; i++)
    {
        if(s[i]=='b'||s[i]=='a'||s[i]=='c'||s[i]=='k'||s[i]=='f'||s[i]=='r'||s[i]=='o'||s[i]=='n'||s[i]=='t')
            mp[s[i]].push_back(i);
    }
    // for(auto &i:mp){
    //     reverse(i.second.begin(),i.second.end());
    // }
    // for(auto i:mp){
    //     cout << i.first << " : ";
    //     for(auto j:i.second){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    ll cb=0,cf=0;
    // while(1){
    //     if(mp['b'].empty()){
    //         break;
    //     }
    //     ll tem=*mp['b'].rbegin();
    //     if(mp['a'].empty()){
    //         break;
    //     }
    //     while ((*mp['a'].rbegin()<=tem)&&(mp['a'].empty()==0))
    //     {
    //         mp['a'].pop_back(); 
    //     }
    //     if(mp['a'].empty()){
    //         break;
    //     }
    //     tem=*mp['a'].rbegin();
    //     if(mp['c'].empty()){
    //         break;
    //     }
    //     while ((*mp['c'].rbegin()<=tem)&&(mp['c'].empty()==0))
    //     {
    //         mp['c'].pop_back(); 
    //     }
    //     if(mp['c'].empty()){
    //         break;
    //     }
    //     tem=*mp['c'].rbegin();
    //     if(mp['k'].empty()){
    //         break;
    //     }
    //     while ((*mp['k'].rbegin()<=tem)&&(mp['k'].empty()==0))
    //     {
    //         mp['k'].pop_back(); 
    //     }
    //     if(mp['k'].empty()){
    //         break;
    //     }
    //     cb++;
    //         mp['b'].pop_back(); 
    //         mp['b'].push_back(0); 
    //         mp['a'].pop_back(); 
    //         mp['c'].pop_back(); 
    //         mp['k'].pop_back(); 
    // }
    // while(1){
    //     if(mp['f'].empty()){
    //         break;
    //     }
    //     ll tem=*mp['f'].rbegin();
    //     if(mp['r'].empty()){
    //         break;
    //     }
    //     while ((*mp['r'].rbegin()<=tem)&&(mp['r'].empty()==0))
    //     {
    //         mp['r'].pop_back(); 
    //     }
    //     if(mp['r'].empty()){
    //         break;
    //     }
    //     tem=*mp['r'].rbegin();
    //     if(mp['o'].empty()){
    //         break;
    //     }
    //     while ((*mp['o'].rbegin()<=tem)&&(mp['o'].empty()==0))
    //     {
    //         mp['o'].pop_back(); 
    //     }
    //     if(mp['o'].empty()){
    //         break;
    //     }
    //     tem=*mp['o'].rbegin();
    //     if(mp['n'].empty()){
    //         break;
    //     }
    //     while ((*mp['n'].rbegin()<=tem)&&(mp['n'].empty()==0))
    //     {
    //         mp['n'].pop_back(); 
    //     }
    //     if(mp['n'].empty()){
    //         break;
    //     }
    //     tem=*mp['n'].rbegin();
    //     if(mp['t'].empty()){
    //         break;
    //     }
    //     while ((*mp['t'].rbegin()<=tem)&&(mp['t'].empty()==0))
    //     {
    //         mp['t'].pop_back(); 
    //     }
    //     if(mp['t'].empty()){
    //         break;
    //     }
    //     cf++;
    //         mp['f'].pop_back(); 
    //         mp['r'].pop_back(); 
    //         mp['o'].pop_back(); 
    //         mp['n'].pop_back(); 
    //         mp['t'].pop_back(); 
    //         mp['t'].insert(mp['t'].begin(),1e6); 
    // }
    while(1){
        if(mp['b'].empty()){
            break;
        }
        ll tem=*mp['b'].begin();
        auto it1=upper_bound(mp['a'].begin(),mp['a'].end(),tem);
        if(it1==mp['a'].end()){
            break;
        }
        tem=*it1;
        auto it2=upper_bound(mp['c'].begin(),mp['c'].end(),tem);
        if(it2==mp['c'].end()){
            break;
        }
        tem=*it2;
        auto it3=upper_bound(mp['k'].begin(),mp['k'].end(),tem);
        if(it3==mp['k'].end()){
            break;
        }
        tem=*it3;
        cb++;
            *mp['b'].begin()=0; 
            mp['a'].erase(it1); 
            mp['c'].erase(it2); 
            mp['k'].erase(it3); 
    }
    while(1){
        if(mp['f'].empty()){
            break;
        }
        ll tem=*mp['f'].begin();
        auto it1=upper_bound(mp['r'].begin(),mp['r'].end(),tem);
        if(it1==mp['r'].end()){
            break;
        }
        tem=*it1;
        auto it2=upper_bound(mp['o'].begin(),mp['o'].end(),tem);
        if(it2==mp['o'].end()){
            break;
        }
        tem=*it2;
        auto it3=upper_bound(mp['n'].begin(),mp['n'].end(),tem);
        if(it3==mp['n'].end()){
            break;
        }
        tem=*it3;
        auto it4=upper_bound(mp['t'].begin(),mp['t'].end(),tem);
        if(it4==mp['t'].end()){
            break;
        }
        tem=*it4;
        cf++;
            *mp['f'].begin(); 
            mp['t'].push_back(1000000); 
            mp['r'].erase(it1); 
            mp['o'].erase(it2); 
            mp['n'].erase(it3); 
            mp['t'].erase(it4); 
    }
    // cout << cb << endl;
    cout << n-(cb*3)-(cf*4) << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}