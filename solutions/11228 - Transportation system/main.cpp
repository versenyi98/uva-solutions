#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;
typedef pair<double, pair<node, node>> edge;

#define f first
#define s second

int test_cases;
int cities;
int state_bound;
int state_count;

node nodes[1000];
bool in_state[1000];
int which_state[1000];

map<int, vector<node>> cities_in_state;

double dist(node a, node b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2)); 
}

int main() {

    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {

        cout << "Case #" << tt + 1 << ": ";

        cin >> cities >> state_bound;

        state_count = 0;
        cities_in_state.clear();

        for (int i = 0; i < cities; i++) {
            int x, y;
            cin >> x >> y;

            nodes[i] = {x, y};
            in_state[i] = false;
        }

        vector<node> cities_to_state;
        cities_to_state.push_back(nodes[0]);
        cities_in_state[0].push_back(nodes[0]);

        in_state[0] = true;
        which_state[0] = 0;
        int actual_index = 0;

        while (cities_to_state.size() < cities) {

            for (int i = 0; i < cities; i++) {
                if (in_state[i]) continue;

                if (dist(cities_to_state[actual_index], nodes[i]) <= state_bound) {
                    cities_in_state[state_count].push_back(nodes[i]);
                    cities_to_state.push_back(nodes[i]);

                    which_state[i] = state_count;
                    in_state[i] = true;
                }
            }
            
            actual_index++;

            if (actual_index == cities_to_state.size()) {
                state_count++;

                for (int i = 0; i < cities; i++) {
                    if (in_state[i]) continue;

                    in_state[i] = true;
                    which_state[i] = state_count;
                    cities_to_state.push_back(nodes[i]);
                    cities_in_state[state_count].push_back(nodes[i]);
                    break;
                } 
            }
        }
        cout << state_count + 1 << " ";

        double best_cost = 0;
        for (int i = 0; i <= state_count; i++) {
            map<node, node> which_tree;
            vector<edge> edges;

            for (int j = 0; j < cities_in_state[i].size(); j++) {
                
                which_tree[cities_in_state[i][j]] = cities_in_state[i][j];
                for (int k = j + 1; k < cities_in_state[i].size(); k++) {
                    edges.push_back({dist(cities_in_state[i][j], cities_in_state[i][k]), {cities_in_state[i][j], cities_in_state[i][k]}});
                }
            }

            sort(edges.begin(), edges.end(), [] (edge a, edge b) {
                return a.f < b.f;
            });

            for (int j = 0; j < edges.size(); j++) {
                if (which_tree[edges[j].s.f] != which_tree[edges[j].s.s]) {
                    best_cost += edges[j].f;

                    node tree_to_overwrite = which_tree[edges[j].s.s];
                    for (int k = 0; k < cities_in_state[i].size(); k++) {
                        if (which_tree[cities_in_state[i][k]] == tree_to_overwrite) {
                            which_tree[cities_in_state[i][k]] = which_tree[edges[j].s.f];
                        }
                    }
                }
            }
        }
        cout << round(best_cost) << " ";

        map<node, int> which_tree;
        vector<edge> edges;

        for (int i = 0; i < cities; i++) {
            which_tree[nodes[i]] = which_state[i];
        }

        for (int i = 0; i < cities; i++) {
            for (int j = i + 1; j < cities; j++) {
                if (which_state[i] != which_state[j]) {
                    edges.push_back({dist(nodes[i], nodes[j]), {nodes[i], nodes[j]}});
                }
            }
        }

        sort(edges.begin(), edges.end(), [] (edge a, edge b) {
            return a.f < b.f;
        });

        best_cost = 0;

        for (int i = 0; i < edges.size(); i++) {
            if (which_tree[edges[i].s.f] != which_tree[edges[i].s.s]) {
                best_cost += edges[i].f;

                int tree_to_overwrite = which_tree[edges[i].s.s];

                for (auto j : which_tree) {
                    if (j.s == tree_to_overwrite) {
                        which_tree[j.f] = which_tree[edges[i].s.f];
                    }
                }
            }
        }

        cout << round(best_cost) << endl;
    }


}