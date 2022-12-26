#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    auto comp = [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    };

    for (int t = 0; t < test_cases; t++) {
        if (t) cout << endl;
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), comp);

        priority_queue<int> pq;
        int current = 0;

        for (int i = 0; i < n; i++) {
            pq.push(v[i].first);
            current += v[i].first;
            if (current > v[i].second) {
                current -= pq.top();
                pq.pop();
            }
        }

        cout << pq.size() << endl;
    }

    return 0;
}