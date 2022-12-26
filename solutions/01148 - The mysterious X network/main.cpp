#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int main() {

    int tc = 0;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        if (i) cout << endl;

        int n;
        map<int, vector<int>> connections;
        int from, to;
        queue<pair<int, int>> q;
        map<int, bool> taken;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int act, num, temp;
            cin >> act >> num;
            taken[i] = false;

            for (int j = 0; j < num; j++) {
                cin >> temp;
                connections[act].push_back(temp);
            }
        }
        cin >> from >> to;

        q.push({from, 0});

        while (!q.empty() && q.front().f != to) {
            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;

            for (auto i : connections[top.f]) {
                if (taken[i]) continue;
                q.push({i, top.s + 1});
            }
        }
        cout << from << " " << to << " " << max(0, q.front().s - 1) << endl;
    }
}