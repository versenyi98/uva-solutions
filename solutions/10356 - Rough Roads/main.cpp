#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define INF 1000000000

int main() {

    int junctions, roads;
    int test_case = 0;

    while (scanf("%d %d", &junctions, &roads) == 2) {

        int from, to, len;
        map<int, vector<pair<int, int>>> connections;
        //       bool true = on back, false = riding
        map<pair<int, bool>, int> dist;

        for (int i = 1; i < junctions; i++) {
            dist[{i, false}] = -INF;
            dist[{i, true}] = -INF;
        }

        for (int i = 0; i < roads; i++) {
            scanf("%d %d %d", &from, &to, &len);

            connections[from].push_back({to, len});
            connections[to].push_back({from, len});
        }
        
        dist[{0, false}] = 0;
        dist[{0, true}] = -INF;

        priority_queue<pair<pair<int, bool>, int>> pq;

        pq.push({{0, false}, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            //cout << top.f.f << " " << top.f.s << " " << top.s << endl;
            for (auto i : connections[top.s]) {
                if (dist[{i.f, !top.f.s}] < top.f.f - i.s) {
                    dist[{i.f, !top.f.s}] = top.f.f - i.s;
                    pq.push({{dist[{i.f, !top.f.s}], !top.f.s}, i.f});
                }
            }
        }

        printf("Set #%d\n", ++test_case);
        if (dist[{junctions - 1, false}] == -INF) {
            printf("?\n");
        } else {
            printf("%d\n", -dist[{junctions - 1, false}]);
        }
    }
}