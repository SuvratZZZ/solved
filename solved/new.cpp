#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    ll tess;
    cin >> tess;
    while(tess--){
        ll lwnn,key,mera,pe=0,du=0,cha=0,at=0,okok=1;
    cin>>lwnn>>key;
    vector<ll>vee(lwnn);
    for (ll  i = 0; i < lwnn ; i++)
    {
        cin>>vee[i];
    }
    mera=vee[key-1];
    for (ll  i = 0; i < lwnn ; i++){
        if((vee[i]<mera)&&(cha==0)){
            pe++;
        }
        if(vee[i]>mera){
            cha++;
            if ((cha==1)&&(okok==1))
            {
                at=i;
                okok=0;
            }
            
        }
        if ((cha==1)&&(vee[i]<mera)&&(i<key-1)){
            du++;
        }
    }
    if (key==1||lwnn==2){
        cout << pe << endl;
    }
    else if(at+1>key){
        cout << pe << endl;
    }
    else{
        cout << max(pe-1,du+1) << endl;
    }
    }
    // ok
    return 0;
}