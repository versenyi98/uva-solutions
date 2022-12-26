#include <iostream>
#include <limits.h>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int main() {
    
    int test = 1;
    int C, E, Q;
    while (cin >> C >> E >> Q, C && E && Q) {
        vector<pair<pii, int>> answer_to_query;
        map<int, int> which_tree;
        map<int, vector<int>> elements_in_tree;
        priority_queue<pair<int, pii>> pq;

        for (int i = 0; i < C; i++) {
            which_tree[i + 1] = i + 1;
            elements_in_tree[i + 1].push_back(i + 1);
        }

        for (int i = 0; i < E; i++) {
            int x, y, c;
            cin >> x >> y >> c;

            pq.push({-c, {x, y}});
        }

        for (int i = 0; i < Q; i++) {
            int x, y;
            cin >> x >> y;

            answer_to_query.push_back({{x, y}, INT_MAX});
        }

        while (!pq.empty()) {
            pair<int, pii> current = pq.top();
            pq.pop();
            if (which_tree[current.s.f] == which_tree[current.s.s]) continue;

            int ow = which_tree[current.s.s];

            for (auto i : elements_in_tree[ow]) {
                elements_in_tree[which_tree[current.s.f]].push_back(i);
                which_tree[i] = which_tree[current.s.f];
            }

            elements_in_tree[ow] = {};

            for (int i = 0; i < answer_to_query.size(); i++) {
                if (which_tree[answer_to_query[i].f.f] == which_tree[answer_to_query[i].f.s]) {
                    answer_to_query[i].s = min(answer_to_query[i].s, -current.f);
                }
            }
        }

        if (test != 1) cout << endl;
        cout << "Case #" << test++ << endl;
        for (int i = 0; i < answer_to_query.size(); i++) {
            if (answer_to_query[i].s == INT_MAX) {
                cout << "no path\n";
            } else {
                cout << answer_to_query[i].s << endl;
            }
        }
    }
}