#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define node pair<int, pii>
#define s second
#define f first

int number_of_nodes;
int number_of_rules;

int which_tree_is_it[200000];
int test_case = 0;
vector<node> edges_and_nodes;

int main() {

    while (cin >> number_of_nodes >> number_of_rules, number_of_nodes != 0 && number_of_rules != 0) {

        edges_and_nodes.clear();

        int all_cost = 0, best_cost = 0;

        for (int i = 0; i < number_of_rules; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            all_cost += c;

            edges_and_nodes.push_back({c, {a, b}});
        }

        sort(edges_and_nodes.begin(), edges_and_nodes.end(), [] (node a, node b) {
            return a.first < b.first;
        });

        for (int i = 0; i < number_of_nodes; i++) {
            which_tree_is_it[i] = i;
        }

/*
        for (auto i : edges_and_nodes) {
            cout << i.first << " " << i.second.first << " " << i.second.second << endl;
        }
*/

        for (int i = 0; i < edges_and_nodes.size(); i++) {
            if (which_tree_is_it[edges_and_nodes[i].s.f] != which_tree_is_it[edges_and_nodes[i].s.s]) {
                best_cost += edges_and_nodes[i].f;

                int tree_to_overwrite = which_tree_is_it[edges_and_nodes[i].s.s];

                for (int j = 0; j < number_of_nodes; j++) {
                    if (which_tree_is_it[j] == tree_to_overwrite) {
                        which_tree_is_it[j] = which_tree_is_it[edges_and_nodes[i].s.f];
                    }
                }
            }
        }
        cout << all_cost - best_cost << endl;
    }
}