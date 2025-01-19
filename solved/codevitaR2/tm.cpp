// typedef set<string> state_set;

// const int N = 8;

// // Movement directions for Queen, Rook, and Bishop
// const vector<pair<int, int>> queen_dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
// const vector<pair<int, int>> rook_dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// const vector<pair<int, int>> bishop_dirs = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

// // Convert current state to a unique string representation
// string encode_state(const vvll &pos) {
//     string s;
//     for (auto &p : pos) {
//         s += to_string(p[0]) + to_string(p[1]) + to_string(p[2]);
//     }
//     return s;
// }

// // Recursive solver with memoization
// ll solve(vvll pos, ll depth, ll current, unordered_map<string, ll> &dp) {
//     if (current == depth) return 1;
//     string state = encode_state(pos);
//     if (dp.find(state) != dp.end()) return 0;

//     ll res = 0;
//     set<pair<ll, ll>> occupied;
//     for (auto &p : pos) occupied.insert({p[1], p[2]});

//     for (size_t idx = 0; idx < pos.size(); idx++) {
//         auto piece = pos[idx][0];
//         vector<pair<int, int>> directions;

//         if (piece == 0) directions = queen_dirs;
//         else if (piece == 1) directions = rook_dirs;
//         else directions = bishop_dirs;

//         for (auto TT : directions) {
//             int dx=TT.first,dy=TT.second;
//             for (int step = 1; step < N; step++) {
//                 int nx = pos[idx][1] + dx * step;
//                 int ny = pos[idx][2] + dy * step;
//                 if (nx < 0 || nx >= N || ny < 0 || ny >= N || occupied.count({nx, ny})) break;

//                 auto new_pos = pos;
//                 new_pos[idx][1] = nx;
//                 new_pos[idx][2] = ny;
//                 res += solve(new_pos, depth, current + 1, dp);
//             }
//         }
//     }
//     return dp[state] = res;
// }

// void chess_solver() {
//     string input;
//     ll moves;
//     vvll pieces;

//     while (cin >> input) {
//         if (isdigit(input[0])) {
//             moves = stoll(input);
//             break;
//         }
//         vector<ll> piece(3);
//         if (input[0] == 'Q') piece[0] = 0;
//         else if (input[0] == 'R') piece[0] = 1;
//         else piece[0] = 2;
//         piece[1] = input[1] - 'A';
//         piece[2] = input[2] - '1';
//         pieces.pb(piece);
//     }

//     unordered_map<string, ll> dp;
//     cout << solve(pieces, moves, 0, dp) << endl;
// }