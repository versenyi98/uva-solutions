#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef pair<int, pair<int, int>> edge;

#define f first
#define s second

int n_nodes, n_edges, airport_cost;
int total_cost, airports;

int which_tree[10000];

int test_cases;

vector<edge> edges;
map<int, vector<int>> elements_in_tree;

int main() {

    scanf("%d", &test_cases);

    for (int tt = 0; tt < test_cases; tt++) {

        scanf("%d %d %d", &n_nodes, &n_edges, &airport_cost);

        edges.clear();
        elements_in_tree.clear();

        total_cost = 0;
        airports = 0;
        
        for (int i = 0; i < n_nodes; i++) {
            which_tree[i] = i;
            elements_in_tree[i].push_back(i);
        }

        int x, y, c;

        for (int i = 0; i < n_edges; i++) {
            scanf("%d %d %d", &x, &y, &c);
            edges.push_back({c, {x, y}});
        }

        sort (edges.begin(), edges.end(), [] (edge a, edge b) {
            return a.f < b.f;
        });

        for (int i = 0; i < n_edges; i++) {
            if (edges[i].f >= airport_cost) break;
            if (which_tree[edges[i].s.f - 1] == which_tree[edges[i].s.s - 1]) continue;

            total_cost += edges[i].f;
            int tree_to_overwrite = which_tree[edges[i].s.s - 1];

            //cout << edges[i].f << " " << edges[i].s.f << " " << edges[i].s.s << endl;
            //cout << tree_to_overwrite << endl;

            for (auto j : elements_in_tree[tree_to_overwrite]) {
                elements_in_tree[which_tree[edges[i].s.f - 1]].push_back(j);
                which_tree[j] = which_tree[edges[i].s.f - 1];
            }

            elements_in_tree[tree_to_overwrite] = {};
        }
        
        for (auto i : elements_in_tree) {
/*
            for (auto j : i.s) {
                cout << j  << " ";
            }
            cout << endl;
*/
            if (i.s.size() != 0) {
                airports++;
                total_cost += airport_cost;
            }
        }
        
        printf("Case #%d: %d %d\n", tt + 1, total_cost, airports);
    }
}