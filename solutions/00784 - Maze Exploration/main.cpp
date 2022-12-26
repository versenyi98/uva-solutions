#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;
    string line;
    getline(cin, line);
    for (int tt = 0; tt < test_cases; tt++) {
        vector<string> lines;
        queue<pair<int, int>> q;
        while (getline(cin, line) && line[0] != '_') {
            if (line.find('*') != string::npos) {
                q.push({lines.size(), line.find('*')});
            }
            lines.push_back(line);
        }

        while (q.size()) {
            auto front = q.front();
            q.pop();

            int f = front.first;
            int s = front.second;

            if (f < 0 || f == lines.size() || s < 0 || s >= lines[f].length() || (lines[f][s] != ' ' && lines[f][s] != '*')) continue;
            lines[f][s] = '#';

            q.push({f + 1, s + 0});
            q.push({f - 1, s + 0});
            q.push({f + 0, s + 1});
            q.push({f + 0, s - 1});
        }

        for (auto i : lines) {
            cout << i << endl;
        }


        cout << line << endl;
    }



}