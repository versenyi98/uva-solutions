#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

#define f first
#define s second

typedef pair<int, pair<int, int>> edge;

int n_nodes, n_edges;
int n_nodes_in_tree;

vector<edge> edges;
vector<int> circles;

int which_tree[1000];
map<int, vector<int>> elements_of_tree;

int main() {

    while (scanf("%d %d", &n_nodes, &n_edges), n_edges != 0 || n_nodes != 0) {

        n_nodes_in_tree = 0;
        elements_of_tree.clear();
        edges.clear();
        circles.clear();

        for (int i = 0; i < n_nodes; i++) {
            which_tree[i] = i;
            elements_of_tree[i].push_back(i);
        }

        int x, y, c;

        for (int i = 0; i < n_edges; i++) {
            scanf("%d %d %d", &x, &y, &c);
            edges.push_back({c, {x, y}});
        }

        sort(edges.begin(), edges.end(), [] (edge a, edge b) {
            return a.f < b.f;
        });

        int i;
        for (i = 0; i < n_edges; i++) {
            if (n_nodes_in_tree == n_nodes) break;
            if (which_tree[edges[i].s.f] == which_tree[edges[i].s.s]) {
                circles.push_back(edges[i].f);
                continue;
            }

            int tree_to_overwrite = which_tree[edges[i].s.s];

            for (auto j : elements_of_tree[tree_to_overwrite]) {
                elements_of_tree[which_tree[edges[i].s.f]].push_back(j);
                which_tree[j] = which_tree[edges[i].s.f];
            }

            elements_of_tree[tree_to_overwrite] = {};

            n_nodes_in_tree = max(n_nodes_in_tree, (int)elements_of_tree[which_tree[edges[i].s.f]].size());
        }

        if (i == n_edges && circles.empty()) {
            printf("forest\n");
        } else {
            bool space = false;

            for (int j = 0; j < circles.size(); j++) {
                if (space) printf(" ");
                if (!j) space = true;
                printf("%d", circles[j]);
            }

            for (int j = 0; j < n_edges - i; j++) {
                if (space) printf(" ");
                if (!j) space = true;
                printf("%d", edges[i + j].f);
            }
            printf("\n");
        }
    }
}