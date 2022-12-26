#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int tt = 0; tt < tc; tt++) {
        int n;
        cin >> n;

        int t[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%1d", &t[i][j]);
            }
        }

        int operations;
        cin >> operations;

        int diff = 0;

        while (operations--) {
            string line;
            cin >> line;

            if (line == "inc") {
                diff++;
                continue;
            }

            if (line == "dec") {
                diff--;
                continue;
            }

            if (line == "row") {
                int a, b;
                cin >> a >> b;
                a--; b--;

                for (int i = 0; i < n; i++) {
                    swap(t[a][i], t[b][i]);
                }
                continue;
            }

            if (line == "col") {
                int a, b;
                cin >> a >> b;
                a--; b--;

                for (int i = 0; i < n; i++) {
                    swap(t[i][a], t[i][b]);
                }
                continue;
            }

            if (line == "transpose") {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= i; j++) {
                        swap(t[i][j], t[j][i]);
                    }
                }
            }
        }

        cout << "Case #" << tt + 1 << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ((t[i][j] + diff) % 10 + 10) % 10;
            }
            cout << endl;
        }
        cout << endl;
    }
}