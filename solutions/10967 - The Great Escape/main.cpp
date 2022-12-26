#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define INF 1000000000

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {

        string maze[100];
        priority_queue<pair<int, pair<int, int>>> pq;

        map<pair<int, int>, int> rot_cost;

        int dist[100][100];
        int R, C;
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            cin >> maze[i];
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                dist[i][j] = -INF;

                if (maze[i][j] != '.' && maze[i][j] != '#') {
                    cin >> rot_cost[{i, j}];
                }
            }
        }
        dist[R - 1][0] = 0;

        int cost[3] = {2, 1, 1};

        pq.push({0, {R - 1, 0}});

        map<char, vector<pair<int, pair<int, int>>>> rot;

        int x[] = {+1, -1, 0, 0};
        int y[] = {0, 0, +1, -1};
        char m[] = {'W', 'E', 'N', 'S'};


        rot['E'] = {
            {0, {0, +1}},
            {2, {0, -1}},
            {1, {+1, 0}},
            {1, {-1, 0}}
        }; 
        rot['N'] = {
            {1, {0, +1}},
            {1, {0, -1}},
            {2, {+1, 0}},
            {0, {-1, 0}}
        }; 
        rot['S'] = {
            {1, {0, +1}},
            {1, {0, -1}},
            {0, {+1, 0}},
            {2, {-1, 0}}
        }; 
        rot['W'] = {
            {2, {0, +1}},
            {0, {0, -1}},
            {1, {+1, 0}},
            {1, {-1, 0}}
        }; 
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
//            cout << top.s.f << " " << top.s.s << " " << dist[top.s.f][top.s.s] << endl;

            if (maze[top.s.f][top.s.s] != '.') {
                for (int i = 0; i < rot[maze[top.s.f][top.s.s]].size(); i++) {
                    pair<int, int> new_pos = {top.s.f + rot[maze[top.s.f][top.s.s]][i].s.f, top.s.s + rot[maze[top.s.f][top.s.s]][i].s.s};
                    if (new_pos.f < 0 || new_pos.f >= R || new_pos.s < 0 || new_pos.s >= C) continue;
                    if (maze[new_pos.f][new_pos.s] == '#') {
                        continue;
                    } else if (maze[new_pos.f][new_pos.s] == '.' || maze[new_pos.f][new_pos.s] == m[i]) {
                        if (dist[new_pos.f][new_pos.s] < top.f - 1 - rot[maze[top.s.f][top.s.s]][i].f * rot_cost[top.s]) {
                            dist[new_pos.f][new_pos.s] = top.f - 1 - rot[maze[top.s.f][top.s.s]][i].f * rot_cost[top.s];
                            pq.push({top.f - 1 - rot[maze[top.s.f][top.s.s]][i].f * rot_cost[top.s], new_pos});
                        }
                    }
                }

                continue;
            }

            for (int i = 0; i < 4; i++) {
                pair<int, int> new_pos = {top.s.f + y[i], top.s.s + x[i]};
                if (new_pos.f < 0 || new_pos.f >= R || new_pos.s < 0 || new_pos.s >= C) continue;

                if (maze[new_pos.f][new_pos.s] == '#') {
                    continue;
                } else if (maze[new_pos.f][new_pos.s] == '.' || maze[new_pos.f][new_pos.s] == m[i]) {
                    if (dist[new_pos.f][new_pos.s] < top.f - 1) {
                        dist[new_pos.f][new_pos.s] = top.f - 1;
                        pq.push({top.f - 1, new_pos});
                    }
                }

            }
        }

        if (dist[0][C - 1] == -INF) {
            cout << "Poor Kianoosh" << endl;
        } else {
            cout << -dist[0][C - 1] << endl;
        }
    }



}