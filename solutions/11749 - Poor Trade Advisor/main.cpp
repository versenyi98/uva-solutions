#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    while (scanf("%d %d", &n, &m), n || m) {
        int from[m], to[m];
        long cost[m];

        vector<int> road[n];
        bool visited[n];
        long maximumPPA = LONG_MIN;

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int f, t;
            long ppa;
            scanf("%d %d %ld", &f, &t, &ppa);

            from[i] = f - 1;
            to[i] = t - 1;
            cost[i] = ppa ;

            maximumPPA = max(maximumPPA, ppa);
        }

        for (int i = 0; i < m; i++) {
            if (cost[i] == maximumPPA) {
                road[from[i]].push_back(to[i]);
                road[to[i]].push_back(from[i]);
            }
        }

        int max_cities = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);

                int counter = 0;

                while (q.size()) {
                    auto front = q.front();
                    q.pop();

                    if (visited[front]) continue;
                    visited[front] = true;

                    counter++;

                    for (auto j : road[front]) {
                        if (!visited[j]) {
                            q.push(j);
                        }
                    }
                }
                max_cities = max(max_cities, counter);
            }
        }
        printf("%d\n", max_cities);
    }
}