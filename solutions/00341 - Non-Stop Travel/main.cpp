#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF -1000000000
#define f first
#define s second

typedef vector<int> utvonal;

priority_queue<pair<int, pair<int, utvonal>>> pq;
vector<int> dist(10000);
map<int, map<int, int>> weight;
int intersections;
int from, to;
int test_case = 0;

int main() {
    while (cin >> intersections, intersections) {
        int num;
        int destination, cost;
        weight.clear();
        pq = priority_queue<pair<int, pair<int, utvonal>>>();

        for (int i = 0; i < intersections; i++) {
            dist[i + 1] = INF;

            cin >> num;
            for (int j = 0; j < num; j++) {
                cin >> destination >> cost;
                weight[i + 1][destination] = cost;
            }
        }

        cin >> from >> to;
        dist[from] = 0;

        for (auto i : weight[from]) {
            if (dist[i.f] < dist[from] - weight[from][i.f]) {
                dist[i.f] = dist[from] - weight[from][i.f];
                pq.push({dist[i.f], {i.f, {from}}});
            }
        }
        pair<int, pair<int, utvonal>> solution = {INF, {to, {}}};
        while (!pq.empty() && pq.top().s.f != to) {

            auto current = pq.top();
            pq.pop();

            for (auto i : weight[current.s.f]) {
                if (dist[i.f] < current.f - weight[current.s.f][i.f]) {
                    dist[i.f] = current.f - weight[current.s.f][i.f];
                    utvonal c_utvonal = current.s.s;
                    c_utvonal.push_back(current.s.f);
                    pq.push({dist[i.f], {i.f, c_utvonal}});
                }
            } 
        }

        solution = pq.top();

        cout << "Case " << ++test_case << ": Path =";
        for (auto i : solution.s.s) {
            cout << " " << i;
        }
        cout << " " << to << "; " << -solution.f << " second delay" << endl;
    }
}