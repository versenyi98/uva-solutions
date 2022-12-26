    #include <iostream>
    #include <map>
    #include <vector>
    #include <algorithm>
    #include <cmath>
    #include <stdio.h>

    using namespace std;

    typedef pair<int, int> node;
    typedef pair<double, pair<node, node> > edge;

    #define f first
    #define s second

    double dist(node a, node b) {
        return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
    }

    node Freddy, Fiona;

    int n;
    vector<node> nodes;
    vector<edge> edges;
    map<node, node> which_tree;

    int main() {

        int test_cases = 0;
        while (cin >> n && n != 0) {
            test_cases++;

            nodes.clear();
            edges.clear();
            which_tree.clear();

            int x, y;
            cin >> x >> y;

            Freddy = {x, y};
            nodes.push_back(Freddy);

            cin >> x >> y;

            Fiona = {x, y};
            nodes.push_back(Fiona);

            for (int i = 2; i < n; i++) {
                cin >> x >> y;
                nodes.push_back({x, y});
            }

            for (int i = 0; i < nodes.size(); i++) {
                which_tree[nodes[i]] = nodes[i];
                for (int j = i + 1; j < nodes.size(); j++) {
                    edges.push_back({dist(nodes[i], nodes[j]), {nodes[i], nodes[j]}});
                }
            }

            sort(edges.begin(), edges.end(), [] (edge a, edge b) {
                return a.f < b.f;
            });


            double jumping_distance = 0;
            for (int i = 0; i < edges.size(); i++) {
                if (which_tree[Fiona] == which_tree[Freddy]) break;

                if (which_tree[edges[i].s.f] != which_tree[edges[i].s.s]) {
                    jumping_distance = edges[i].f;

                    node tree_to_overwrite = which_tree[edges[i].s.s];

                    for (auto j : which_tree) {
                        if (j.s == tree_to_overwrite) {
                            which_tree[j.f] = which_tree[edges[i].s.f];
                        }
                    }
                }
            }
            printf("Scenario #%d\nFrog Distance = %.3f\n", test_cases, jumping_distance);
            cout << endl;
        }
    }