#include <bits/stdc++.h>
using namespace std;
# define ll long long


int main(){
    ll tes ;
    cin >> tes ;
    while(tes --){
        ll len ,c1  =0,cc2 =0;
    cin >> len ;
    string stsy ,t1 ,t2;
    cin >> stsy ;
    for (ll  i = 0; i < len -2 ; i++)
    {
        t1  = stsy .substr(i,3);
        
        if (t1 =="map"||t1 =="pie")
        {
            c1  ++;
        }
        if (i<len -4)
        {
            t2 =stsy .substr(i,5);
            if (t2 =="mapie")
            {
                cc2  ++;
            }
            
        }
        
    }
    // adding the two 
        cout << c1 -cc2  << endl;
    }
    return 0;
}   