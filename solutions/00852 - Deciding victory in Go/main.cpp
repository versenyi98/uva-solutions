#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int tt = 0; tt < tc; tt++) {
        string table[9];
        
        for (int i = 0; i < 9; i++) {
            cin >> table[i];
        }

        int xp = 0;
        int op = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (table[i][j] == 'X') xp++;
                if (table[i][j] == 'O') op++;
                if (table[i][j] == '.') {
                    bool has_x = false;
                    bool has_o = false;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int counter = 0;

                    while (q.size()) {
                        auto front = q.front();
                        q.pop();

                        int f = front.first;
                        int s = front.second;

                        if (f < 0 || f == 9 || s < 0 || s == 9) continue;
                        if (table[f][s] == 'X') has_x = true;
                        if (table[f][s] == 'O') has_o = true;
                        if (table[f][s] != '.') continue;

                        table[f][s] = ',';

                        counter++;

                        q.push({f + 1, s + 0});
                        q.push({f - 1, s + 0});
                        q.push({f + 0, s + 1});
                        q.push({f + 0, s - 1});

                    }

                    if (has_x && has_o) continue;
                    if (has_x) xp += counter;
                    if (has_o) op += counter;
                }
            }
        }
        cout << "Black " << xp << " White " << op << endl;
    }
}