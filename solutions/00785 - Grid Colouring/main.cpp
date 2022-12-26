#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    bool line_read = true;

    while (line_read) {
        vector<string> lines;
        while (line_read = (bool)getline(cin, line), line_read && line[0] != '_') {
            lines.push_back(line);
        }

        if (!line_read) break;
        char contour = ' ';

        for (int i = 0; i < lines.size() && contour == ' '; i++) {
            for (int j = 0; j < lines[i].length() && contour == ' '; j++) {
                contour = lines[i][j];
            }
        }

        for (int i = 0; i < lines.size(); i++) {
            for (int j = 0; j < lines[i].length(); j++) {
                if (lines[i][j] != ' ' && lines[i][j] != contour) {
                    char colour = lines[i][j];
                    lines[i][j] = ' ';

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (q.size()) {
                        auto front = q.front();
                        q.pop();

                        int f = front.first;
                        int s = front.second;

                        if (f < 0 || f >= lines.size() || s < 0 || s >= lines[f].length() || lines[f][s] != ' ') continue;

                        lines[f][s] = colour;

                        q.push({f + 1, s + 0});
                        q.push({f - 1, s + 0});
                        q.push({f + 0, s + 1});
                        q.push({f + 0, s - 1});
                    }
                }
            }
        }

        for (auto i : lines) {
            cout << i << endl;
        }

        cout << line << endl;
    }
}