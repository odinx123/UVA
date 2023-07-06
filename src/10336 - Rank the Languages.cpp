#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void check(const vector<vector<char>>& grid, vector<vector<char>>& state, int y, int x, char pre) {
    if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() || state[y][x] == '1')
        return;
    if (grid[y][x] != pre)
        return;

    state[y][x] = '1';
    pre = grid[y][x];

    check(grid, state, y, x + 1, pre);
    check(grid, state, y + 1, x, pre);
    check(grid, state, y - 1, x, pre);
    check(grid, state, y, x - 1, pre);
}

int main() {
    int T = 0;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> grid(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        map<char, int> cnt;
        vector<vector<char>> state(m, vector<char>(n, '0'));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (state[i][j] == '0') {
                    check(grid, state, i, j, grid[i][j]);
                    ++cnt[grid[i][j]];
                }
            }
        }

        vector<pair<char, int>> res(cnt.begin(), cnt.end());
        stable_sort(res.begin(), res.end(), [] (const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        cout << "World #" << k << endl;
        for (const auto& p : res) {
            cout << p.first << ": " << p.second << endl;
        }
    }

    return 0;
}
