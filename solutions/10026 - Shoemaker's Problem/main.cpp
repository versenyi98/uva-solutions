#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        if (t) cout << endl;
        int n;

        cin >> n;
        vector<pair<int, pair<int, int>>> v(n);

        for (int i = 0; i < n; i++) {
            v[i].first = i + 1;
            cin >> v[i].second.first >> v[i].second.second;
        }

        sort(v.begin(), v.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            return a.second.first * b.second.second < b.second.first * a.second.second;
        });

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << v[i].first;
        }
        cout << endl;
    }

    return 0;
}