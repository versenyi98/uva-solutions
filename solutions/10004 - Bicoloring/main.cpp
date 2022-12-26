#include <bits/stdc++.h>

using namespace std;

bool good;

void bicolor(map<int, bool> &has_color, map<int, int> &color, map<int, vector<int>> &edge, int i, int color_) {

    if (has_color[i]) return;

    has_color[i] = true;
    color[i] = color_;

    for (auto node : edge[i]) {
        if (has_color[node] && color[node] == color_) {
            good = false;
            return;
        }

        if (!has_color[node]) {
            bicolor(has_color, color, edge, node, 1 - color_);
        }
    }
}

int main() {

    int n, m;

    while (cin >> n, n != 0) {
        good = true;
        map<int, bool> has_color;
        map<int, int> color;
        map<int, vector<int>> edge;

        cin >> m;

        int a, b;
        while(m--) {
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        for (int i = 0; i < n && good; i++) {
            if (!has_color[i]) {
                bicolor(has_color, color, edge, i, 0);
            }
        }

        if (good) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
}