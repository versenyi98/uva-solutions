#include <bits/stdc++.h>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);

    int n, m;

    while (cin >> n >> m, n || m) {

        int t[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> t[i][j];
            }
        }

        vector<int> diagonals[n + m - 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diagonals[i + j].push_back(t[i][m - 1 - j]);
            }
        }

        for (int i = 0; i < n + m - 1; i++) {
            sort(diagonals[i].begin(), diagonals[i].end());
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            int low, high, mx = 0;

            cin >> low >> high;

            for (int j = 0; j < n + m - 1; j++) {
                int val = upper_bound(diagonals[j].begin(), diagonals[j].end(), high) - lower_bound(diagonals[j].begin(), diagonals[j].end(), low);
                mx = max(mx, val);            
            }
            cout << mx << endl;
        }
        cout << "-\n";
    }
}