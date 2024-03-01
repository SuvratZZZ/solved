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


bool ispalrec(string &s, int n,int l){
        if(l<=n){return true;}
        if((int)s[n]>=65 && (int)s[n]<=90) s[n]=(s[n]+32);
        if((int)s[l]>=65 && (int)s[l]<=90) s[l]=(s[l]+32);
        cout << n << " " << s[n] << " n s[n] l s[l] " << l << " " << s[l] << endl;
        if(((int)s[n]<97) || ((int)s[n]>122)){
            return ispalrec(s,n+1,l);
        }
        if(((int)s[l]<97) || ((int)s[l]>122)){
            return ispalrec(s,n,l-1);
        }
        if(s[n]!=s[l]){
            return false;
        }
        return ispalrec(s,n+1,l-1);
    }
    bool isPalindrome(string s) {
    
        return ispalrec(s,0,s.length()-1);
    }
int main(){
    string s;
    cin >> s;
    cout << isPalindrome(s);
    return 0;
}
