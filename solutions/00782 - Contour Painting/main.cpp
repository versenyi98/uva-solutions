#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    string line;

    cin >> test_cases;
    cin.ignore(100, '\n');

    for (int tt = 0; tt < test_cases; tt++) {
        vector<string> lines;
        queue<pair<int, int>> q;
        pair<int, int> star;
        int i = 0;

        while (getline(cin, line) && line[0] != '_') {
            lines.push_back(line);
            if (lines[i].find('*') != string::npos) {
                star.first = i;
                star.second = lines[i].find('*');
            }
            i++;
        }

        q.push(star);
        lines[star.first][star.second] = ' ';
        for (int i = 0; i < lines.size(); i++) {
            lines[i] = lines[i] + string(100 - lines[i].length(), ' ');
        }

        while (q.size()) {
            auto front = q.front(); 
            q.pop();

            int f = front.first;
            int s = front.second;

            if (f < 0 || f >= lines.size() || s < 0 || s >= 100 || lines[f][s] != ' ') continue;

            int x[] = {-1, +1, 0, 0};
            int y[] = {0, 0, +1, -1};

            bool border = false;

            for (int i = 0; i < 4; i++) {
                int ff = f + x[i];
                int ss = s + y[i];
                if (ff < 0 || ff >= lines.size() || ss < 0 || ss >= 100 || lines[ff][ss] == '.') continue;
                if (lines[ff][ss] == 'X') border = true;
                q.push({ff, ss});
            }

            if (border) {
                lines[f][s] = '#';
            } else {
                lines[f][s] = '.';
            }
        }

        for (int i = 0; i < lines.size(); i++) {
            replace(lines[i].begin(), lines[i].end(), '.', ' ');
            int last_of_us = max((int)lines[i].find_last_of('#'), (int)lines[i].find_last_of('X'));
            cout << lines[i].substr(0, last_of_us + 1) << endl;
        }
        cout << line << endl;
    }
}