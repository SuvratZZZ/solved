#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main(){
    ll n;
    cin >> n;
    string tt ,t2;
    cin>> tt>> t2;
    string temp;
    temp.push_back(tt[0]);
    for (ll  i = 0; i < n ; i++)
    {
        temp=tt.substr(0,i+1)+t2.substr(i,n-i);
        cout << temp << endl;
    }
    return 0;
}