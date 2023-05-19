#include <iostream>
#include <unordered_map>
using namespace std;

// 教訓: 看不懂題目就先分析測資(像這題如果看到口號對應就要想到一個口號對應另個口號)
int main() {
    int n = 0;
    (cin >> n).get();
    string s1, s2;
    unordered_map<string, string> m;

    for (int i = 0; i < n; ++i) {
        getline(cin, s1);
        getline(cin, s2);
        m[s1] = s2;
    }

    int Q = 0;
    (cin >> Q).get();
    for (int i = 0; i < Q; ++i) {
        getline(cin, s1);
        cout << m[s1] << endl;
    }

    // system("pause");
    return 0;
}
