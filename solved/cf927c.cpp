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

// class BigInt{
//     string digits;
// public:
 
//     //Constructors:
//     BigInt(unsigned long long n = 0);
//     BigInt(string &);
//     BigInt(const char *);
//     BigInt(BigInt &);
 
//     //Helper Functions:
//     friend void divide_by_2(BigInt &a);
//     friend bool Null(const BigInt &);
//     friend int Length(const BigInt &);
//     int operator[](const int)const;
 
//                /* * * * Operator Overloading * * * */
 
//     //Direct assignment
//     BigInt &operator=(const BigInt &);
 
//     //Post/Pre - Incrementation
//     BigInt &operator++();
//     BigInt operator++(int temp);
//     BigInt &operator--();
//     BigInt operator--(int temp);
 
//     //Addition and Subtraction
//     friend BigInt &operator+=(BigInt &, const BigInt &);
//     friend BigInt operator+(const BigInt &, const BigInt &);
//     friend BigInt operator-(const BigInt &, const BigInt &);
//     friend BigInt &operator-=(BigInt &, const BigInt &);
 
//     //Comparison operators
//     friend bool operator==(const BigInt &, const BigInt &);
//     friend bool operator!=(const BigInt &, const BigInt &);
 
//     friend bool operator>(const BigInt &, const BigInt &);
//     friend bool operator>=(const BigInt &, const BigInt &);
//     friend bool operator<(const BigInt &, const BigInt &);
//     friend bool operator<=(const BigInt &, const BigInt &);
 
//     //Multiplication and Division
//     friend BigInt &operator*=(BigInt &, const BigInt &);
//     friend BigInt operator*(const BigInt &, const BigInt &);
//     friend BigInt &operator/=(BigInt &, const BigInt &);
//     friend BigInt operator/(const BigInt &, const BigInt &);
 
//     //Modulo
//     friend BigInt operator%(const BigInt &, const BigInt &);
//     friend BigInt &operator%=(BigInt &, const BigInt &);
 
//     //Power Function
//     friend BigInt &operator^=(BigInt &,const BigInt &);
//     friend BigInt operator^(BigInt &, const BigInt &);
     
//     //Square Root Function
//     friend BigInt sqrt(BigInt &a);
 
//     //Read and Write
//     friend ostream &operator<<(ostream &,const BigInt &);
//     friend istream &operator>>(istream &, BigInt &);
 
//     //Others
//     friend BigInt NthCatalan(int n);
//     friend BigInt NthFibonacci(int n);
//     friend BigInt Factorial(int n);
// };


void solve(){
    ll n,m;
    ll prod=1;
    cin>>n>>m;
    vector<ll> a(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    string ss;
    cin>>ss;
    ll l=0,r=n-1;
    stack<ll> st;
    vector<ll> res;
    for (ll  i = 0; i < n ; i++)
    {
        // cout << prod%m << " ";
        if (ss[i]=='L')
        {
            st.push(a[l]);
            l++;
        }
        else{
            st.push(a[r]);
            r--;
        }
    }

    while (!st.empty())
    {
        prod=prod*st.top();
        prod%=m;
        res.push_back(prod);
        st.pop();
    }
    for(auto i=res.rbegin();i!=res.rend();i++){
        cout << *i << " ";
    }
    cout << endl;
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