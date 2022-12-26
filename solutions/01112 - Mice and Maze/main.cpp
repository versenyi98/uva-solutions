#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        if (tt) std::cout << endl;
        int mice, exit_pos, cons, countdown;
        cin >> mice >> exit_pos >> countdown >> cons;

        bool taken[101];
        map<int, vector<pair<int, int>>> can_arrive_from;
        priority_queue<pair<int, int>> pq;

        int from, to, cost;
        for (int i = 1; i <= mice; i++) taken[i] = false;
        for (int i = 0; i < cons; i++) {
            cin >> from >> to >> cost;
            can_arrive_from[to].push_back({from, cost});
        }

        pq.push({0, exit_pos});
        int counter = 0;

        while (!pq.empty() && pq.top().f >= -countdown) {
            auto t = pq.top();
            pq.pop();
            if (taken[t.s]) continue;
            
            counter++;
            taken[t.s] = true;

            for (auto i : can_arrive_from[t.s]) {
                if (taken[i.f]) continue;
                pq.push({t.f - i.s, i.f});
            }
        }
        std::cout << counter << endl;
    }
}