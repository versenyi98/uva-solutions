#include <bits/stdc++.h>

#define f first
#define s second
#define MINUS_INF -1000000000

using namespace std;

map<int, vector<pair<int, int>>> connections;
int dist[501];
int fire_stations[501];
int test_cases;
int number_of_firestations;
int number_of_intersections;

priority_queue<pair<int, int>> pq;

int main() {

    cin >> test_cases;

    while (test_cases--) {
        connections.clear();

        cin >> number_of_firestations >> number_of_intersections;
        
        for (int i = 0; i < number_of_firestations; i++) {
            cin >> fire_stations[i];
        }

        int x, y, c;
        string str;

        getline(cin, str);
        while (str = "", getline(cin, str), str.length() != 0) {
            int elso = str.find(' ');

            x = stoi(str.substr(0, elso));
            str = str.substr(elso + 1);

            int masodik = str.find(' ');
            y = stoi(str.substr(0, masodik));
            c = stoi(str.substr(masodik + 1));
            connections[x].push_back({y, c});
            connections[y].push_back({x, c});
        }
    
        int maximum = MINUS_INF;
        int max_pos;
        for (int tt = 1; tt <= number_of_intersections; tt++) {
            pq = priority_queue<pair<int, int>>();
            for (int i = 1; i <= number_of_intersections; i++) {
                dist[i] = MINUS_INF;
            }
            for (int i = 0; i < number_of_firestations; i++) {
                dist[fire_stations[i]] = 0;
                pq.push({0, fire_stations[i]});
            }
            
            dist[tt] = 0;
            pq.push({0, tt});

            while (!pq.empty()) {
                auto current = pq.top();
                pq.pop();

                for (auto i : connections[current.s]) {
                    if (dist[i.f] < dist[current.s] - i.s) {
                        dist[i.f] = dist[current.s] - i.s;
                        pq.push({dist[i.f], i.f});
                    }
                }
            }

            int count = -MINUS_INF;
            for (int i = 1; i <= number_of_intersections; i++) {
                count = min(dist[i], count);
            }

            if (count > maximum) {
                maximum = count;
                max_pos = tt;
            }
        } 

        cout << max_pos << endl;
        if (test_cases) cout << endl;
    }
}