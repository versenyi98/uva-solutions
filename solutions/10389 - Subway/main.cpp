#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define MINUS_INF -1000000000

typedef pair<int, int> pii;

double dist_(pii a, pii b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

vector<pair<int, int>> positions;
pair<int, int> start_pos, school_pos;
map<pair<int, int>, vector<pair<double, pair<int, int>>>> connections;
map<pair<int, int>, double> dist;
priority_queue<pair<double, pair<int, int>>> pq;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        if (tt) cout << endl;

        positions.clear();
        connections.clear();
        dist.clear();
        pq = priority_queue<pair<double, pair<int, int>>>();
        map<pair<int, int>, pair<int, int>> parent;
        int x, y;

        cin >> x >> y;
        start_pos = {x, y};

        cin >> x >> y;
        school_pos = {x, y};

        positions.push_back(start_pos);
        positions.push_back(school_pos);

        double distance_walk = dist_(start_pos, school_pos) / 1000.0 / 10.0 * 60.0;
        connections[start_pos].push_back({distance_walk, school_pos});
        connections[school_pos].push_back({distance_walk, start_pos});

        dist[school_pos] = MINUS_INF;

        string str;
        getline(cin, str);

        while (getline(cin, str)) {
            if (str.length() == 0) break;

            vector<pair<int, int>> stations;
            size_t space_pos;
            while (space_pos = str.find(' '), space_pos != string::npos) {
                x = stoi(str.substr(0, space_pos));
                str = str.substr(space_pos + 1);

                space_pos = str.find(' ');             
                y = stoi(str.substr(0, space_pos));
                str = str.substr(space_pos + 1);

                if (y == -1 && x == -1) break;

                if (stations.size()) {
                    double distance = dist_({x, y}, stations[stations.size() - 1]) / 1000.0 / 40.0 * 60.0;

                    connections[stations[stations.size() - 1]].push_back({distance, {x, y}});
                    connections[{x, y}].push_back({distance, stations[stations.size() - 1   ]});
                }
                

                for (int i = 0; i < positions.size(); i++) {
                    double distance = dist_({x, y}, positions[i]) / 1000.0 / 10.0 * 60.0;

                    connections[positions[i]].push_back({distance, {x, y}});
                    connections[{x, y}].push_back({distance, positions[i]});    
                }

                stations.push_back({x, y});
                positions.push_back({x, y});

                dist[{x, y}] = MINUS_INF;
            }
        }

        dist[start_pos] = 0;

        pq.push({0, start_pos});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (dist[top.s] != top.f) continue;
            for (auto i : connections[top.s]) {
                if (dist[i.s] < top.f - i.f) {
                    dist[i.s] = top.f - i.f;
                    pq.push({dist[i.s], i.s});
                    parent[i.s] = top.s;
                }
            }
        }
/*
        for (auto i : connections) {
            cout << "{" << i.f.f << "," << i.f.s << "} => " << endl;
            for (auto j : i.s) {
                cout << "\t" << dist_(i.f, j.s) << "\t" << j.f << " {" << j.s.f << "," << j.s.s << "}\n";
            }
        }
        auto current = school_pos;

        while (current != start_pos) {
            cout << current.f << "\t" << current.s << endl;
            current = parent[current];
        }
        cout << current.f << "\t" << current.s << endl;
*/
        cout << round(-dist[school_pos]) << endl;
    }
}