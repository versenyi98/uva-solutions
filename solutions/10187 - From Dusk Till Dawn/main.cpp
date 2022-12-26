#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

#define INF 1000000000

int main() {

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; ++i) {
        cout << "Test Case " << i + 1 << "." << endl;
    
        map<string, pair<int, int>> distance;
        map<string, vector<pair<string, pair<int, int>>>> connections;

        int routes;
        string from, to;
        int start, len;

        cin >> routes;
        for (int j = 0; j < routes; j++) {
            cin >> from >> to >> start >> len;

            if (len > 12) continue;
            if (len == 12 && start != 18) continue;
            if (start < 18 && start > 6) continue;
            if ((start + len) % 24 > 6 && (start + len) % 24 < 18) continue;
            if (start < 12) start += 24;

            connections[from].push_back({to, {start, len}});
            distance[from] = {-INF, -INF};
            distance[to] = {-INF, -INF};
        }

        cin >> from >> to;
        priority_queue<pair<int, pair<int, string>>> pq;
        distance[to] = {-INF, -INF};
        distance[from] = {0, 0};
        pq.push({0, {-12, from}});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            //cout << top.ff << " " << top.ss.ff << " " << top.ss.ss << endl;
            for (auto j : connections[top.ss.ss]) {
                int blood = top.ff;
                int hour = top.ss.ff;

                if (j.ss.ff < -hour) {
                    blood--;
                } 
                hour = -j.ss.ff - j.ss.ss;

                if (distance[j.ff].ff < blood || (distance[j.ff].ff == blood && distance[j.ff].ss < hour)) {
                    distance[j.ff] = {blood, hour};
                    //cout << "\t" << blood << " " << hour << " " << j.ff << endl;
                    pq.push({blood, {hour, j.ff}});
                }
            }
        }

        if (distance[to].ff == -INF) {
            cout << "There is no route Vladimir can take." << endl;
        } else {
            cout << "Vladimir needs " << -distance[to].ff << " litre(s) of blood." << endl;
        }
    }
}