#include <bits/stdc++.h>
using namespace std;
# define ll long long


void revvv(string &str)
{
    ll n = str.length();
 
    for (ll i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        ll n;
    cin >> n;
    string inpp;
    cin >> inpp;
    string reverse=inpp;
    bool ch=0;
    revvv(reverse);
    for (ll  i = 0; i < inpp.length()/2; i++)
    {
        if ((int)reverse[i]<(int)inpp[i])
        {
            ch=1;
            break;
        }
        else if((int)reverse[i]>(int)inpp[i]){
            ch = 0;
            break;
        }
        else{
            continue;
        }
    }
    if (ch)
    {
        cout << reverse+inpp << endl;
    }
    else{
        cout << inpp << endl;
    }
    }
    return 0;
}