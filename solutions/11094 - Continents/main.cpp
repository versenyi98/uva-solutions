#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, M;

    while (cin >> N >> M) {
        char lland, uland, lwater, uwater;
        vector<string> lines;
        int x, y;
        int mm = 0;

        for (int i = 0; i < N; i++) {
            string line;
            cin >> line;
            lines.push_back(line);
        }

        cin >> x >> y;
        lland = lines[x][y];
        lwater = lland;

        for (int i = 0; lland == lwater && i < N; i++) {
            for (int j = 0; lwater == lland && j < M; j++) {
                lwater = lines[i][j];
            }
        }
        if (lland == lwater) lwater = lland + 1;
        lwater = tolower(lwater);
        uwater = toupper(lwater);

        queue<pair<int, int>> q;
        
        q.push({x, y});

        while (q.size()) {
            auto front = q.front();

            q.pop();
            
            int f = front.first;
            int s = front.second;
            if (f < 0 || f >= N || lines[f][s] != lland) continue;

            lines[f][s] = lwater;

            q.push({f + 1, s});
            q.push({f, (s + 1) % M});
            q.push({f, (M + s - 1) % M});
            q.push({f - 1, s});
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (lines[i][j] == lland) {
                    
                    int counter = 0;
                    queue<pair<int, int>> qq;
                    qq.push({i, j});

                    while (qq.size()) {
                        auto front = qq.front();
                        qq.pop();

                        int f = front.first;
                        int s = front.second;

                        if (f < 0 || f >= N || lines[f][s] != lland) continue;
                        counter++;

                        lines[f][s] = lwater;

                        qq.push({f + 1, s});
                        qq.push({f, (s + 1) % M});
                        qq.push({f, (M + s - 1) % M});
                        qq.push({f - 1, s});
                    }
                    mm = max(mm, counter);
                }
            }
        }

        cout << mm << endl;
    }
}