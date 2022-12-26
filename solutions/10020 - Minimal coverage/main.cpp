#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int nn = 0; nn < n; nn++) {
        if (nn) cout << endl;
        int len;
        cin >> len;

        vector<pair<int, int>> vii;

        int left, right;
        while (cin >> left >> right, left || right) {
            vii.push_back({left, right});
        }

        sort(vii.begin(), vii.end(), [] (pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        int so_far = 0;
        int idx = 0;
        vector<int> v;
        while (so_far < len) {
            int best_idx = -1;
            while (idx < vii.size() && vii[idx].first <= so_far) {
                if (best_idx == -1 || vii[idx].second > vii[best_idx].second) {
                    best_idx = idx;
                }
                idx++;
            }
            if (best_idx == -1) break;
            if (v.size() && v.back() == best_idx) break;
            idx = best_idx;
            v.push_back(idx);
            so_far = vii[best_idx].second;
        }

        if (so_far < len) {
            cout << 0 << endl;
        } else {
            cout << v.size() << endl;
            for (auto i : v) {
                cout << vii[i].first << ' ' << vii[i].second << endl;
            }
        }
    }

    return 0;
}