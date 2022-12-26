#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int n;
    int t = 0;

    while (cin >> n) {
        if (t) cout << endl;
        t++;
        map<string, vector<string>> connections;
        map<string, bool> touched;

        queue<pair<string, vector<string>>> q;

        string from, to;
        for (int i = 0; i < n; i++) {
            cin >> from >> to;

            connections[to].push_back(from);
            connections[from].push_back(to);
        }

        cin >> from >> to;

        q.push({from, {from}});

        while (!q.empty() && q.front().f != to) {
            auto top = q.front();
            q.pop();

            if (touched[top.f]) continue;
            touched[top.f] = true;

            for (auto i : connections[top.f]) {
                if (!touched[i]) {
                    auto v = top.s;
                    v.push_back(i);

                    q.push({i, v});
                }
            }
        }

        if (q.empty()) {
            cout << "No route" << endl; 
        } else {
            for (int i = 0; i < q.front().s.size() - 1; i++) {
                cout << q.front().s[i] << " " << q.front().s[i + 1] << endl;;
            }
        }
    }
}