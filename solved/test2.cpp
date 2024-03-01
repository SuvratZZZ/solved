#include <bits/stdc++.h>
using namespace std;

#define ll long long

// void solve(){
//     ll n, k, m;
//     cin >> n >> k >> m;
//     string s;
//     cin >> s;

//     // Creating a set to store characters present in the input string 's'
//     set<char> present_chars;
//     for(char ch : s) {
//         present_chars.insert(ch);
//     }

//     // Creating a string to store the result
//     string result;

//     // Iterating through all possible characters of length 'n'
//     for (int i = 0; i < n; i++) {
//         char ch = 'a' + (i % k); // Generating characters from 'a' to 'a' + k - 1 in circular manner
//         if (present_chars.find(ch) == present_chars.end()) {
//             // If the character is not present in 's', add it to the result string
//             result += ch;
//         }
//     }

//     // If the length of the result string is not equal to 'n', it means we couldn't find all characters
//     // in the input string 's', so the answer is "NO"
//     if (result.length() != n) {
//         cout << "NO" << endl;
//     } else {
//         // If the result string has length 'n', then all characters are found in 's'
//         cout << "YES" << endl;
//         cout << result << endl;
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }



const int MOD = 1e9 + 7;

int sol(int n, int m, vector< vector<int> > &mat){
    vector<int> curr(m+1, 0);
    vector<int> prev(m+1, 0);
    curr[1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mat[i-1][j-1] == 0){
                curr[j] = (curr[j-1] + prev[j]) % MOD;
            }
            else{
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return curr[m];
}

int mazeObstacles(int n, int m, vector< vector<int> > &mat) {
    int res = sol(n, m, mat);
    return res;
}

int main() {
    // Example usage:
    vector<vector<int>> maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    int n = 3, m = 3;
    int result = mazeObstacles(n, m, maze);
    cout << "Number of unique paths: " << result << endl; // Output: 2
    return 0;
}
