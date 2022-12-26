#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c, l;
    while (cin >> n >> l >> c) {
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int chars = v[0].length();
        int lines = 0;
        int pages = 1;
        int idx = 1;

        while (idx != n) {
            if (chars + 1 + v[idx].length() > c) {
                lines++;
                chars = v[idx].length();
                if (lines == l) {
                    pages++;
                    lines = 0;
                }
            } else {
                chars += 1 + v[idx].length();
            }

            idx++;
        }
        cout << pages << endl;
    }

    return 0;
}