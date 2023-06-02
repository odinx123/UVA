#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    // 輸出會有只有換行的
    while (getline(cin, s1) && getline(cin, s2)) {
        // 對於每列都是s1的字元跑過s2的每個字元，而對於每行都是s2的字元跑過s1的每個字元
        // 對於公共子序列，是要有順序的，所以每個col都不能先後面的col則順序不對(row當然也是)
        vector<vector<int>> LCM(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        // 每列都代表一次s1的字元
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++)
                if (s1[i-1] == s2[j-1])  // s1、s2的長度位置跟LCM不一樣i-1、j-1是當前位置
                    // s1的上個字元跟s2的上個字元的最大公共子序列 + 1
                    LCM[i][j] = LCM[i - 1][j - 1] + 1;
                else
                    // 若不相等，就在s1的上個字元到當前s2的最大值，或是上個s2的最大值(正在找的這個s2字元)
                    LCM[i][j] = max(LCM[i - 1][j],LCM[i][j - 1]);
        }

        cout << LCM[s1.size()][s2.size()] << endl;
    }

    return 0;
}
