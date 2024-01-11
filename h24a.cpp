#include <bits/stdc++.h>
using namespace std;
# define ll long long
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
int main(){
    ll t;
    cin>> t;
     while (t--)
        {
            ll a,b;
            cin >> a >> b;
            if ((a+b)%2==0)
            {
                cout << "Bob" << endl;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
    return 0;
}