#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int pow(int n, int k) {
    return k == 0 ? 1 : n * pow(n, k - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int days;

    cin >> days;

    while (days--) {
        vector<pair<int, int>> vii;

        auto c = [&vii]() -> bool {
            int a, b;
            cin >> a >> b;
            if (a || b) {
                vii.push_back({a, b});
            }

            return a || b;
        };

        while (c()) {}

        int bound = pow(2, vii.size());

        int maximal = 0;
        for (int i = 0; i < bound; i++) {
            int actual = 0;
            int arr[11] = {0};

            for (int j = 0; j < vii.size(); j++) {
                if (i & (1 << j)) {
                    actual++;
                    arr[vii[j].first]++;
                    arr[vii[j].second]--;
                }
            }

            int counter = 0;
            for (int i = 0; i < 11; i++) {
                counter += arr[i];
                if (counter > 1) break;
            }

            if (counter > 1) continue;
            maximal = max(maximal, actual);
        }

        cout << maximal << endl;
    }

    return 0;
}