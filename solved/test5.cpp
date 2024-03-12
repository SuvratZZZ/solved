#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve_case() {
    int n, c;
    cin >> n >> c;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int odd = 0, even = 0;
    ll ans = 1ll * (c + 1) * (c + 2) / 2;
        // cout << ans << " rs2 " << endl;
    for (int i = 0; i < n; i++) {
        ans -= s[i] / 2 + 1;
        ans -= c - s[i] + 1;
        if (s[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
        // cout << ans << " rs2 " << endl;
    ans += 1ll * even * (even + 1) / 2;
    ans += 1ll * odd * (odd + 1) / 2;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve_case();
    }
}