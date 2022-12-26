#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int main() {

    int tc;
    cin >> tc;

    while (tc--) {

        int stations, lines;
        map<int, int> lines_touch;
        map<int, bool> imbortant;
        vector<int> important;
        map<int, vector<int>> connections;

        cin >> stations >> lines;

        for (int i = 0; i < lines; i++) {
            int stat;
            int last = -1;
            while (cin >> stat, stat) {
                if (lines_touch[stat]++ == 1) {
                    important.push_back(stat);
                    imbortant[stat] = true;
                }
                if (last != -1) {
                    connections[last].push_back(stat);
                    connections[stat].push_back(last);
                }
                last = stat;
            }
        }

        int min_avg = 99999999;
        int pos = stations + 50;

        for (int i = 0; i < important.size(); i++) {
            int time[10001];
            int current_avg = 0;
            int important_counter = 0;
            queue<pair<int, int>> q;

            for (int j = 1; j <= stations; j++) {
                time[j] = -1;
            }

            q.push({important[i], 0});

            while (!q.empty() || important_counter != important.size()) {
                auto top = q.front();
                q.pop();

                if (time[top.f] != -1) continue;

                if (imbortant[top.f]) {
                    current_avg += top.s;
                    important_counter++;
                }

                time[top.f] = top.s;

                for (auto j : connections[top.f]) {
                    q.push({j, top.s + 1});
                }
            }

            if (important_counter == important.size() && (current_avg < min_avg || (current_avg == min_avg && pos > important[i]))) {
                min_avg = current_avg;
                pos = important[i];
            }
        }
        cout << "Krochanska is in: " << pos << endl;
    }
}