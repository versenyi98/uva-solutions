#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cases = 0;
    while (cin >> n, n) {
        cout << "Case " << ++cases << ": ";
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end(), [] (pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        int current = 0;
        int maxi = 0;

        for (auto i : v) {
            current += i.first;
            maxi = max(maxi, current + i.second);
        }

        cout << maxi << endl;
    }

    return 0;
}