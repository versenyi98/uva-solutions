#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        int ans = INT_MAX;

        int diff = 0;

        while (diff < s1.length() || diff < s2.length()) {
            bool good = true;
            for (int i = 0; i < s1.length(); i++) {
                if (i + diff >= s2.length()) break;
                if (s1[i] == s2[i + diff] && s1[i] == '2') {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans = min(ans, (int)max(s1.length() + diff, s2.length()));
            }

            good = true;
            for (int i = 0; i < s2.length(); i++) {
                if (i + diff >= s1.length()) break;
                if (s2[i] == s1[i + diff] && s2[i] == '2') {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans = min(ans, (int)max(s2.length() + diff, s1.length()));
            }
            diff++;
        }
        ans = min(ans, (int)s1.length() + (int)s2.length());
        cout << ans << endl;
    }

    return 0;
}