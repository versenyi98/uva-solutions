#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

#define f first
#define s second

typedef pair<double, double> node;
typedef pair<double, pair<node, node>> edge;

int test_cases;
int number_of_nodes;

vector<edge> edges;
vector<node> nodes;
int which_tree[100];

double dist(node a, node b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

int main() {

    cin >> test_cases;

    for (int z = 0; z < test_cases; z++) {

        edges.clear();
        nodes.clear();

        cin >> number_of_nodes;

        double x, y;
        for (int i = 0; i < number_of_nodes; i++) {
            cin >> x >> y;
            nodes.push_back({x ,y});

            which_tree[i] = i;
        }

        for (int i = 0; i < number_of_nodes; i++) {
            for (int j = i + 1; j < number_of_nodes; j++) {
                edges.push_back({dist(nodes[i], nodes[j]), {nodes[i], nodes[j]}});
            }
        }
        sort(edges.begin(), edges.end(), [] (edge a, edge b) {
            return a.f < b.f;
        });

        double cost = 0;

        for (int i = 0; i < edges.size(); i++) {
            int a_index, b_index;

            for (int j = 0; j < nodes.size(); j++) {
                if (edges[i].s.f == nodes[j]) a_index = j;
                if (edges[i].s.s == nodes[j]) b_index = j;
            }

            if (which_tree[a_index] != which_tree[b_index]) {
                cost += edges[i].f;

                int tree_to_overwrite = which_tree[b_index];

                for (int j = 0; j < number_of_nodes; j++) {
                    if (which_tree[j] == tree_to_overwrite) {
                        which_tree[j] = which_tree[a_index];
                    }
                }
            }

        }
        if (z) cout << endl;
        printf("%.2f\n", cost);
    }
}