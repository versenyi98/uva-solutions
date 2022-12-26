#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

// Prim

// mihez mennyi
vector<pii> edges[1000005];

bool taken[1000005];
// -mennyi mihez
priority_queue<pii> pq;

void process(int node) {
    taken[node] = true;
    for (int i = 0; i < edges[node].size(); i++) {
        if (!taken[edges[node][i].first]) {
            pq.push({-edges[node][i].second, edges[node][i].first});
        }
    }
}

int main() {
    int n, m;

    while (cin >> n >> m, n) {
        for (int i = 0; i < n; i++) {
            edges[i].clear();
            taken[i] = false;
        }
    
        while (m--) {
            int i, j, cost;
            cin >> i >> j >> cost;
            edges[i].push_back({j, cost});
            edges[j].push_back({i, cost});
        }
    
        process(0);
        int worst_cost = 0;

        while (!pq.empty()) {
            pii current = pq.top();
            pq.pop();

            if (!taken[current.second]) {
                process(current.second);
                worst_cost = max(worst_cost, -current.first);
            }
        }
        
        bool all_connected = true;

        for (int i = 0; i < n; i++) {
            all_connected = all_connected && taken[i];
        }

        if (all_connected) {
            cout << worst_cost << endl;
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
} 