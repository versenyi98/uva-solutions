#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define INF 1000000000

struct node {
    int cost;
    int city;
    vector<pair<pair<int, int>, int>> route;

    bool operator< (const node n) const {
        return cost < n.cost;
    }
};

int main() {

    int nodes, routes;
    int S, D;
    while (cin >> nodes >> routes, nodes || routes) {
        cin >> S >> D;

        int from, to, cost;
        
        map<int, vector<pair<int, int>>> connections;
        map<int, bool> taken;
        map<pair<pair<int, int>, int>, bool> shortest;
        map<int, int> dist;

        for (int i = 0; i < routes; i++) {
            cin >> from >> to >> cost;
            connections[from].push_back({to, cost});
        }

        for (int i = 0; i < nodes; i++) {
            dist[i] = -INF;
        }
        dist[S] = 0;

        priority_queue<node> pq;
        node nd;

        nd.city = S;
        nd.cost = 0;
        nd.route = {};

        pq.push(nd);

        while (!pq.empty()) {

            node top = pq.top();
            pq.pop();

            if (taken[top.city]) continue;
            taken[top.city] = true;

            if (top.city == D) {
                for (int i = 0; i < top.route.size(); i++) {
                    shortest[top.route[i]] = true;
                }

                while (!pq.empty() && pq.top().cost == top.cost) {
                    if (pq.top().city == D) {
                        for (int i = 0; i < pq.top().route.size(); i++) {
                            shortest[pq.top().route[i]] = true;
                        }
                    }
                    pq.pop();
                }
                break;
            }

            for (auto i : connections[top.city]) {
                if (taken[i.f]) continue;
                node nxt = top;

                nxt.city = i.f;
                nxt.cost -= i.s;
                nxt.route.push_back({{top.city, i.f}, i.s});

                pq.push(nxt);
            }
        }

        priority_queue<pair<int, int>> pq2;
        pq2.push({0, S});

        while (!pq2.empty()) {
            auto top = pq2.top();
            pq2.pop();

            for (auto i : connections[top.s]) {
                if (shortest[{{top.s, i.f}, i.s}]) continue;
                if (dist[i.f] < top.f - i.s) {
                    dist[i.f] = top.f - i.s;
                    pq2.push({dist[i.f], i.f});
                }
            }
        }

        if (dist[D] == -INF) {
            cout << "-1" << endl;
        } else {
            cout << -dist[D] << endl;
        }
    }
} 