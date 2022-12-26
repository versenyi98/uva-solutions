#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

double dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

int main() {

    int ROWS, COLUMNS;
    int tc = 0;
    while (cin >> ROWS >> COLUMNS, ROWS || COLUMNS) {
        int forbid;
        cin >> forbid;

        //if (++tc == 6) cout << ROWS << " " << COLUMNS << endl;

        map<pair<int, int>, bool> taken;
        priority_queue<pair<int, pair<pair<int, int>, int>>> q;
        for (int i = 0; i < forbid; i++) {
            int x, y;
            cin >> x >> y;

            taken[{x, y}] = true;
        }

        int jiggle;
        vector<pair<pair<int, int>, int>> jigglypuff;
        cin >> jiggle;

        for (int i = 0; i < jiggle; i++) {
            int x, y, power;
            cin >> x >> y >> power;
            jigglypuff.push_back({{x, y}, power});

            map<pair<int, int>, bool> taken_j;
            queue<pair<int, int>> q_j;

            q_j.push({x, y});

            while (!q_j.empty()) {
                auto top = q_j.front();
                q_j.pop();

                int xd[] = {1, -1, 0, 0};
                int yd[] = {0, 0, 1, -1};

                for (int j = 0; j < 4; j++) {
                    if (!taken_j[{top.f + xd[j], top.s + yd[j]}] && dist({top.f + xd[j], top.s + yd[j]}, {x, y}) <= power) {
                        q_j.push({top.f + xd[j], top.s + yd[j]});
                        taken_j[{top.f + xd[j], top.s + yd[j]}] = true;
                        taken[{top.f + xd[j], top.s + yd[j]}] = true;
                    }
                }
            }
        }

        for (int i = 1; i <= ROWS; i++) {
            taken[{i, 0}] = true;
            taken[{i, COLUMNS + 1}] = true;
        }
        for (int i = 1; i <= COLUMNS; i++) {
            taken[{0, i}] = true;
            taken[{ROWS + 1, i}] = true;
        }
/*
        for (int i = 1; i <= ROWS; i++) {
            for (int j = 1; j <= COLUMNS; j++) {
                cout << taken[{i, j}];
            }
            cout << endl;
        }
*/
        q.push({0, {{1, 1}, 0}});

        while (!q.empty() && q.top().s.f != make_pair(ROWS, COLUMNS)) {
            auto top = q.top();
            q.pop();

            if (taken[top.s.f]) continue;
            taken[top.s.f] = true;

            int x[] = {+1, -1, 0, 0};
            int y[] = {0, 0, +1, -1};

            for (int i = 0; i < 4; i++) {
                if (!taken[{top.s.f.f + x[i], top.s.f.s + y[i]}]) {
                    q.push({-(ROWS - top.s.f.f - x[i] + COLUMNS - top.s.f.s - y[i] + top.s.s + 1), {{top.s.f.f + x[i], top.s.f.s + y[i]}, top.s.s + 1}});
                }
            }   
        }

        if (q.empty()) {
            cout << "Impossible.\n";
        } else {
            cout << q.top().s.s << endl;
        }
    }
}