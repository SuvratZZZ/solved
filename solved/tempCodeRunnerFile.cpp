void solve(){
    ll l,r,k;
    cin>>l>>r>>k;
    ll res=0,too=ceil((float)10/k);
    cout << res << " r : t " << too << endl;
    res=((too-1)*poo(too,l))%mod;
    cout << res << " r : aat " << poo(too,l) << endl;
    res=(res*((poo(too,r-l)%mod)-1))%mod;
    cout << res << " r : +t " << ((poo(too,r-l)%mod)-1) << endl;
    res=(res*poo(too-1,mod-2))%mod;
    cout << res << " r : //t " <<poo(too-1,mod-2)<< endl;
    cout << res << endl;
}