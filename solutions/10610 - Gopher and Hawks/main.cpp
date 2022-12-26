#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<double, double> pdd;

int speed, minutes;
vector<pdd> holes;
map<int, vector<int>> connections;

double dist(int i, int j) {
    return sqrt(pow(holes[i].f - holes[j].f, 2) + pow(holes[i].s - holes[j].s, 2)) / speed;
}

int main() {

    while (cin >> speed >> minutes, speed || minutes) {

        string str;
        getline(cin, str);

        holes.clear();
        connections.clear();

        while (getline(cin, str), str.length() != 0) {
            double d1, d2;
            d1 = stod(str.substr(0, str.find(' ')));
            d2 = stod(str.substr(str.find(' ') + 1));
            holes.push_back({d1, d2});

            for (int i = 0; i < holes.size() - 1; i++) {
                double distance = dist(i, holes.size() - 1);
                if (distance > minutes * 60) continue;
                connections[i].push_back(holes.size() - 1);
                connections[holes.size() - 1].push_back(i);
            }
        }

        map<int, bool> taken;
        // index, holes visited
        queue<pair<int, int>> q;

        q.push({0, 0});

        while (!q.empty() && q.front().f != 1) {

            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;

            for (auto i : connections[top.f]) {
                if (!taken[i]) {
                    q.push({i, top.s + 1});
                }
            }
        }

        if (q.empty()) {
            cout << "No.\n";
        } else {
            cout << "Yes, visiting " << max(0, q.front().s - 1) << " other holes." << endl;
        }
    }
} 