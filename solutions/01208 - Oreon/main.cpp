#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define node pair<int, pii>
#define s second
#define f first

using namespace std;

int test_cases;
int cities;

vector<node> edges_nodes;
int which_tree[26];

int main() {

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        cin >> cities;

        char comma;
        int cost;

        edges_nodes.clear();

        for (int j = 0; j < cities; j++) {
            which_tree[j] = j;
            for (int k = 0; k < cities; k++) {
                cin >> cost;
                if (k != cities - 1) cin >> comma;

                if (k > j && cost != 0) {
                    edges_nodes.push_back({cost, {j, k}});
                }
            }
        }

        sort(edges_nodes.begin(), edges_nodes.end(), [] (node a, node b) {
            if (a.f == b.f) {
                if (a.s.f == b.s.f) {
                    return a.s.s < b.s.s;
                }
                return a.s.f < b.s.f;
            }
            return a.f < b.f;
        });

        cout << "Case " << i + 1 << ":" << endl;
        for (int i = 0; i < edges_nodes.size(); i++) {
            if (which_tree[edges_nodes[i].s.f] == which_tree[edges_nodes[i].s.s]) continue;

            cout << (char)('A' + edges_nodes[i].s.f) << "-" << (char)('A' + edges_nodes[i].s.s) << ' ' << edges_nodes[i].f << endl;

            int tree_to_overwrite = which_tree[edges_nodes[i].s.s];

            for (int j = 0; j < cities; j++) {
                if (which_tree[j] == tree_to_overwrite) {
                    which_tree[j] = which_tree[edges_nodes[i].s.f];
                }
            }
        }
    }
}