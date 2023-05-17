#include <iostream>
#include <memory>
using namespace std;

int main() {
    int n = 0, k = 0;
    while (cin >> n) {
        if (n == 0) break;
        cin >> k;

        int size_n = n*k*(n-1)/2;
        int p1 = 0, p2 = 0;
        string m1, m2;

        unique_ptr<int[]> win_num(new int[n]());
        unique_ptr<int[]> no_win(new int[n]());
        for (int i = 0; i < size_n; ++i) {
            cin >> p1 >> m1 >> p2 >> m2;

            if (m1 == m2) {
                ++no_win[p1-1];
                ++no_win[p2-1];
            }
            else if (m1 == "rock" && m2 == "scissors" || m1 == "scissors" && m2 == "paper" || m1 == "paper" && m2 == "rock") {
                ++win_num[p1-1];
            } else {
                ++win_num[p2-1];
            }
        }

        double every_win = k*(n-1.0);
        for (int i = 0; i < n; ++i) {
            if (no_win[i] == every_win) {
                cout << "-\n";
            }
            else
                printf("%.3f\n", win_num[i]/(every_win-no_win[i]));
        }
    }

    return 0;
}