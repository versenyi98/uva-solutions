#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    string endline;
    getline(cin, endline);
    getline(cin, endline);

    for (int tt = 0; tt < test_cases; tt++) {
        if (tt) cout << endl;

        vector<string> lines;
        vector<pair<int, int>> positions;   
        string line;

        while (getline(cin, line) && (line[0] == 'W' || line[0] =='L')) {
            lines.push_back(line);
        }

        int n = lines.size();
        int m = lines[0].length();
        int counter[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                counter[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lines[i][j] != '-') {
                    char save = lines[i][j];

                    queue<int> x, y;
                    queue<pair<int, int>> closed;

                    x.push(i), y.push(j);
                    int cc = 0;
                    
                    while (x.size()) {

                        int xtop = x.front(), ytop = y.front();
                        x.pop(); y.pop();

                        if (xtop < 0 || xtop >= n || ytop < 0 || ytop >= m || lines[xtop][ytop] != save) {
                            continue;
                        }

                        lines[xtop][ytop] = '-';
                        closed.push({xtop, ytop});
                        cc++;

                        x.push(xtop + 1); y.push(ytop + 1); x.push(xtop + 1); y.push(ytop); x.push(xtop + 1); y.push(ytop - 1);
                        x.push(xtop); y.push(ytop - 1); x.push(xtop); y.push(ytop + 1);
                        x.push(xtop - 1); y.push(ytop + 1); x.push(xtop - 1); y.push(ytop); x.push(xtop - 1); y.push(ytop - 1);
                    }

                    while (closed.size()) {
                        auto front = closed.front();
                        closed.pop();

                        counter[front.first][front.second] = cc;
                    }
                }
            }
        }
        do {
            int x = stoi(line.substr(0, line.find(' '))) - 1;
            int y = stoi(line.substr(line.find(' ') + 1)) - 1;

            cout << counter[x][y] << endl;
        } while (getline(cin, line) && line.length());
    }
}