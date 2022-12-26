#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    string line;
    getline(cin, line);
    getline(cin, line);

    for (int i = 0; i < test_cases; i++) {

        vector<string> lines;

        while (getline(cin, line) && line.length()) {
            lines.push_back(line);
        }

        int n = lines.size(), m = lines.back().length();

        int t[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i][j] = lines[i][j] == '1' ? 1 : 0;
            }
        }

        int counter = -1;

        int tt[n][m];

        while(true) {

            bool find_one = false;
            for (int i = 0; i < n && !find_one; i++) {
                for (int j = 0; j < m && !find_one; j++) { 
                    if (t[i][j] == 1) find_one = true;
                }
            }

            if (!find_one) break;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    int c = 0;

                    c += (i - 1 >= 0 ? t[i - 1][j] : 0);
                    c += (i + 1 < n ? t[i + 1][j] : 0);
                    c += (j - 1 >= 0 ? t[i][j - 1] : 0);
                    c += (j + 1 < m ? t[i][j + 1] : 0);

                    tt[i][j] = c % 2;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    t[i][j] = tt[i][j];
                }
            }
            counter++;
        }
        cout << counter << endl;

    }
}