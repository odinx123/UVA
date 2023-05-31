#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0;
    while (cin >> N) {
        if (N == 0) {
            cout << "1 = 0" << endl;
            continue;
        }
        vector<long long int> r(N);
        for (int k = 0; k < N; ++k) {
            cin >> r[k];
            r[k] = -r[k];
        }

        vector<long long int> pol;
        pol.push_back(1);
        pol.push_back(r[0]);
        // pol多一倍x減去原本pol*r[i]
        for (int i = 1; i < N; ++i) {
            vector<long long int> temp = pol;
            temp.push_back(pol.back()*r[i]);
            for (int j = 1; j < temp.size()-1; ++j) {
                temp[j] += r[i]*pol[j-1];
            }
            pol = temp;
        }

        int n = N;
        if (n > 1)
            cout << "x^" << n << " ";
        else
            cout << "x" << " ";
        --n;
        char sign[2] = {'-', '+'};
        for (int i = 1; i < pol.size()-1; ++i) {
            if (pol[i] == 0) {
                --n;
                continue;
            }
            if (pol[i] == 1 || pol[i] == -1) {
                if (n == 1)
                    cout << sign[pol[i] > 0] << " " << "x ";
                else
                    cout << sign[pol[i] > 0] << " " << "x^" << n << " ";
            }
            else {
                if (n == 1)
                    cout << sign[pol[i] > 0] << " " << abs(pol[i]) << "x ";
                else
                    cout << sign[pol[i] > 0] << " " << abs(pol[i]) << "x^" << n << " ";
            }
            --n;
        }
        cout << sign[pol.back()>=0] << " " << abs(pol.back()) << " = 0" << endl;
    }

    return 0;
}
