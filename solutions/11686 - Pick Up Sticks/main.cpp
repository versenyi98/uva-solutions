#include <bits/stdc++.h>

using namespace std;

int n, m;
map<int, int> seen;
map<int, set<int>> depends_on;
vector<int> toposorted;

void toposort (int i) {

    seen[i] = 1;

    for (auto j : depends_on[i]) {
        if (seen[j] == 0) {
            toposort(j);
        } else if (seen[j] == 1) {
            return;
        }
    }

    seen[i] = 2;

    toposorted.push_back(i);
}


int main() {
    int tc = 0;
    while (scanf("%d %d", &n, &m), n || m) {

        seen.clear();
        depends_on.clear();
        toposorted.clear();

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            depends_on[b].insert(a);
        }

        for (int i = 1; i <= n; i++) {
            if (seen[i] == 0) toposort(i);
        }
        if (toposorted.size() != n) {
            printf("IMPOSSIBLE\n");
        } else {
            for (int i = 0; i < toposorted.size(); i++) {
                printf("%d\n",toposorted[i]);
            }
        }

    }
}