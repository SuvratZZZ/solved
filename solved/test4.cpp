#include <bits/stdc++.h>
using namespace std;
# define ll long long

// index
// 1 substr_sum
// 2 bitwise left right
// 3 map - empty


// 1
void substr_sum(){
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
}

// 2
void bitwiselr(){
    ll n;
    cin >> n;
    ll tem= (1<<n);
    cout << tem << endl;
}

// 3
void mapii(){
    map<ll,ll> m;
    m[0]++;
    auto it=m.begin();
    it--;
    cout << it->first << " " << it->second ;
}


int main(){
    // bitwiselr();
    mapii();
    return 0;
}