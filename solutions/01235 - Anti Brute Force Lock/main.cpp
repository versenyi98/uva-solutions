#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define node pair<int, pii>
#define f first
#define s second

int test_cases;

vector<node> edges_nodes;
int passwords[500];
map<int, int> which_tree;

int count_cost(int a, int b) {

    int cost = 0;

    int c = a / 1000, d = b / 1000;
    if (c > d) {
        cost += min(c - d, 10 + d - c);
    } else {
        cost += min(d - c, 10 + c - d);
    }

    c = (a % 1000) / 100, d = (b % 1000) / 100;
    if (c > d) {
        cost += min(c - d, 10 + d - c);
    } else {
        cost += min(d - c, 10 + c - d);
    }

    c = (a % 100) / 10, d = (b % 100) / 10;
    if (c > d) {
        cost += min(c - d, 10 + d - c);
    } else {
        cost += min(d - c, 10 + c - d);
    }

    c = (a % 10), d = (b % 10);
    if (c > d) {
        cost += min(c - d, 10 + d - c);
    } else {
        cost += min(d - c, 10 + c - d);
    }

    return cost;
}

int main() {

    cin >> test_cases;

    while (test_cases--) {

        int pw;

        int start_cost = 999;
        cin >> pw;

        edges_nodes.clear();
        which_tree.clear();

        for (int i = 0; i < pw; i++) {
            int temp;
            int current_cost = 0;
            int current_pw = 0;

            for (int j = 0; j < 4; j++) {
                scanf("%1d", &temp);

                current_pw = current_pw * 10 + temp;
                current_cost = current_cost + min(temp, 10 - temp);
            }

            passwords[i] = current_pw;
            which_tree[current_pw] = current_pw;

            start_cost = min(start_cost, current_cost);
        }

        for (int i = 0; i < pw; i++) {
            for (int j = i + 1; j < pw; j++) {
                edges_nodes.push_back({count_cost(passwords[i], passwords[j]), {passwords[i], passwords[j]}});
            }
        }

        sort(edges_nodes.begin(), edges_nodes.end(), [] (node a, node b) {
            return a.f < b.f;
        });

        for (int i = 0; i < edges_nodes.size(); i++) {
            if (which_tree[edges_nodes[i].s.f] != which_tree[edges_nodes[i].s.s]) {
                int tree_to_overwrite = which_tree[edges_nodes[i].s.s];

                start_cost += edges_nodes[i].f;

                for (auto j : which_tree) {
                    if (j.second == tree_to_overwrite) {
                        which_tree[j.first] = which_tree[edges_nodes[i].s.f];
                    }
                }
            }
        }

        cout << start_cost << endl;

    }
}