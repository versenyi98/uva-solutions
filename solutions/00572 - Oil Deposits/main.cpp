#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    while(cin >> n >> m, n || m) {

        char arr[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        int counter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == '@') {
                    queue<pair<int, int>> q;
                    counter++;

                    q.push({i, j});

                    while (q.size()) {

                        auto front = q.front();
                        q.pop();
                        if (front.first < 0 || front.first >= n || front.second < 0 || front.second >= m || arr[front.first][front.second] != '@') continue;
                        arr[front.first][front.second] = '*';
                        int x[] = {-1, -1, -1, 0, 0, +1, +1, +1};
                        int y[] = {-1, 0, +1, -1, +1, -1, 0, +1};

                        for (int k = 0; k < 8; k++) {
                            q.push({front.first + x[k], front.second + y[k]});
                        }
                    }
                }
            }
        }

        cout << counter << endl;


    }


}