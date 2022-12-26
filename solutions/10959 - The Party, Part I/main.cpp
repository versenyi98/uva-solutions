#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int test_case;
    cin >> test_case;

    for (int tc = 0; tc < test_case; tc++) {

        if (tc) cout << endl;

        int P, D;
        int x, y;
        map<int, vector<int>> dance;
        map<int, int> giovanni_num;
        map<int, bool> taken;
        queue<pair<int, int>> q;

        cin >> P >> D;

        for (int i = 0; i < D; i++) {
            cin >> x >> y;
            dance[x].push_back(y);
            dance[y].push_back(x);
        }

        q.push({0,0});

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;
            giovanni_num[top.f] = top.s;

            for (auto i : dance[top.f]) {
                if (taken[i]) continue;
                q.push({i, top.s + 1});
            }
        }

        for (int i = 1; i < P; i++) {
            cout << giovanni_num[i] << endl;
        }
    }
}