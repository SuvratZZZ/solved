#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n ;
    cin>>n;
    vector<int> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    ll p1=1,p2=0;
    for (ll  i = 1; i < n ; i++)
    {
        if(v[i]==v[0])p1++;
        if(v[i]!=v[0])p2=i+1;
    }
    if(p1==1){cout << 1 << endl;}
    else {cout << p2 << endl;}
    }
    return 0;
}