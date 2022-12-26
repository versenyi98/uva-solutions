#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<string> lines;
    string line;

    while (true) {
        bool val = (bool)getline(cin, line);
        if (!val || line.compare("%") == 0) {
            int n = lines.size();
            int m = (lines[0].length() + 1) / 2;

            char trees[n][m];
            int monkey_family[n][m];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    monkey_family[i][j] = 0;
                    trees[i][j] = lines[i][j * 2];
                }
            }
            int monkey_counter = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (monkey_family[i][j] == 0) {
                        ++monkey_counter;
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        char saved = trees[i][j];

                        while (q.size()) {
                            auto front = q.front();
                            q.pop();

                            int f = front.first;
                            int s = front.second;

                            if (f < 0 || f >= n || s < 0 || s >= m || monkey_family[f][s] != 0 || trees[f][s] != saved) continue;
                            monkey_family[f][s] = monkey_counter;

                            q.push({f + 1, s + 1});
                            q.push({f + 1, s + 0});
                            q.push({f + 1, s - 1});
                            q.push({f + 0, s + 1});
                            q.push({f + 0, s - 1});
                            q.push({f - 1, s + 1});
                            q.push({f - 1, s + 0});
                            q.push({f - 1, s - 1});
                        }
                    }
                }
            }
            int maxi[m];
            for (int i = 0; i < m; i++) maxi[i] = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    maxi[i] = max(maxi[i], monkey_family[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {

                for (int j = 0; j < m; j++) {
                    if (j) putchar(' ');
                    for (int k = 0; k < (int)(log10(maxi[j]) - (int)log10(monkey_family[i][j])); k++) {
                        putchar(' ');
                    }
                    cout << monkey_family[i][j];
                }
                cout << endl;
            }
            cout << "%\n";

            lines.clear();
            if (!val) return 0;
            continue;
        }

        lines.push_back(line);
    }
}