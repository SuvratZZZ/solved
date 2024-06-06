#include <bits/stdc++.h>
using namespace std;
# define ll long long


int main() {
    int tes;
    cin >> tes;
    while (tes>0) {
        int lenn, tee;
    cin >> lenn >> tee;
    ll res = 0;
    ll cha=5;
    for (int i = 1; i <= tee; i++) {
        res = res + (lenn + i) / i / i;
        cha++;
    }
    res--;
    cout << res << endl;
    tes--;
    }
    return 0;
}