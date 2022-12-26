#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        vector<uint64_t> v;
        uint64_t n;

        cin >> n;

        for (int i = 0; i < n; i++) {
            uint64_t a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());

        uint64_t sum = 0;

        for (int i = v.size() - 1; i >= 0; i -= 3) {
            if (i >= 2) sum += v[i - 2];
        }
        cout << sum << endl;
    }

    return 0;
}