#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int64_t test_cases;
    cin >> test_cases;

    for (int64_t t = 0; t < test_cases; t++) {
        cout << "Case " << t + 1 << ": ";

        int64_t n, k;
        cin >> n >> k;
        vector<int64_t> v;

        for (int64_t i = 0; i < n; i++) {
            int64_t a; cin >> a; v.push_back(a);
        }

        for (int64_t i = 0; i < n; i++) {
            int64_t a; cin >> a; v[i] = a - v[i];
        }

        sort(v.begin(), v.end());

        int64_t idx = 0;
        int64_t res = 0;
        while (idx < v.size() && v[idx] <= 0 && k) {
            k--;
            idx++;
        }

        for (int64_t i = idx; i < n; i++) {
            res += v[i];
        }

        if (res <= 0) cout << "No Profit" << endl;
        if (res >  0) cout << res << endl;
    }

    return 0;
}