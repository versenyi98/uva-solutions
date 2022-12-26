#include <bits/stdc++.h>
//#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int t = 0; t < n; t++) {
        cout << "Case " << t + 1 << ":\n";

        int rows;
        cin >> rows;
        string table[rows];

        for (int i = 0; i < rows; i++) {
            cin >> table[i];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                if (table[i][j] != '.') continue;
                int x[] = {i, i, i + 1, i - 1};
                int y[] = {j + 1, j - 1, j, j};
                char next = 'A';
                for (int k = 0; k < 4;) {
                    if (x[k] < 0 || x[k] == rows || y[k] < 0 || y[k] == rows) {
                        k++;
                        continue;
                    }

                    if (table[x[k]][y[k]] == next) {
                        next++;
                        k = 0;
                    } else {
                        k++;
                    }
                }
                table[i][j] = next;
            }
        }

        for (int i = 0; i < rows; i++) {
            cout << table[i] << endl;
        }
    }

    return 0;
}