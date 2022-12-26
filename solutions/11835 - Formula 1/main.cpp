#include <bits/stdc++.h>

using namespace std;

int main() {

    int G, P;

    while (cin >> G >> P, G || P) {

        int results[G][P];

        for (int i = 0; i < G; i++) {
            for (int j = 0; j < P; j++) {
                cin >> results[i][j];
            }
        }

        int S;
        cin >> S;

        int scoring_systems[S][P];

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < P; j++) {
                scoring_systems[i][j] = 0;
            }
        }

        for (int i = 0; i < S; i++) {
            int N;
            cin >> N;

            for (int j = 0; j < N; j++) {
                cin >> scoring_systems[i][j];
            }
        }

        vector<pair<int, int>> final_result[S];

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < P; j++) {
                final_result[i].push_back({0, -j});
            }
        }

        for (int i = 0; i < G; i++) {
            for (int j = 0; j < P; j++) {
                for (int k = 0; k < S; k++) {
                    final_result[k][j].first += scoring_systems[k][results[i][j] - 1];
                }
            }
        }

        for (int i = 0; i < S; i++) {
            sort(final_result[i].begin(), final_result[i].end());
        }

        for (int i = 0; i < S; i++) {
            int top = final_result[i].back().first;
            int ct = 0;
            while (final_result[i].size() && final_result[i].back().first == top) {
                if (ct++) cout << ' ';
                cout << -final_result[i].back().second + 1;
                final_result[i].pop_back();
            }
            cout << endl;
        }
    }
}