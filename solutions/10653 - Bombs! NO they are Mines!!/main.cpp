#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int R, C;

    while (cin >> R >> C, R || C) {

        int rows;
        cin >> rows;

        pair<int, int> start, destination;
        map<pair<int, int>, bool> taken;
        priority_queue<pair<int, pair<pair<int, int>, int>>> q;

        for (int i = 0; i < R; i++) {
            taken[{i, -1}] = true;
            taken[{i, C}] = true;
        }

        for (int i = 0; i < C; i++) {
            taken[{-1, i}] = true;
            taken[{R, i}] = true;
        }

        for (int i = 0; i < rows; i++) {
            int row, pcs;
            cin >> row >> pcs;

            for (int j = 0; j < pcs; j++) {
                int temp;
                cin >> temp;
                taken[{row, temp}] = true;
            }
        }

        int x, y;
        cin >> x >> y;
        start = {x, y};
        cin >> x >> y;
        destination = {x, y};

        q.push({0, {start, 0}});

        while (!q.empty() && q.top().s.f != destination) {
            auto top = q.top();
            q.pop();

            //cout << top.f << "\t" << top.s.f.f << ":" << top.s.f.s << "\t" << top.s.s << endl;

            if (taken[top.s.f]) continue;
            taken[top.s.f] = true;

            int dx[] = {-1, +1, 0, 0};
            int dy[] = {0, 0, -1, +1};

            for (int i = 0; i < 4; i++) {
                pair<int, int> next_p = {top.s.f.f + dx[i], top.s.f.s + dy[i]};
                if (taken[next_p]) continue;
                int dist = abs(next_p.f - destination.f) + abs(next_p.s - destination.s);
                q.push({-dist - top.s.s - 1, {next_p, top.s.s + 1}});
            }
        }
        cout << q.top().s.s << endl;
    }
}