#include <bits/stdc++.h>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);

    int N, Q;
    int tc = 0;
    while (cin >> N >> Q, N || Q) {
        vector<int> v;
        int temp;

        while (N--) {
            cin >> temp;
            v.push_back(temp);
        }

        sort(v.begin(), v.end());
        cout << "CASE# " << ++tc << ":\n";
        for (int i = 0; i < Q; i++) {
            int q;
            cin >> q;

            auto pos = lower_bound(v.begin(), v.end(), q);

            if (*pos != q) {
                cout << q << " not found\n";
            } else {
                cout << q << " found at " << distance(v.begin(), pos) + 1 << endl;
            }
        }
    }
}