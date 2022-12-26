#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, pair<string, string> > edge;

#define f first
#define s second

int number_of_nodes;
int number_of_paths;

string nodes[400];
vector<edge> edges;

map<string, string> which_tree;

int main() {

    while (cin >> number_of_nodes >> number_of_paths, number_of_paths != 0 || number_of_nodes != 0) {

        edges.clear();
        which_tree.clear();

        for (int i = 0; i < number_of_nodes; i++) {
            cin >> nodes[i];
            //cout << nodes[i] << endl;
            which_tree[nodes[i]] = nodes[i];
        }

        for (int i = 0; i < number_of_paths; i++) {
            edges.push_back({1, {"", ""}});
            cin >> edges[i].s.f >> edges[i].s.s >> edges[i].f;
        }

        string Peter;
        cin >> Peter;

        sort(edges.begin(), edges.end(), [] (edge a, edge b) {
            return a.f < b.f;
        });

        int best_cost = 0;
        for (int i = 0; i < number_of_paths; i++) {
            //cout << edges[i].f << " " << edges[i].s.f << "  "<< edges[i].s.s << endl;
            if (which_tree[edges[i].s.f] != which_tree[edges[i].s.s]) {
                best_cost += edges[i].f;

                string tree_to_owerwrite = which_tree[edges[i].s.s];

                for (auto j : which_tree) {
                    if (j.s == tree_to_owerwrite) {
                        which_tree[j.f] = which_tree[edges[i].s.f];
                    }
                }
            }
        }

        bool possible = true;

        for (int i = 0; i < number_of_nodes - 1 && possible; i++) {
            possible = which_tree[nodes[i]] == which_tree[nodes[i + 1]];
        }

        if (possible) {
            cout << best_cost << endl;
        } else {
            cout << "Impossible" << endl;
        }

    }
}