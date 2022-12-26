#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    while (cin >> n >> m, n || m) {
        string big[n];
        string small[m];

        for (int i = 0; i < n; i++) cin >> big[i];
        for (int i = 0; i < m; i++) cin >> small[i];

        vector<pair<int, int>> v;

        bool found_origin = false;
        pair<int, int> origin;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (small[i][j] == '*') {
                    if (!found_origin) {
                        found_origin = true;
                        origin = {i, j};
                    }
                    v.push_back({i - origin.first, j - origin.second});
                }
            }
        }

        int count = 0;
        bool all_good = true;

        for (int i = 0; i < n && all_good; i++) {
            for (int j = 0; j < n && all_good; j++) {
                if (big[i][j] == '*') {

                    for (auto pos : v) {
                        if (pos.first + i < 0 || pos.first + i >= n || pos.second + j < 0 || pos.second >= n || big[i + pos.first][j + pos.second] != '*') {
                            all_good = false;
                            break;
                        }  
                        big[i + pos.first][j + pos.second] = '.';
                     }

                }
            }
        }

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                all_good = all_good && big[i][j] != '*';

        cout << (all_good ? 1 : 0) << endl;
    }

    return 0;
}