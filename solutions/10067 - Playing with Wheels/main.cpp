#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int step(int a, int b, int c) {

    int next = a % (int)pow(10, c);

    next += b;
    next += (int) pow(10, c);
    next %= (int) pow(10, c);

    int ret = a / (int) pow(10, c) * pow(10, c) + next;
    return ret;
}

int main() {

    int tc;
    cin >> tc;

    while (tc--) {
        int start = 0;
        int finish = 0;
        int forbids;

        map<int, bool> taken;
        queue<pair<int, int>> q;

        for (int i = 0; i < 4; i++) {
            int x;
            cin >> x;

            start = start * 10 + x;
        }
    
        for (int i = 0; i < 4; i++) {
            int x;
            cin >> x;

            finish = finish * 10 + x;
        }

        cin >> forbids;
        for (int i = 0; i < forbids; i++) {
            int f = 0;
            for (int j = 0; j < 4; j++) {
                int x;
                cin >> x;

                f = f * 10 + x;
            }
            taken[f] = true;
        }

        q.push({start, 0});

        while (!q.empty() && q.front().f != finish) {
            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;

            int moves[] = {+1, -1, +10, -10, +100, -100, +1000, -1000};
            int powers[] = {1, 1, 2, 2, 3, 3, 4, 4};

            for (int i = 0; i < 8; i++) {
                int next = step(top.f, moves[i], powers[i]);
                if (taken[next]) continue;
                q.push({next, top.s + 1});
            }
        }

        if (q.empty()) {
            cout << -1 << endl;
        } else {
            cout << q.front().s << endl;
        }
    }
}