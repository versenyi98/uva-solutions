#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define pss pair<string, string>
#define node pair<int, pss>
#define f first
#define s second

map<string, string> which_tree;
int test_cases;
int cities;
int lines;

vector<node> nodes;

int main() {

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {

        cin >> cities;
        cin >> lines;

        nodes.clear();
        which_tree.clear();

        string a, b;
        int cost;

        for (int j = 0; j < lines; j++) {
            cin >> a >> b >> cost;

            which_tree[a] = a;
            which_tree[b] = b;

            nodes.push_back({cost, {a, b}});
        }

        sort(nodes.begin(), nodes.end(), [] (node a, node b) {
            return a.f < b.f;
        });

        int best_cost = 0;
        for (int j = 0; j < nodes.size(); j++) {
            if (which_tree[nodes[j].s.f] == which_tree[nodes[j].s.s]) continue;
            best_cost += nodes[j].f;

            string tree_overwrite = which_tree[nodes[j].s.s];

            for (auto k : which_tree) {
                if (k.second == tree_overwrite) {
                    which_tree[k.first] = which_tree[nodes[j].s.f];
                }
            }
        }
        if (i) cout << endl;
        cout << best_cost << endl;
    }
}