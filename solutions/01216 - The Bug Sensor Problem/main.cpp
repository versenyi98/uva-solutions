#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef pair<int, int> node;
typedef pair<double, pair<node, node>> edge;

#define f first
#define s second

vector<node> nodes;
priority_queue<edge> edges;

int test_cases;

map<node, vector<node>> elements_in_tree;
map<node, node> which_tree;

int receivers;

double dist(node a, node b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

int main() {

    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {

        which_tree.clear();
        elements_in_tree.clear();
        nodes.clear();
        edges = priority_queue<edge>();

        cin >> receivers;

        int x, y;

        while (cin >> x, x != -1) {
            cin >> y;

            nodes.push_back({x, y});
            which_tree[{x, y}] = {x, y};
            elements_in_tree[{x, y}].push_back({x, y});
        }

        for (int i = 0; i < nodes.size(); i++) {
            for (int j = i + 1; j < nodes.size(); j++) {
                edges.push({-dist(nodes[i], nodes[j]), {nodes[i], nodes[j]}});
            }
        }

        int used = 0;
        int best_dist = 0;

        while (used != nodes.size() - receivers && !edges.empty()) {

            edge current = edges.top();
            edges.pop();

            if (which_tree[current.s.f] != which_tree[current.s.s]) {
                used++;
                best_dist = ceil(-current.f);

                node tree_to_ow = which_tree[current.s.s];

                for (auto j : elements_in_tree[tree_to_ow]) {
                    elements_in_tree[which_tree[current.s.f]].push_back(j);
                    which_tree[j] = which_tree[current.s.f];
                }

                elements_in_tree[tree_to_ow] = {};
            }
        }

        cout << best_dist << endl;
    }

    return 0;
}