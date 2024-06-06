#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll t;
    cin >> t;
    while(t--){
        string a,b;
        cin>>a>>b;
        if(a[a.size()-1]<b[b.size()-1]){
            cout << '>' << endl;
            continue;
        }
        if(a[a.size()-1]>b[b.size()-1]){
            cout << '<' << endl;
            continue;
        }
        if (a[a.size()-1]=='S')
        {
            int c1 = count(a.begin(), a.end(), 'X');
            int c2 = count(b.begin(), b.end(), 'X');
            if (c1==c2)
            {
                cout << '=' << endl;
                continue;
            }
            cout << (c1>c2?'<':'>') << endl;
        }
        else if (a[a.size()-1]=='L')
        {
            int c1 = count(a.begin(), a.end(), 'X');
            int c2 = count(b.begin(), b.end(), 'X');
            if (c1==c2)
            {
                cout << '=' << endl;
                continue;
            }
            
            cout << (c1>c2?'>':'<') << endl;
        }
        else{
            cout << '=' << endl;
        }
    }
    return 0;
}