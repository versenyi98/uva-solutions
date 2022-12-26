#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        if (tc) cout << endl;

        int connection_num, query_num;
        cin >> connection_num >> query_num;

        map<string, vector<string>> connections;

        string from, to;
        for (int i = 0; i < connection_num; i++) {
            cin >> from >> to;

            connections[from].push_back(to);
            connections[to].push_back(from);
        }

        for (int i = 0; i < query_num; i++) {
            map<string, bool> taken;
            queue<pair<string, string>> q;

            cin >> from >> to;

            q.push({from, string(1, from[0])});

            while (!q.empty() && q.front().f != to) {
                auto top = q.front();
                q.pop();

                if (taken[top.f]) continue;
                taken[top.f] = true;

                for (auto j : connections[top.f]) {
                    if (taken[j]) continue;

                    auto v = top.s;
                    v = v + j[0];

                    q.push({j, v});
                }
            }
            cout << q.front().s << endl;
        }
    }
}