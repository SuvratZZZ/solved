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
    ll p9[15]={
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
        100000000,
        1000000000,
        10000000000,
        100000000000,
        1000000000000,
        10000000000000,
        100000000000000,
    };
long long n4(long long n) {
    string num = to_string(n);
    int len = num.length();
    
    for (int i = 0; i < len; ++i) {
        if (num[i] == '4') {
            // Replace the current digit '4' with the highest possible digit <= '3'
            num[i] = '3';
            // Set all subsequent digits to '9'
            // for (int j = i + 1; j < len; ++j) {
            //     num[j] = '9';
            // }
            // break;
        }
    }
    
    // Convert the modified string back to a number
    long long result = stoll(num);

    // // Ensure that the result does not contain '4'
    // while (containsDigit4(to_string(result))) {
    //     result--;
    // }

    return result;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> da(19,1);
    // for (ll  i = 2; i <= 18 ; i++)
    // {
    //     da[i]=da[i-1]*9+p10[i-1];
    //     //cout << da[i-1]*9 << " da " << binpow(10,i-1) << endl];
    // }

    // // for (ll  i = 0; i < 19 ; i++)
    // // {
    // //     cout << da[i] << " " ;
    // // }
    // auto che=[&](const ll no )->bool
    // {
    //     ll curr=no ;
    //     ll res=0;
    //     while (curr>9)
    //     {
    //         ll st=curr/p10[(ll)floor(log10(curr))];
    //         // cout << st << " : st " << endl;
    //         for (ll  j  = st; j  > 0 ; j--)
    //         {
    //             if(j==4){
    //                 res+=p10[(ll)floor(log10(curr))];
    //                 continue;
    //             }
    //             res+=da[(ll)floor(log10(curr))];
    //         }
    //         curr%=p10[(ll)floor(log10(curr))];
    //     }
    //     if(curr>=4)res++;
    //     // cout << no - res << endl;
    //         return no-res<n ;
    // };
    // ll l=1,r=n+p10[(ll)ceil(log10(n)+1)];
    // cout << ceil(log10(50)) << endl;
    // while (l<r )
    // {
    //     ll mid=(l+r)/2;
    //     if(che(mid)){
    //         l=mid+1;
    //     }
    //     else{
    //         r=mid;
    //     }
    // }
    ll l=14,res=0;
    while ( n > 0||l>=0)
    {
        ll mid=0;
        if(n>=p9[l]){
            mid=n/p9[l];
            n%=p9[l];
            if(mid>=4){
                mid++;
            }
        }
    // cout << mid << endl;
        res=res*10+mid;
        l--;
    }
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
   for (ll  i = 0; i < 15; i++)
   {
        p9[i]=binpow(9,i);
   }
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
