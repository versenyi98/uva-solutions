#include <bits/stdc++.h>

#define f first
#define s second
#define MINUS_INF -1000000000
using namespace std;

map<int, vector<int>> elevator_stops_at;
map<int, vector<int>> which_elevators_stop_here;
vector<int> elevators_speed;

int number_of_elevators, desired_level;
int dist[100];

int main() {

    while (cin >> number_of_elevators >> desired_level) {

        string line;

        elevators_speed.clear();
        which_elevators_stop_here.clear();
        elevator_stops_at.clear();

        priority_queue<pair<int, pair<int, int>>> pq;

        for (int i = 0; i <= 99; i++) {
            dist[i] = MINUS_INF;
        }

        int temp;
        for (int i = 0; i < number_of_elevators; i++) {
            cin >> temp;
            elevators_speed.push_back(temp);
        }
        
        getline(cin, line);
        for (int i = 0; i < number_of_elevators; i++) {
            getline(cin, line);
            size_t pos;

            while (pos = line.find(' '), pos != string::npos) {
                elevator_stops_at[i].push_back(stoi(line.substr(0, pos)));
                which_elevators_stop_here[stoi(line.substr(0, pos))].push_back(i);
                line = line.substr(pos + 1);
            }
            elevator_stops_at[i].push_back(stoi(line));
            which_elevators_stop_here[stoi(line)].push_back(i);
        }

        for (auto i : which_elevators_stop_here[0]) {
            for (auto j : elevator_stops_at[i]) {
                if (dist[j] < -elevators_speed[i] * j) {
                    dist[j] = -elevators_speed[i] * j;
                    pq.push({dist[j], {i, j}});
                }
            }
        }

        pair<int, pair<int, int>> current;
        while (!pq.empty() && pq.top().s.s != desired_level) {
            current = pq.top();
            pq.pop();
            //cout << current.f << " " << current.s.f << " " << current.s.s << endl;

            for (auto i : which_elevators_stop_here[current.s.s]) {
                if (i == current.s.f) continue;
                for (auto j : elevator_stops_at[i]) {
                    if (dist[j] < dist[current.s.s] - 60 - (abs(j - current.s.s)) * elevators_speed[i]) {
                        dist[j] = dist[current.s.s] - 60 - (abs(j - current.s.s)) * elevators_speed[i];
                        pq.push({dist[j], {i, j}});
                    }
                }
            }
        }
        if (pq.empty()) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << -pq.top().f << endl;
        }
    }
}