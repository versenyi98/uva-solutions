#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <stdio.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> edge;

int denials = 0;

vector<edge> edges;
int which_tree[100001];
map<int, set<int>> nodes_in_tree;


int main() {

    int a, b;

    while (scanf("%d", &a) == 1) {
        
        if (a == -1) {
            for (int i = 0; i < edges.size(); i++) {
                if (which_tree[edges[i].f] == which_tree[edges[i].s]) {
                    denials++;
                    continue;
                }
                
                int tree_to_overwrite = which_tree[edges[i].s];

                for (auto j : nodes_in_tree[tree_to_overwrite]) {
                    which_tree[j] = which_tree[edges[i].f];
                    nodes_in_tree[which_tree[edges[i].f]].insert(j);
                }

                nodes_in_tree[tree_to_overwrite] = {};
            }

            printf("%d\n", denials);
            edges.clear();
            nodes_in_tree.clear();
            denials = 0;
            continue;
        }

        scanf("%d", &b);

        edges.push_back({a, b});
        which_tree[a] = a;
        which_tree[b] = b;

        nodes_in_tree[a].insert(a);
        nodes_in_tree[b].insert(b);
    }   
}