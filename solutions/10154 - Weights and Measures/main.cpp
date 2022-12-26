#include <bits/stdc++.h>

using namespace std;

int main() {

    long w, s;
    vector<pair<long, long>> turtles;
    while (cin >> w >> s) {
        turtles.push_back({w, s});
    }

    vector<vector<long>> weights(turtles.size());
    sort(turtles.begin(), turtles.end(), [](pair<int, int> f, pair<int, int> s) {
        return (f.second == s.second && f.first < s.first) || f.second < s.second;
    });

    for (int i = 0; i < turtles.size(); i++) {
        weights[i] = vector<long>(i + 1, INT_MAX);
    }
    weights[0][0] = turtles[0].first;
    
    for (int i = 1; i < turtles.size(); i++) {
        weights[i][0] = min(weights[i - 1][0], turtles[i].first);
    }

    int result = 1;
    for (int i = 1; i < turtles.size(); i++) {
        for (int j = 1; j < i + 1; j++) {
            if (i - 1 >= j) {
                weights[i][j] = weights[i - 1][j];
            }
            if (weights[i - 1][j - 1] + turtles[i].first <= turtles[i].second) {
                result = max(result, j + 1);
                weights[i][j] = min(weights[i - 1][j - 1] + turtles[i].first, weights[i][j]);
            }
        }
    }
    cout << result << endl;
    return 0;
}