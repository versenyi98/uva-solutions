#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        int n;
        cin >> n;

        string lines[n];
        for (int i = 0; i < n; i++) cin >> lines[i];
        int counter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(lines[i][j] == 'x') {
                    queue<pair<int, int>> q;
                    counter++;

                    q.push({i, j});

                    while (q.size()) {
                        auto front = q.front();
                        q.pop();

                        int f = front.first;
                        int s = front.second;

                        if (f < 0 || f == n || s < 0 || s == n || lines[f][s] == '.') continue;
                        lines[f][s] = '.';

                        q.push({f + 1, s});
                        q.push({f, s + 1});
                        q.push({f - 1, s});
                        q.push({f, s - 1});
                    }
                }
            }
        }
        cout << "Case " << tt + 1 << ": " << counter << endl;
    }

}