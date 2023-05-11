#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int main() {
    int n;
    vector<char> prime(2002, '1');

    prime[0] = '0';
    prime[1] = '0';
    for (int i = 2; i*i <= 2001; ++i) {
        if (prime[i] == '1') {
            for (int j = i*2; j <= 2001; j+=i)
                prime[j] = '0';
        }
    }

    cin >> n;
    string s;
    for (int k = 1; k <= n; ++k) {
        cin >> s;
        int cnt[26+26+10] = {0};
        for (const auto& c : s){
            if (c >= 'a' && c <= 'z')
                ++cnt[c-'a'+10+26];
            else if (c >= 'A' && c <= 'Z')
                ++cnt[c-'A'+10];
            else
                ++cnt[c-'0'];
        }
        cout << "Case " << k << ": ";
        bool flag = false;
        for (int i = 0; i < 26+26+10; ++i) {
            if (prime[cnt[i]] == '1') {
                if (i < 10)
                    cout << static_cast<char>(i+'0');
                else if (i < 26+10)
                    cout << static_cast<char>(i+'A'-10);
                else
                    cout << static_cast<char>(i+'a'-10-26);
                flag = true;
            }
        }
        if (!flag)
            cout << "empty" << endl;
        else
            cout << endl;
    }

    // system("pause");
    return 0;
}
