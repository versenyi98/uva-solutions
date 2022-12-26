#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define INF 1000000000

struct state {

    int cost;
    int fuel;
    int city;

    bool operator< (const state s) const {
        return cost < s.cost;
    }

};

int main() {

    int n, m;
    int fuel_cost[1001];
    
    map<int, vector<int>> connections;
    int connections_cost[1001][1001];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &fuel_cost[i]);
    }
    int from, to, cost;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &cost);

        connections[from].push_back(to);
        connections[to].push_back(from);

        connections_cost[from][to] = cost;
        connections_cost[to][from] = cost;
    }
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int capacity, start, destination;
        int dist[1001][101];
        
        scanf("%d %d %d", &capacity, &start, &destination);
    
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= capacity; k++) {
                dist[j][k] = -INF;
            }
        }
    
        dist[start][0] = 0;

        priority_queue<state> pq;

        state st;
        st.cost = 0;
        st.fuel = 0;
        st.city = start;

        pq.push(st);

        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();

            for (auto j : connections[top.city]) {
                if (connections_cost[top.city][j] > top.fuel) continue;

                state st;
                st.city = j;
                st.fuel = top.fuel - connections_cost[top.city][j];
                st.cost = top.cost;

                if (dist[st.city][st.fuel] < st.cost) {
                    dist[st.city][st.fuel] = st.cost;
                    pq.push(st);
                }
            }

            if (dist[top.city][top.fuel + 1] < top.cost - fuel_cost[top.city]) {
                if (top.fuel + 1 > capacity) continue;
                dist[top.city][top.fuel + 1] = top.cost - fuel_cost[top.city];

                state st;
                st.city = top.city;
                st.fuel = top.fuel + 1;
                st.cost = top.cost - fuel_cost[top.city];
                pq.push(st);
            }
            

            

        }
        if (dist[destination][0] == -INF) {
            cout << "impossible\n";
            continue;
        }
        cout << -dist[destination][0] << endl;
    }



}