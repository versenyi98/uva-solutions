#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;
    string line;
    getline(cin, line);
    getline(cin, line);

    for (int tt = 0; tt < test_cases; tt++) {
        if (tt) cout << endl;

        vector<string> lines;
        while (getline(cin, line) && line.length()) {
            lines.push_back(line);
        }

        int maximum = 0;

        for (int i = 0; i < lines.size(); i++) {
            for (int j = 0; j < lines[0].length(); j++) {
                if (lines[i][j] == '1') {
                    int counter = 0;

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (q.size()) {
                        auto fr = q.front();
                        q.pop();

                        int f = fr.first;
                        int s = fr.second;

                        if (f < 0 || f == lines.size() || s < 0 || s == lines[0].length() || lines[f][s] != '1') continue;
                        counter++;
                        lines[f][s] = '-';

                        q.push({f + 1, s});
                        q.push({f, s + 1});
                        q.push({f, s - 1});
                        q.push({f - 1, s});

                        q.push({f - 1, s - 1});
                        q.push({f - 1, s + 1});
                        q.push({f + 1, s + 1});
                        q.push({f + 1, s - 1});
                    }
                    maximum = max(maximum, counter);
                }
            }
        }
        cout << maximum << endl;
    }
}