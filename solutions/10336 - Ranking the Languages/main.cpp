#include <bits/stdc++.h>

using namespace std;

int main() {

    int tt;

    cin >> tt;

    for (int tc = 0; tc < tt; tc++) {

        int n, m;
        cin >> n >> m;

        char arr[n][m];
        int counter[26];
        vector<pair<int, char>> languages;
        for (int i = 0; i < 26; i++) counter[i] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != '+') {
                    char save = arr[i][j];
                    counter[arr[i][j] - 'a']++;
                    queue<pair<int, int>> q;

                    q.push({i, j});

                    while (q.size()) {
                        auto front = q.front();
                        q.pop();

                        if (front.first < 0 || front.first >= n || front.second < 0 || front.second >= m || arr[front.first][front.second] != save) continue;

                        arr[front.first][front.second] = '+';

                        q.push({front.first + 1, front.second});
                        q.push({front.first - 1, front.second});
                        q.push({front.first, front.second + 1});
                        q.push({front.first, front.second - 1});

                    }
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (counter[i] > 0) languages.push_back({counter[i], 'a' + i});
        }
        sort(languages.begin(), languages.end(), [](pair<int, char> a, pair<int, char> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });

        cout << "World #" << tc+1 << endl;
        for (auto i : languages) {
            cout << i.second << ": " << i.first << endl;
        }
    }
}