#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int x, y;
        string line;
        vector<string> lines;

        cin >> x >> y;
        getline(cin, line);
        while (getline(cin, line) && line.length()) {
            lines.push_back(line);
        }

        int n = lines.size();
        int m = lines.back().size();

        queue<pair<int, int>> q;
        q.push({x - 1, y - 1});

        int counter = 0;
        while (q.size()) {
            auto front = q.front();
            q.pop();

            int f = front.first;
            int s = front.second;

            if (f < 0 || f >= n || s < 0 || s >= m || lines[f][s] != '0') continue;

            counter++;
            lines[f][s] = '1';

            q.push({f + 1, s});
            q.push({f - 1, s});
            q.push({f, s + 1});
            q.push({f, s - 1});
        }

        if (tc) cout << endl;
        cout << counter << endl;
    }
}