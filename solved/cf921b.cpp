#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
int main(){
    ll t;
    cin>> t;
    while(t--){
        int x,n;
        cin >> x >> n;
        if (x%2==0)
        {
            if (n%2==1)
            {
                cout << ((x/n)%2?(x/n)-1:(x/n)) << endl; 
            }
            else cout << x/n << endl;
        }
        else{
            cout << x/n << endl;
        }
    }
    return 0;
}