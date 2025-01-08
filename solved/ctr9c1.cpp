#include <bits/stdc++.h>
using namespace std;
# define ll long long

int find(unsigned ll x) {
    int msb = -1;
    while (x > 0) {
        x >>= 1;
        msb++;
    }
    return msb;
}
int main(){
    ll t=1;
    cin >> t;
    for(int jj = t; jj > 0 ; ){
        ll cho,fin,res=0;
        cin>>cho>>fin;
        ll tefin=(1<<(find(cho)+1))-1;
        for (ll  i = 1; i <= min(tefin,fin) ; i++)
        {
            if((cho!=i)&&((cho%(cho^i)==0)||(i%(cho^i)==0))){
            res++;
        }
        }
        cout << res << endl;
        jj -- ;
    }
    return 0;
}