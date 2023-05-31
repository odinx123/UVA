#include <iostream>
#include <vector>
using namespace std;

#define SUM(lo, up) (((lo)+(up))*(up)/2)

int main() {
    int s = 0;
    while (cin >> s && s) {
        int sum = 2;
        int r = 20000, l = 1;  // r是上底
        while (true) {
            int mid = (l+r)/2;
            sum = SUM(1, mid);
            if (sum > s && SUM(1, mid-1) <= s) {
                r = mid;
                break;
            } else if (sum > s) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        cout << sum-s << " " << r << endl;
    }

    return 0;
}
