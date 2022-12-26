#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while (cin >> n, n) {
        bool good = true;
        int start_pos[n];
        for (int i = 0; i < n; i++) start_pos[i] = -1;
        for (int i = 0; i < n; i++) {
            int C, P;
            cin >> C >> P;

            if (i + P < 0 || i + P >= n || start_pos[i + P] != -1) {
                good = false;
            } else {
                start_pos[i + P] = C;
            }
        }

        if (good) {
            for (int i = 0; i < n; i++) {
                if (i) cout << ' ';
                cout << start_pos[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}