#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    for (int k = 0; k < T; ++k) {
        int n = 0;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            long long int temp = 0, exp = 10;
            cin >> temp;
            for (int j = n-1; j >= 0; --j) {
                matrix[i][j] = temp%exp;
                temp /= exp;
            }
        }

        string ins;
        int num = 0;
        int add = 0;
        cin >> num;
        for (int l = 0; l < num; ++l) {
            cin >> ins;
            if (ins == "inc") ++add;
            else if (ins == "dec") --add;
            else if (ins == "row") {
                int r1 = 0, r2 = 0;
                cin >> r1 >> r2;
                for (int i = 0; i < n; ++i) {
                    swap(matrix[r1 - 1][i], matrix[r2 - 1][i]);
                }
            }
            else if (ins == "col") {
                int c1 = 0, c2 = 0;
                cin >> c1 >> c2;
                for (int i = 0; i < n; ++i) {
                    swap(matrix[i][c1 - 1], matrix[i][c2 - 1]);
                }
            }
            else if (ins == "transpose") {
                for (int i = 0; i < n; ++i) {
                    for (int j = i + 1; j < n; ++j) {
                        swap(matrix[i][j], matrix[j][i]);
                    }
                }
            }
        }

        cout << "Case #" << k + 1 << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]+add < 0)
                    cout << 10+((matrix[i][j]+add)%10);
                else
                    cout << (matrix[i][j]+add)%10;
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
