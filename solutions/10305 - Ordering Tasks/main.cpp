#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[100];
set<int> depends_on[100];
vector<int> toposort;

void toposort_(int i) {

    visited[i] = true;

    for (auto j : depends_on[i]) {
        if (!visited[j]) toposort_(j);
    }
    toposort.push_back(i);
}

int main() {

    while (cin >> n >> m, n || m) {
        toposort.clear();

        for (int i = 0; i < n; i++) {
            depends_on[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int a1, a2;
            cin >> a1 >> a2;

            depends_on[a2 - 1].insert(a1 - 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (!visited[i]) {
                toposort_(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (i) putchar(' ');
            cout << toposort[i] + 1;
        }
        cout << endl;
    }
}