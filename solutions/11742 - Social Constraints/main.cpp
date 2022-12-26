#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int fact(int n) {
    return n == 0 ? 1 : n * fact(n - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m, n || m) {
        vector<int> v;
        for (int i = 0; i < n; i++) v.push_back(i);

        map<int, int> pos;
        map<pair<int, int>, set<int>> constraints;
        int a, b, c;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            constraints[{a, b}].insert(c);
        }

        int counter = 0;
        for (int i = 0; i < fact(n); i++) {
            for (int j = 0; j < v.size(); j++) {
                pos[v[j]] = j;
            }

            bool good = true;
            for (auto j : constraints) {
                for (auto sec : j.second) {
                    if (sec < 0) {
                        good = abs(pos[j.first.first] - pos[j.first.second]) >= abs(sec);
                    } else {
                        good = abs(pos[j.first.first] - pos[j.first.second]) <= abs(sec);
                    }
                    if (!good) break;
                }
                if (!good) break;
            }
            if (good) counter++;
            next_permutation(v.begin(), v.end());
        }

        cout << counter << endl;
    }

    return 0;
}