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
        ll n,sol=0;
        cin >> n;
        string s;
        cin >> s;
        int arr[26] = {0};
        for (ll i = 0; i < s.length(); i++)
        {
            if (arr[(int)s[i]-97]==1)
            {
                continue;
            }
            else{
                sol=sol+s.length()-i;
                arr[(int)s[i]-97]=1;
            }
        }
        
        cout << sol  << endl;

    }
    return 0;
}