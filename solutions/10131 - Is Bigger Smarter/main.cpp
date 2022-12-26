#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<pair<pair<int, int>, int>> elephants;
    vector<vector<int>> path;

    int i = 1;

    int w, s;
    while (cin >> w >> s) {
        elephants.push_back({{w, s}, i});
        i++;
    }

    sort(elephants.begin(), elephants.end(), [] (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if (a.first.first == b.first.first) {
            return a.first.second > b.first.second;
        }
        return a.first.first < b.first.first;
    });

    for (int i = 0; i < elephants.size(); i++) path.push_back({elephants[i].second});

    int mxx = 0;
    int mxx_pos = 0;
    for (int i = elephants.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < elephants.size(); j++) {

            if (elephants[i].first.first < elephants[j].first.first &&
                elephants[i].first.second > elephants[j].first.second) {
                
                if (path[i].size() <= path[j].size()) {
                    path[i] = path[j];
                    path[i].push_back(elephants[i].second);
                }
            }
        }
        if (mxx < path[i].size()) {
            mxx = path[i].size();
            mxx_pos = i;
        }
    }
    cout << mxx << endl;
    for (int i = path[mxx_pos].size() - 1; i >= 0; i--) {
        cout << path[mxx_pos][i] << endl;
    }
}