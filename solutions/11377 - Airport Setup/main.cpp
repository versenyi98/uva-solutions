#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define MINUS_INF -1000000000

int test_cases;
int number_of_cities, number_of_air_routes, number_of_airports, number_of_demands;

map<int, bool> has_airport;
map<int, vector<int>> valid_routes;

int dist[2001];

int main() {
    int dummy, puppet;

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        has_airport.clear();
        valid_routes.clear();

        cin >> number_of_cities >> number_of_air_routes >> number_of_airports;
        
        for (int i = 0; i < number_of_airports; i++) {
            cin >> dummy;
            has_airport[dummy] = true;
        }

        for (int i = 0; i < number_of_air_routes; i++) {
            cin >> dummy >> puppet;

            valid_routes[dummy].push_back(puppet);
            valid_routes[puppet].push_back(dummy);
        }

        cin >> number_of_demands;

        int from, to;

        cout << "Case " << tc + 1 << ":\n";

        for (int i = 0; i < number_of_demands; i++) {
            cin >> from >> to;

            if (from == to) {
                cout << 0 << endl;
                continue;
            }

            for (int t = 0; t <= number_of_cities; t++) dist[t] = MINUS_INF;

            if (has_airport[from]) {
                dist[from] = 0;
            } else {
                dist[from] = -1;
            }

            priority_queue<pair<int, int>> pq;
            pq.push({dist[from], from});

            while (!pq.empty() && pq.top().s != to) {
                auto current = pq.top();
                pq.pop();

                for (auto j : valid_routes[current.s]) {
                    if (dist[j] < (dist[current.s] + (has_airport[j] ? 0 : -1))) {
                        dist[j] = dist[current.s] + (has_airport[j] ? 0 : -1);
                        pq.push({dist[j], j});
                    }
                }
            }
            
            if (pq.empty()) {
                cout << "-1" << endl;
            } else {
                cout << pq.top().f * -1 << endl;
            }
        }
        cout << endl;
    }
}