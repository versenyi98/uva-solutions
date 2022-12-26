#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int L, R, C;

    while (cin >> L >> R >> C, L || R || C) {

        string maze[30][30];
        pair<int, pair<int, int>> start_pos;
        pair<int, pair<int, int>> end_pos;
        queue<pair<pair<int, pair<int, int>>, int>> q;
        map<pair<int, pair<int, int>>, bool> taken;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> maze[i][j];

                if (maze[i][j].find('E') != string::npos) end_pos = {i, {j, maze[i][j].find('E')}};
                if (maze[i][j].find('S') != string::npos) start_pos = {i, {j, maze[i][j].find('S')}};
            }
        }

        q.push({start_pos, 0});

        while (!q.empty() && q.front().f != end_pos) {
            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;

            //cout << top.f.f << " " << top.f.s.f << " " << top.f.s.s << endl;

            //1
            auto p1 = top.f;
            p1.s.f++;
            
            if (p1.s.f >= 0 && p1.s.f < R && !taken[p1] && maze[p1.f][p1.s.f][p1.s.s] != '#') {
                q.push({p1, top.s + 1});
            }

            //2
            auto p2 = top.f;
            p2.s.f--;
            
            if (p2.s.f >= 0 && p2.s.f < R && !taken[p2] && maze[p2.f][p2.s.f][p2.s.s] != '#') {
                q.push({p2, top.s + 1});
            }

            //3
            auto p3 = top.f;
            p3.s.s++;

            if (p3.s.s >= 0 && p3.s.s < C && !taken[p3] && maze[p3.f][p3.s.f][p3.s.s] != '#') {
                q.push({p3, top.s + 1});
            }

            //4
            auto p4 = top.f;
            p4.s.s--;

            if (p4.s.s >= 0 && p4.s.s < C && !taken[p4] && maze[p4.f][p4.s.f][p4.s.s] != '#') {
                q.push({p4, top.s + 1});
            }

            //5
            auto p5 = top.f;
            p5.f++;

            if (p5.f >= 0 && p5.f < L && !taken[p5] && maze[p5.f][p5.s.f][p5.s.s] != '#') {
                q.push({p5, top.s + 1});
            }

            //6
            auto p6 = top.f;
            p6.f--;

            if (p6.f >= 0 && p6.f < L && !taken[p6] && maze[p6.f][p6.s.f][p6.s.s] != '#') {
                q.push({p6, top.s + 1});
            }
        }

        if (q.empty()) {
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << q.front().s << " minute(s)." << endl;
        }
    }
}