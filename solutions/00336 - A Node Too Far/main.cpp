#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n_connections;
map<int, vector<int>> connections;
map<int, bool> touched;

int test_case = 0;
int available = 0;

priority_queue<pair<int, int>> pq;

void process(int node, int TTL) {

    touched[node] = true;

    for (auto i : connections[node]) {
        if (!touched[i]) {
            pq.push({TTL, i});
        }
    }
}

pair<int, int> current;

int main() {

    while (scanf("%d", &n_connections), n_connections) {
        int a, b;

        connections.clear();
        touched.clear();

        for (int i = 0; i < n_connections; i++) {
            cin >> a >> b;

            connections[a].push_back(b);
            connections[b].push_back(a);

            touched[a] = false;
            touched[b] = false;
        }

        int start_pos, TTL;

        while (cin >> start_pos >> TTL, start_pos || TTL) {

            pq = priority_queue<pair<int, int>>();

            test_case++;

            process(start_pos, TTL);
            touched[start_pos] = true;
            available++;

            while (!pq.empty()) {
                current = pq.top();
                pq.pop();

                if (!touched[current.second] && current.first > 0) {
                    //cout << current.second << " " << current.first << endl;
                    process(current.second, current.first - 1);
                    available++;
                }
            }
            //cout << available << endl;
            cout << "Case " << test_case << ": "
                << touched.size() - available
                << " nodes not reachable from node " << start_pos
                << " with TTL = " << TTL << ".\n";

            available = 0;
            for (auto i : touched) {
                touched[i.first] = false;
            }
        }
    }
}