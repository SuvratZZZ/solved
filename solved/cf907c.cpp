#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
using namespace std;
# define ll long long

void solve(){
    ll n;
    cin >> n;
    multiset<ll> s;
    for (ll  i = 0; i < n ; i++)
    {
        ll tem;
        cin >> tem ;
        s.insert(tem);
    }
    auto lef=s.multiset::begin();
    auto rig=s.multiset::end();
    rig--;
    ll x=0,cou=0;
    ll flag=0;
    while (lef!=rig)
    {
        x=x+(*lef);
        // cou = cou + (*lef);
        if (x>=(*rig ))
        {
            // cout << x << " : x rig : " << (*rig) << endl;
            cou = cou+(*rig);
            x=x-(*rig );
            rig--;
            cou ++;
            if (rig==lef)
            {
                flag=1;
                break;
            }
        }
        // cout << "x at out : " << x << " at lef : " << (*lef) << endl;
        // cout << "cou inside : " << cou << endl;
        lef++;
    }
    if (flag )
    {
        if(x==0)
            cout << cou << endl;
        else{
            cou = cou + (x+1)/2+(x==1?0:1);
            // cout << "cou : " << cou << endl;
            cout << cou << endl;
        }
    }
    else{
        cou = cou + (x+(*lef)+1)/2+(x+(*lef)==1?0:1);
        // cout << "cou : " << cou << endl;
        cout << cou << endl;
    }
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