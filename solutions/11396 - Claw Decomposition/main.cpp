#include <bits/stdc++.h>

using namespace std;

map<int, bool> has_color;
map<int, vector<int>> edge;
map<int, int> color;
bool is_good;
int n;

void bicolor(int i, int color_) {

    if (has_color[i]) return;
    has_color[i] = true;
    color[i] = color_;

    for (auto node : edge[i]) {
        if (has_color[node] && color[node] == color_) {
            is_good = false;
            return;
        }

        if (!has_color[node]) {
            bicolor(node, 1 - color_);
        }
    }
}

int main() {

    while (cin >> n, n) {
        int from, to;
        
        has_color.clear();
        edge.clear();
        color.clear();

        is_good = true;

        while (cin >> from >> to, from || to) {
            edge[from].push_back(to);
            edge[to].push_back(from);
        }

        for (int i = 0; i < n && is_good; i++) {
            if (!has_color[i]) {
                bicolor(i, 0);
            }
        }

        if (is_good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}