#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;

    while (cin >> s >> t) {
        int idx1 = 0, idx2 = 0;

        while (idx2 != t.size() && idx1 != s.size()) {
            if (s[idx1] == t[idx2]) {
                idx1++;
            }
            idx2++;
        }
        if (idx1 == s.size()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}