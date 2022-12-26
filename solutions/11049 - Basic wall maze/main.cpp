#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int x, y;
    while (cin >> x >> y, x || y) {
        pair<int, int> start = {x, y};
        pair<int, int> finish;

        vector<pair<pair<int, int>, pair<int, int>>> forbidden;
        map<pair<int, int>, bool> taken;
//                          heu       pos             way
        priority_queue<pair<int, pair<pair<int, int>, string>>> pq;
        for (int i = 1; i <= 6; i++) {
            taken[{i, 0}] = true;
            taken[{0, i}] = true;
            taken[{i, 7}] = true;
            taken[{7, i}] = true;
        }

        cin >> x >> y;
        finish = {x, y};

        for (int i = 0; i < 3; i++) {
            pair<int, int> from, to;

            int a, b, c, d;
            cin >> a >> b >> c >> d;

            bool horizontal = b == d;
            if (horizontal) {
                if (a < c) {
                    from = {a, b};
                    to = {c, d};
                } else {
                    to = {a, b};
                    from = {c, d};                    
                }
                for (int i = from.f + 1; i <= to.f; i++) {
                    forbidden.push_back({{i, from.s}, {i, from.s + 1}});
                    forbidden.push_back({{i, from.s + 1}, {i, from.s}});
                }
            } else {
                if (b > d) {
                    to = {a, b};
                    from = {c, d};
                } else {
                    from = {a, b};
                    to = {c, d};
                }
                for (int i = from.s + 1; i <= to.s; i++) {
                    forbidden.push_back({{from.f, i}, {from.f + 1, i}});
                    forbidden.push_back({{from.f + 1, i}, {from.f, i}});
                }
            }
        }
        pq.push({0, {start, ""}});

        while (!pq.empty() && pq.top().s.f != finish) {
            auto top = pq.top();
            pq.pop();

            if (taken[top.s.f]) continue;
            taken[top.s.f] = true;

            int x[] = {0, 0, +1, -1};
            int y[] = {-1, +1, 0, 0};
            string ss[] = {"N", "S", "E", "W"};

            for (int i = 0; i < 4; i++) {
                pair<int, int> next_pos = {top.s.f.f + x[i], top.s.f.s + y[i]};

                if (taken[next_pos]) continue;
                vector<pair<pair<int, int>, pair<int ,int>>>::iterator ff = find(forbidden.begin(), forbidden.end(), make_pair(top.s.f, next_pos));
                if ( ff != forbidden.end()) continue;

                pq.push({-(finish.f - next_pos.f + finish.s - next_pos.s + top.s.s.length() + 1), {next_pos, top.s.s + ss[i]}});
            }
        }

        if (pq.empty()) {
            cout << "Impossible" << endl;
        } else {
            cout << pq.top().s.s << endl;
        }
    }
}