#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    int tc = 0;
    while (cin >> n >> m, n || m) {
        tc++;
        string lines[m];
        for (int i = 0; i < m; i++) {
            cin >> lines[i];
        }

        vector<int> throws_;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (lines[i][j] != '.') {
                    int counter = 0;

                    queue<pair<int, int>> star_queue;
                    star_queue.push({i, j});

                    while (star_queue.size()) {
                        auto front = star_queue.front();
                        star_queue.pop();

                        int f = front.first;
                        int s = front.second;

                        if (f < 0 || f >= m || s < 0 || s >= n || lines[f][s] == '.') continue;

                        if (lines[f][s] == 'X') {
                            counter++;
                            queue<pair<int, int>> X_queue;
                            X_queue.push({f, s});

                            while (X_queue.size()) {
                                auto ffront = X_queue.front();
                                X_queue.pop();

                                int ff = ffront.first;
                                int ss = ffront.second;

                                if (ff < 0 || ff >= m || ss < 0 || ss >= n || lines[ff][ss] != 'X') {
                                    continue;
                                }

                                lines[ff][ss] = '*';

                                X_queue.push({ff, ss + 1});
                                X_queue.push({ff, ss - 1});
                                X_queue.push({ff - 1, ss});
                                X_queue.push({ff + 1, ss});
                            }
                        }

                        lines[f][s] = '.';

                        star_queue.push({f, s + 1});
                        star_queue.push({f, s - 1});
                        star_queue.push({f - 1, s});
                        star_queue.push({f + 1, s});
                    }

                    throws_.push_back(counter);
                }
            }
        }

        sort(throws_.begin(), throws_.end());
        cout << "Throw " << tc << endl;
        for (int i = 0; i < throws_.size(); i++ ) {
            if (i) cout << ' ';
            cout << throws_[i];
        }
        cout << endl << endl;
    }
}