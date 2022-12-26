#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

typedef pair<int, pair<string, string>> edge;

#define f first
#define s second

int n_nodes;
int n_edges;
int maximum_weight;

string from, to;

map<string, set<string>> nodes_in_tree;
map<string, string> which_tree;
vector<edge> edges;

int main() {

    int test_cases = 0;

    while (scanf("%d %d", &n_nodes, &n_edges), n_nodes || n_edges) {

        test_cases++;

        maximum_weight = 0;

        nodes_in_tree.clear();
        which_tree.clear();
        edges.clear();

        string x, y;
        int cost;

        for (int i = 0; i < n_edges; i++) {
            cin >> x >> y >> cost;
            
            edges.push_back({cost, {x, y}});
            
            which_tree[x] = x;
            which_tree[y] = y;

            nodes_in_tree[x].insert(x);
            nodes_in_tree[y].insert(y);
        }
        cin >> from >> to;

        sort(edges.begin(), edges.end(), [] (edge a, edge b) {
            return a.f > b.f;
        });

        for (int i = 0; i < edges.size(); i++) {
            if (which_tree[from] == which_tree[to]) break;
            if (which_tree[edges[i].s.f] == which_tree[edges[i].s.s]) continue;

            string tree_to_overwrite = which_tree[edges[i].s.s];
            maximum_weight = edges[i].f;

            for (auto j : nodes_in_tree[tree_to_overwrite]) {
                which_tree[j] = which_tree[edges[i].s.f];
                nodes_in_tree[which_tree[edges[i].s.f]].insert(j); 
            }

            nodes_in_tree[tree_to_overwrite] = {};
        }

        printf("Scenario #%d\n%d tons\n\n", test_cases, maximum_weight);
    }
}