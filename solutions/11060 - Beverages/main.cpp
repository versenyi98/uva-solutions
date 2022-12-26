#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> bev;
map<string, bool> seen;
map<string, bool> inqueue;
map<string, vector<string>> depends_on;
vector<string> toposort;
priority_queue<pair<int, string>> pq;

int main() {
    int tc = 0;
    while (cin >> n) {
        tc++;
        bev.clear();
        seen.clear();
        depends_on.clear();
        toposort.clear();

        string s1, s2;
        for (int i = 0; i < n; i++) {
            cin >> s1;
            bev.push_back(s1);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2;
            depends_on[s2].push_back(s1);
        }

        for (int i = 0; i < bev.size(); i++) {
            if (depends_on[bev[i]].size() == 0) {
                pq.push({-i, bev[i]});
                inqueue[bev[i]] = true;
            }  
        }

        while (pq.size()) {
            seen[pq.top().second] = true;
            inqueue[pq.top().second] = false;
            toposort.push_back(pq.top().second);
            pq.pop();

            for (int i = 0; i < bev.size(); i++) {
                if (seen[bev[i]] || inqueue[bev[i]]) continue;
                bool ready = true;

                for (auto j : depends_on[bev[i]]) {
                    if (!seen[j]) {
                        ready = false;
                        break;
                    }
                }

                if (ready) {
                    inqueue[bev[i]] = true;
                    pq.push({-i, bev[i]});
                }
            }
        }

        cout << "Case #" << tc << ": Dilbert should drink beverages in this order:";

        for (int i = 0; i < toposort.size(); i++) {
            cout << ' ' << toposort[i];
        }
        cout << ".\n\n";
    }



}