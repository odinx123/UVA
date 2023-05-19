#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, m = 0;
    while (cin >> n >> m) {
        vector<int> ans(1, n);

        bool flag = false;
        if (m == 0 || m == 1 || n == 0 || n == 1) {
            cout << "Boring!" << endl;
            continue;
        }
        while (!flag && n != 1) {
            if (n % m == 0) {
                ans.push_back(n / m);
                n /= m;
            }
            else {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "Boring!\n";
        }
        else {
            for (int i = 0; i < ans.size(); ++i) {
                if (i)
                    cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }
    }

    // system("pause");
    return 0;
}
/*
125 5
30 3
80 2
81 3
*/
