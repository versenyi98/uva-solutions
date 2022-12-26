#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int start, goal, n;
    int tc = 1;
    while (cin >> start >> goal >> n, start || goal || n) {

        vector<int> additions;
        map<int, bool> taken;
        queue<pair<int, int>> q;

        int a;
        while (n--) {
            cin >> a;
            additions.push_back(a);
        }

        q.push({start, 0});

        while (!q.empty() && q.front().f != goal) {
            auto top = q.front();
            q.pop();


            if (taken[top.f]) continue;
            taken[top.f] = true;

            for (auto i : additions) {
                q.push({(top.f + i) % 10000, top.s + 1});
            }
        }

        cout << "Case " << tc++ << ": ";
        if (q.empty()) {
            cout << "Permanently Locked\n";
        } else {
            cout << q.front().s << endl;
        }
    }
}