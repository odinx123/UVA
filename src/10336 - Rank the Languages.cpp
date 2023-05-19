#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Data {
    int mark;
    int cnt;
    char c;
};

void dfs(vector<vector<char>>& gra, vector<vector<char>>& mark, char& target, int y, int x) {
    if (mark[y][x] != '0') return;
    if (gra[y][x] != target) return;

    mark[y][x] = '1';

    if (y > 0) dfs(gra, mark, target, y-1, x);
    if (y < gra.size()-1) dfs(gra, mark, target, y+1, x);
    if (x > 0) dfs(gra, mark, target, y, x-1);
    if (x < gra[0].size()-1) dfs(gra, mark, target, y, x+1);
}

int main() {
    int n = 0;
    cin >> n;
    for (int k = 0; k < n; ++k) {
        int H = 0, W = 0, cur_mark = 0;
        cin >> H >> W;
        vector<vector<char>> gra(H, vector<char>(W, ' '));
        // char, <mark_num, cnt>
        unordered_map<char, pair<int, int>> cnt;

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> gra[i][j];
            }
        }

        vector<vector<char>> mark(H, vector<char>(W, '0'));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (mark[i][j] == '0') {
                    dfs(gra, mark, gra[i][j], i, j);
                    if (cnt.find(gra[i][j]) == cnt.end())
                        cnt[gra[i][j]].first = cur_mark;
                    ++cnt[gra[i][j]].second;
                }
            }
        }

        vector<Data> ans;
        for (const auto& d : cnt) {
            ans.push_back({d.second.first, d.second.second, d.first});
        }
        sort(ans.begin(), ans.end(), [](Data& a, Data& b) {
            if (a.cnt == b.cnt)
                return a.c < b.c;
            return a.cnt > b.cnt;
        });

        cout << "World #" << k+1 << endl;
        for (const auto& d : ans) {
            cout << d.c << ": " << d.cnt << endl;
        }
    }

    // system("pause");
    return 0;
}
/*
2
4 8
ttuuttdd
ttuuttdd
uuttuudd
uuttuudd
9 9
bbbbbbbbb
aaaaaaaab
bbbbbbbab
baaaaacab
bacccccab
bacbbbcab
bacccccab
baaaaaaab
bbbbbbbbb
*/