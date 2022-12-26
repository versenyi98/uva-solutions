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
int number_of_new_rules;
int number_of_old_rules;

int which_tree_is_it[1000000];
int test_case = 0;
vector<node> edges_and_nodes;

int main() {

    while (cin >> number_of_nodes) {

        edges_and_nodes.clear();

        int current_cost = 0, best_cost = 0;

        for (int i = 0; i < number_of_nodes - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            current_cost += c;
        }

        cin >> number_of_new_rules;

        for (int i = 0; i < number_of_new_rules; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            edges_and_nodes.push_back({c, {a, b}});
        }

        cin >> number_of_old_rules;

        for (int i = 0; i < number_of_old_rules; i++) {
            int a, b, c;
            cin >> a >> b >> c;
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
            if (which_tree_is_it[edges_and_nodes[i].s.f - 1] != which_tree_is_it[edges_and_nodes[i].s.s - 1]) {
                best_cost += edges_and_nodes[i].f;

                int tree_to_overwrite = which_tree_is_it[edges_and_nodes[i].s.s - 1];

                for (int j = 0; j < number_of_nodes; j++) {
                    if (which_tree_is_it[j] == tree_to_overwrite) {
                        which_tree_is_it[j] = which_tree_is_it[edges_and_nodes[i].s.f - 1];
                    }
                }
            }
        }
        if (test_case) cout << endl;
        cout << current_cost << endl << best_cost << endl;
        test_case++;
    }
}