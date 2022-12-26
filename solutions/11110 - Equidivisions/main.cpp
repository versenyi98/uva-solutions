#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    while (cin >> n, n) {

        int table[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                table[i][j] = n - 1;
            }
        }

        string line;
        getline(cin, line);

        for (int i = 0; i < n - 1; i++) {
            getline(cin, line);
            
            size_t pos = line.find(' ');
            while (pos = line.find(' '), pos != string::npos) {
                int x = stoi(line.substr(0, pos));
                line = line.substr(pos + 1);
                pos = line.find(' ');
                int y = stoi(line.substr(0, pos));
                line = line.substr(pos + 1);

                table[x - 1][y - 1] = i;
            }
        }

        bool wrong = false;

        for (int i = 0; i < n && !wrong; i++) {
            for (int j = 0; j < n && !wrong; j++) {
                if (table[i][j] != -1) {
                    int counter = 0;
                    int save = table[i][j];
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (q.size()) {
                        auto front = q.front();
                        q.pop();

                        int f = front.first;
                        int s = front.second;

                        if (f < 0 || f == n || s < 0 || s == n || table[f][s] != save) continue;
                        table[f][s] = -1;
                        counter++;

                        q.push({f + 1, s});
                        q.push({f, s + 1});
                        q.push({f - 1, s});
                        q.push({f, s - 1});
                    }

                    if (counter != n) {
                        wrong = true;
                    }
                }
            }
        }

        if (wrong) {
            cout << "wrong" << endl;
        } else {
            cout << "good" << endl;
        }
    }
}