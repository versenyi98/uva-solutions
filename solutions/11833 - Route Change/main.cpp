#include <bits/stdc++.h>

#define f first
#define s second
#define INF 1000000000

using namespace std;

int main() {

    int cities, roads, service, repair;

    while (cin >> cities >> roads >> service >> repair, cities || roads || service || repair) {

        int dist[251];
        for (int i = 0; i <= cities; i++) dist[i] = -INF;

        int connections_cost[251][251];
        map<int, vector<int>> connectioms;

        dist[repair] = 0;

        int from, to, cost;
        for (int i = 0; i < roads; i++) {
            cin >> from >> to >> cost;

            connectioms[from].push_back(to);
            connectioms[to].push_back(from);

            connections_cost[from][to] = cost;
            connections_cost[to][from] = cost;
        }

        priority_queue<pair<int, int>> pq;
        pq.push({0, repair});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (top.s < service) {
                int current_cost = top.f;
                for (int i = top.s; i <= service - 2; i++) {
                    current_cost -= connections_cost[i][i + 1];
                }
                if (dist[service - 1] < current_cost) dist[service - 1] = current_cost;
            } else {
                for (auto i : connectioms[top.s]) {
                    if (dist[i] < top.f - connections_cost[top.s][i]) {
                        dist[i] = top.f - connections_cost[top.s][i];

                        pq.push({dist[i], i});
                    }
                }
            }  

        }
        cout << -dist[service - 1] << endl;
    }
}