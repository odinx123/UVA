#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    vector<string> st;
    while (T--) {
        string ins;
        cin >> ins;
        if (ins == "Sleep") {
            string name;
            cin >> name;
            st.push_back(name);
        }
        else if (ins == "Kick") {
            if (!st.empty())
                st.pop_back();
        }
        else if (ins == "Test") {
            if (!st.empty())
                cout << st.back() << endl;
            else
                cout << "Not in a dream" << endl;
        }
    }

    return 0;
}
