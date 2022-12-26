#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int tt = 0; tt < tc; tt++) {

        int city_num;
        map<string, int> dist;
        int solution[100];

        cin >> city_num;

        string str;
        for (int i = 0; i < city_num; i++) {
            cin >> str;
            dist[str] = 1000000000;
        }
        dist["Calgary"] = 0;

        map<string, vector<pair<string, int>>> connections;
        int conn;
        cin >> conn;

        string from, to;
        int cost;

        for (int i = 0; i < conn; i++) {
            cin >> from >> to >> cost;
            connections[from].push_back({to, cost});
        }

        queue<string> q;
        q.push("Calgary");

        for (int i = 0; i < city_num; i++) {
            vector<pair<string, int>> temp;
            int qs = q.size();

            for (int j = 0; j < qs; j++) {
                auto top = q.front();
                q.pop();

                for (auto k : connections[top]) {
                    if (dist[k.first] > k.second + dist[top]) {
                        temp.push_back({k.first, k.second + dist[top]});
                        q.push(k.first);
                    }
                }

            }

            for (auto j : temp) {
                dist[j.first] = min(dist[j.first], j.second);
            }

            solution[i] = dist["Fredericton"];
        }

        int query;
        cin >> query;

        if (tt) cout << endl;
        cout << "Scenario #" << tt + 1 << endl;
        for (int i = 0; i < query; i++) {
            int qq;
            cin >> qq;

            if (qq > city_num - 1) {
                qq = city_num - 1;
            }

            if (solution[qq] == 1000000000) {
                cout << "No satisfactory flights" << endl;
            } else {
                cout << "Total cost of flight(s) is $" << solution[qq] << endl;
            }
        }
    }
}