#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int R, C;
    int c = 0;

    while (cin >> R >> C) {
        if (c++ ) cout << endl;

        map<pair<int, int>, bool> figure;
        map<pair<int, int>, bool> taken;

        vector<pair<pair<int, int>, int>> solution;
        queue<pair<int, pair<int, int>>> q;
        pair<int, int> current;

        int x, y;

        for (int i = 0; i < C * 4; i++) {
            cin >> x >> y;
            figure[{x, y}] = true;    
        }


        cin >> x >> y;
        current = {x, y};
/*
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (current == make_pair(i, j)) {
                    cout << "X";
                }  else if (figure[{i, j}]) {
                    cout << "o";
                } else {
                    cout << "-";
                }
            }
            cout << endl;
        }
*/
        if (current.f + 1 <= R && !figure[{current.f + 1, current.s}]) solution.push_back({{current.f + 1, current.s}, 1});
        if (current.s + 1 <= C && !figure[{current.f, current.s + 1}]) solution.push_back({{current.f, current.s + 1}, 1});
        if (current.s - 1 <= C && !figure[{current.f, current.s - 1}]) solution.push_back({{current.f, current.s - 1}, 1});

        if (current.f + 2 <= R && figure[{current.f + 1, current.s}] && !figure[{current.f + 2, current.s}]) q.push({1, {current.f + 2, current.s}});
        if (current.s + 2 <= C && figure[{current.f, current.s + 1}] && !figure[{current.f, current.s + 2}]) q.push({1, {current.f, current.s + 2}});
        if (current.s - 2 >= 0 && figure[{current.f, current.s - 1}] && !figure[{current.f, current.s - 2}]) q.push({1, {current.f, current.s - 2}});
        if (current.f + 2 <= R && current.s + 2 <= C && figure[{current.f + 1, current.s + 1}] && !figure[{current.f + 2, current.s + 2}]) q.push({1, {current.f + 2, current.s + 2}});
        if (current.f + 2 <= R && current.s - 2 >= 0 && figure[{current.f + 1, current.s - 1}] && !figure[{current.f + 2, current.s - 2}]) q.push({1, {current.f + 2, current.s - 2}});

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (taken[top.s]) continue;
            taken[top.s] = true;

            solution.push_back({top.s, top.f});

            if (top.s.f + 2 <= R && figure[{top.s.f + 1, top.s.s}] && !figure[{top.s.f + 2, top.s.s}] && !taken[{top.s.f + 2, top.s.s}]) q.push({top.f + 1, {top.s.f + 2, top.s.s}});
            if (top.s.s + 2 <= C && figure[{top.s.f, top.s.s + 1}] && !figure[{top.s.f, top.s.s + 2}] && !taken[{top.s.f, top.s.s + 2}]) q.push({top.f + 1, {top.s.f, top.s.s + 2}});
            if (top.s.s - 2 >= 0 && figure[{top.s.f, top.s.s - 1}] && !figure[{top.s.f, top.s.s - 2}] && !taken[{top.s.f, top.s.s - 2}]) q.push({top.f + 1, {top.s.f, top.s.s - 2}});
            if (top.s.f + 2 <= R && top.s.s + 2 <= C && figure[{top.s.f + 1, top.s.s + 1}] && !figure[{top.s.f + 2, top.s.s + 2}]  && !taken[{top.s.f + 2, top.s.s + 2}]) q.push({top.f + 1, {top.s.f + 2, top.s.s + 2}});
            if (top.s.f + 2 <= R && top.s.s - 2 >= 0 && figure[{top.s.f + 1, top.s.s - 1}] && !figure[{top.s.f + 2, top.s.s - 2}]  && !taken[{top.s.f + 2, top.s.s - 2}]) q.push({top.f + 1, {top.s.f + 2, top.s.s - 2}});
        }
    
        sort(solution.begin(), solution.end(), [] (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
            return (a.f.f > b.f.f) || (a.f.f == b.f.f && a.f.s < b.f.s);
        });

        for (auto i : solution) {
            cout << i.f.f << " " << i.f.s << " " << i.s << endl;
        }
    }
}