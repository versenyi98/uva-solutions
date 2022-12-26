#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define INF 1000000000

int main() {

    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        map<int, int> dist_reverse, dist_forward;
        priority_queue<pair<int, int>> pq_reverse, pq_forward;
        map<int, vector<pair<int, int>>> conn_forward, conn_reverse;
        int maximum = -INF;

        int N, M, start, terminal, p;
        cin >> N >> M >> start >> terminal >> p;

        int from, to, cost;

        for (int i = 0; i < M; i++) {
            cin >> from >> to >> cost;

            conn_reverse[to].push_back({from, cost});
            conn_forward[from].push_back({to, cost});
        }

        for (int i = 1; i <= N; i++) {
            dist_reverse[i] = -INF;
            dist_forward[i] = -INF;
        }

        dist_reverse[terminal] = 0;
        dist_forward[start] = 0;

        pq_forward.push({0, start});
        while (!pq_forward.empty()) {
            auto top = pq_forward.top();
            pq_forward.pop();

            for (auto i : conn_forward[top.s]) {
                if (dist_forward[i.f] < top.f - i.s) {
                    dist_forward[i.f] = top.f - i.s;
                    pq_forward.push({dist_forward[i.f], i.f});
                }
            }
        }
                
        pq_reverse.push({0, terminal});
        while (!pq_reverse.empty()) {
            auto top = pq_reverse.top();
            pq_reverse.pop();

            for (auto i : conn_reverse[top.s]) {
                if (dist_reverse[i.f] < top.f - i.s) {
                    dist_reverse[i.f] = top.f - i.s;
                    pq_reverse.push({dist_reverse[i.f], i.f});
                }
            }
        }

        for (auto i : conn_forward) {
            for (auto j : i.s) {
                if (-dist_forward[i.f] + j.s - dist_reverse[j.f] <= p) {
                    maximum = max(maximum, j.s);
                }
            }
        }

        if (maximum == -INF) maximum = -1;
        cout << maximum << endl;
    }
}