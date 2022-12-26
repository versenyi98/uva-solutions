#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int main() {

    int n;
    int tc = 0;
    while (cin >> n && n != -1) {
        string line;
        getline(cin, line);
        tc++;
        int cost[101];
        int distance[101];
        bool taken[101];
        vector<int> connections[101];

        for (int i = 1; i <= n; i++) {
            distance[i] = -1000000000;
            cin >> cost[i];
            taken[i] = false;
            int num;
            cin >> num;

            for (int j = 0; j < num; j++) {
                int dest;
                cin >> dest;
                connections[i].push_back(dest);
            }
        }

        distance[1] = 100;
        for (int i = 0; i <= 100 && distance[n] < 0; i++) {
            for (int j = 1; j <= n; j++) {
                if (distance[j] <= 0) continue;
                for (auto k : connections[j]) {
                    if (distance[k] < distance[j] + cost[k]) {
                        distance[k] = distance[j] + cost[k];
                    }
                }
            }
        }

        queue<int> q;

        for (int j = 1; j <= n; j++) {
            if (distance[j] <= 0) continue;
            for (auto k : connections[j]) {
                if (distance[k] < distance[j] + cost[k]) {
                    q.push(k);
                }
            }
        }
        bool solve = false;
        while (q.size()) {
            auto top = q.front();
            q.pop();

            solve = solve || (top == n);

            for (auto i : connections[top]) {
                if (!taken[i]) {
                    taken[i] = true;
                    q.push(i);
                }
            }
        }
        
        if (solve || distance[n] > 0) {
            cout << "winnable\n";
        } else {
            cout << "hopeless\n";
        }
    }

    return 0;
}