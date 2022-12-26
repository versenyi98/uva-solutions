#include <bits/stdc++.h>

#define f first
#define s second
#define MINUS_INF -1000000000

using namespace std;

int dist[999][999];
int weight[999][999];

priority_queue<pair<int, pair<int, int>>> pq;
int test_case;
int rows, cols;

int main() {
    cin >> test_case;

    while (test_case--) {
        cin >> rows >> cols;

        pq = priority_queue<pair<int, pair<int, int>>>();

        int temp;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> weight[i][j];
                dist[i][j] = MINUS_INF;                
            }
        }

        dist[0][0] = -weight[0][0];
        pq.push({dist[0][0], {0, 0}});

        while (!pq.empty() && (pq.top().s.f != rows - 1 || pq.top().s.s != cols - 1)) {
            auto current = pq.top();
            pq.pop();

            int x[] = {+1, -1, +0, -0};
            int y[] = {+0, -0, +1, -1};

            for (int i = 0; i < 4; i++) {
                if (current.s.f + y[i] < 0 || current.s.f + y[i] >= rows || current.s.s + x[i] < 0 || current.s.s + x[i] >= cols) continue;
                if (dist[current.s.f + y[i]][current.s.s + x[i]] < dist[current.s.f][current.s.s] - weight[current.s.f + y[i]][current.s.s + x[i]]) {
                    dist[current.s.f + y[i]][current.s.s + x[i]] = dist[current.s.f][current.s.s] - weight[current.s.f + y[i]][current.s.s + x[i]];
                    pq.push({dist[current.s.f + y[i]][current.s.s + x[i]], {current.s.f + y[i], current.s.s + x[i]}});
                }
            }
        }
        cout << -pq.top().f << endl;
    }
}