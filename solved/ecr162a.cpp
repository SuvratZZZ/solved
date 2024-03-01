#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin >> n;
    vector <int > a(n);
    int count =0;
    int start=0
    int end=0;
    for (int  i = 0; i < n ; i++)
    {
        cin >> a[i];
        if (a[i]==0)
        {
            count++;
        }
        
    }
    for (int  i = 0; i < n ; i++)
    {
        if (a[i]==0)
        {
            start++;
        }
        if (a[i]==1)
        {
            break;
        }
        
    }
    for (int  i = n-1; i >= 0 ; i--)
    {
        if (a[i]==0)
        {
            end++;
        }
        if (a[i]==1)
        {
            break;
        }
    }
    cout << (count-start)-end << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}