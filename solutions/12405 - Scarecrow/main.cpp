#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);

    for (int tt = 0; tt < tc; tt++) {
        int len;
        cin >> len;

        char ch;
        bool needed = false;
        bool placed = false;
        int cc = 0;
        for (int i = 0; i < len; i++) {
            cin >> ch;
            if (needed) {
                placed = true;
                needed = false;
                cc++;
            } else if (placed) {
                placed = false;
            } else if (ch == '.') {
                needed = true;
            }
        }
        if (needed) cc++;
        cout << "Case " << tt+1 << ": " << cc << endl;
    }
}