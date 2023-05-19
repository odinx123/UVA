#include <iostream>
// #include <vector>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n) {
        if (n == -1) break;

        unsigned int male = 0, female = 1;
        // 產生female個male，female留一隻，male產生male個female跟male後全死
        for (int i = 0; i < n; ++i) {
            int temp_male = male;
            male = female;
            female = 1;

            male += temp_male;
            female += temp_male;
        }

        cout << male << " " << male+female << endl;
    }

    // system("pause");
    return 0;
}
