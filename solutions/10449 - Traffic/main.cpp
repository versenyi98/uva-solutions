#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

int pow3(int x) {
    return x * x * x;
}

int main() {

    int n;
    int tc = 0;
    while (tc++, cin >> n) {
        cout << "Set #" << tc << endl;

        int cost[201];
        int dist[201];
        vector<int> conn[201];

        for (int i = 0; i < n; i++) {
            cin >> cost[i + 1];
            dist[i + 1] = 1000000000;
        }

        int routes;
        cin >> routes;
        int from, to;
        for (int i = 0; i < routes; i++) {
            cin >> from >> to;
            conn[from].push_back(to);
        }

        dist[1] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[j] == 1000000000) continue;
                for (auto k : conn[j]) {
                    if (dist[k] > dist[j] + pow3(cost[k] - cost[j])) {
                        dist[k] = dist[j] + pow3(cost[k] - cost[j]);
                    }
                }
            }
        }
        
        queue<int> q;
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[j] == 1000000000) continue;
                for (auto k : conn[j]) {
                    if (dist[k] > dist[j] + pow3(cost[k] - cost[j])) {
                        dist[k] = dist[j] + pow3(cost[k] - cost[j]);
                        q.push(k);
                    }
                }
            }
        }
        
        while (q.size()) {
            dist[q.front()] = 0;
            q.pop();
        }

        int queries;
        cin >> queries;
        
        int temp;
        for (int i = 0; i < queries; i++) {
            cin >> temp;
            if (dist[temp] < 3 || dist[temp] == 1000000000) {
                cout << "?" << endl;
            } else {
                cout << dist[temp] << endl;
            }
        }
    }
}