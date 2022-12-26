#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define f first
#define s second

int test_cases;
int n_nodes, n_edges;

vector<pii> edges[100];
priority_queue<pair<int, pii>> pq;
vector<pii> used_edges;
bool taken[100];

pii forbidden = {-1, -1};

void process(int node) {
    taken[node] = true;

    for (int i = 0; i < edges[node].size(); i++) {
        if (node == forbidden.f && edges[node][i].f == forbidden.s) continue;
        if (node == forbidden.s && edges[node][i].f == forbidden.f) continue;
        if (!taken[edges[node][i].f]) {
            pq.push({-edges[node][i].s, {node, edges[node][i].f}});
        }
    }
}

int main() {

    cin >> test_cases;
    while(test_cases--) {

        pq = priority_queue<pair<int, pii>>();
        forbidden = {-1, -1};
        used_edges.clear();
        
        cin >> n_nodes >> n_edges;

        for (int i = 0; i < n_nodes; i++) {
            edges[i].clear();
            taken[i] = false;
        }

        for (int i = 0; i < n_edges; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            edges[a - 1].push_back({b - 1, c});
            edges[b - 1].push_back({a - 1, c});
        }

        process(0);
        int worst_cost = 0;
        
        while (!pq.empty()) {
            pair<int, pii> current = pq.top();
            pq.pop();

            if (!taken[current.s.s]) {
                process(current.s.s);
                used_edges.push_back({current.s.f, current.s.s});
                worst_cost -= current.f;
            }
        }
        
        cout << worst_cost << " ";
        int second_best = 9999999;

        for (int i = 0; i < used_edges.size(); i++) {
            forbidden = used_edges[i];

            pq = priority_queue<pair<int, pii>>();
            for (int j = 0; j < n_nodes; j++) {
                taken[j] = false;
            }
            process(0);
            int worst_cost = 0; 

            while (!pq.empty()) {
                pair<int, pii> current = pq.top();
                pq.pop();

                if (!taken[current.s.s]) {
                    process(current.s.s);
                    worst_cost -= current.f;
                }
            }

            bool is_all_connected = true;
            for (int j = 0; j < n_nodes; j++) {
                is_all_connected &= taken[j];
            }

            if (is_all_connected) {
                second_best = min(second_best, worst_cost);
            }
        }
        cout << second_best << endl;
    }
}