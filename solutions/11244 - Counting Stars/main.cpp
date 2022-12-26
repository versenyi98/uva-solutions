#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    while (cin >> n >> m, n || m) {
        string lines[n];
        for (int i = 0; i < n; i++) {
            cin >> lines[i];
        }

        int stars = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lines[i][j] != '.') {
                    int counter = 0;
                    queue<pair<int, int>> q;

                    q.push({i, j});

                    while (q.size()) {
                        auto front = q.front();
                        q.pop();

                        int f = front.first;
                        int s = front.second;

                        if (f < 0 || f == n || s < 0 || s == m || lines[f][s] == '.') continue;
                        lines[f][s] = '.';
                        counter++;

                        q.push({f + 1, s + 1});
                        q.push({f + 1, s + 0});
                        q.push({f + 1, s - 1});
                        q.push({f + 0, s + 1});
                        q.push({f + 0, s - 1});
                        q.push({f - 1, s - 1});
                        q.push({f - 1, s + 0});
                        q.push({f - 1, s + 1});
                    }

                    if (counter == 1) {
                        stars++;
                    }
                }
            }
        }
        cout << stars << endl;
    }

    return 0;
}