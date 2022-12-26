#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    int tt = 0;
    while (cin >> n >> m, n || m) {
        string lines[n];
        for (int i = 0; i < n; i++) {
            cin >> lines[i];
        }
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lines[i][j] != '.') {
                    int counter = 0;
                    char origin = lines[i][j];

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (q.size()) {
                        auto top = q.front();
                        q.pop();

                        int f = top.first;
                        int s = top.second;

                        if (f < 0 || f >= n || s < 0 || s >= m || lines[f][s] != origin) continue;
                        counter++;
                        lines[f][s] = '.';

                        q.push({f + 1, s});
                        q.push({f, s + 1});
                        q.push({f, s - 1});
                        q.push({f - 1, s});
                    }

                    pq.push({counter, -1 * origin});
                }
            }
        }

        cout << "Problem " << ++tt << ":" << endl;
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();

            cout << char(-1 * top.second) << ' ' << top.first << endl;
        }
    }
}