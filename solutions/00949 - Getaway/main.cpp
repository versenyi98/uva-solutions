#include <bits/stdc++.h>
#include <set>

using namespace std;

#define f first
#define s second

int main() {

    int rows, cols;

    while (cin >> cols >> rows) {
        int rest, mon;
        map<pair<pair<int, int>, pair<int, int>>, bool> cannot_pass;
        map<pair<int, int>, set<int>> monitored;
        map<pair<int, int>, bool> taken;
        priority_queue<pair<int, pair<int, int>>> pq;

        pair<int, int> start = {0, 0};
        pair<int, int> finish = {cols - 1, rows - 1};

        cannot_pass.clear();
        monitored.clear();
        taken.clear();
        pq = priority_queue<pair<int, pair<int, int>>>();

        cin >> rest;
        {
            int a, b, c, d;
            for (int i = 0; i < rest; i++) {
                cin >> a >> b >> c >> d;
                cannot_pass[{{a, b}, {c, d}}] = true;
            }
        }
        
        cin >> mon;
        {
            int a, b, c;
            for (int i = 0; i < mon; i++) {
                cin >> a >> b >> c;
                monitored[{b, c}].insert(a);
            }
        }

        pq.push({0, start});

        while (pq.top().s != finish) {
            auto top = pq.top();
            pq.pop();

            if (taken[top.s]) continue;
            taken[top.s] = true;

            // fel
            if (!cannot_pass[{top.s, {top.s.f, top.s.s - 1}}] && top.s.s - 1 >= 0 && !taken[{top.s.f, top.s.s - 1}]) {
                int cost = top.f - 1;

                while (monitored[{top.s.f, top.s.s - 1}].find(-cost) != monitored[{top.s.f, top.s.s - 1}].end()) {
                    cost--;
                }
                pq.push({cost, {top.s.f, top.s.s - 1}});
            }
            // le
            if (!cannot_pass[{top.s, {top.s.f, top.s.s + 1}}] && top.s.s + 1 < rows && !taken[{top.s.f, top.s.s + 1}]) {
                int cost = top.f - 1;

                while (monitored[{top.s.f, top.s.s + 1}].find(-cost) != monitored[{top.s.f, top.s.s + 1}].end()) {
                    cost--;
                }
                pq.push({cost, {top.s.f, top.s.s + 1}});
            }
            // jobbra
            if (!cannot_pass[{top.s, {top.s.f + 1, top.s.s}}] && top.s.f + 1 < cols && !taken[{top.s.f + 1, top.s.s}]) {
                int cost = top.f - 1;

                while (monitored[{top.s.f + 1, top.s.s}].find(-cost) != monitored[{top.s.f + 1, top.s.s}].end()) {
                    cost--;
                }
                pq.push({cost, {top.s.f + 1, top.s.s}});
            }
            // balra
            if (!cannot_pass[{top.s, {top.s.f - 1, top.s.s}}] && top.s.f - 1 >= 0 && !taken[{top.s.f - 1, top.s.s}]) {
                int cost = top.f - 1;

                while (monitored[{top.s.f - 1, top.s.s}].find(-cost) != monitored[{top.s.f - 1, top.s.s}].end()) {
                    cost--;
                }
                pq.push({cost, {top.s.f - 1, top.s.s}});
            }
        }
        cout << pq.top().f * -1 << endl;
    }
}