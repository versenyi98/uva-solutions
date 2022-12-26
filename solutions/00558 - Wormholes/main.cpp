#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    int n, m;
    cin >> tc;
    while (cin >> n >> m) {

        map<int, vector<pair<int, int>>> conn;
        vector<int> distance;
        vector<int> reachable;
        queue<int> q;
        map<int, bool> taken;

        int from, to, dist;
        for (int i = 0; i < m; i++) {
            cin >> from >> to >> dist;
            conn[from].push_back({to, dist});
        }

        q.push(0);
        while (q.size()) {
            auto top = q.front();
            q.pop();

            reachable.push_back(top);
            
            for (auto i : conn[top]) {
                if (!taken[i.first]) {
                    taken[i.first] = true;
                    q.push(i.first);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            distance.push_back(1000000000);
        }

        distance[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                for (auto k : conn[j]) {
                    if (distance[k.first] > distance[j] + k.second) {
                        distance[k.first] = distance[j] + k.second;
                    }
                }
            }
        }

        bool possible = false;
        for (int j = 0; j < n; j++) {
            for (auto k : conn[j]) {
                if (distance[k.first] > distance[j] + k.second) {
                    distance[k.first] = distance[j] + k.second;
                    if (find(reachable.begin(), reachable.end(), k.first) != reachable.end()) {
                        possible = true;
                        break;
                    }
                }
            }
            if (possible) {
                break;
            }
        }
        cout << (possible ? "possible" : "not possible")<< endl;
    }
}