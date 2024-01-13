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
            ll n;
            cin >> n ;
            string s;
            cin >> s;
            ll p1=0,p2=0;
            for (ll i = 0; i < s.length(); i++)
            {
                if (s[i]=='+')
                {
                    p1++;
                }
                else p2++;
                if (p1==p2)
                {
                    p1=0;p2=0;
                }   
            }
            cout << abs(p1-p2) << endl;
        }
    return 0;
}