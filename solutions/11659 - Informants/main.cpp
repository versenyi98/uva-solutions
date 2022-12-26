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

    int n, m;

    while (cin >> n >> m, n || m) {
        vector<pair<int, int>> vii(m);

        for (int i = 0; i < m; i++) {
            cin >> vii[i].first >> vii[i].second;
        }

        int bound = pow(2, n);
        int maximal = 0;

        for (int i = 0; i < bound; i++) {
            string modell = "";
            bool so_far_so_good = true;

            int acutal = 0;

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) acutal++;
            }

            if (acutal <= maximal) continue;
            for (int j = 0; j < m; j++) {
                if (i & 1 << (vii[j].first - 1)) {
                    bool op1 = vii[j].second < 0;
                    bool op2 = (i & (1 << abs(vii[j].second) - 1));
                    if ((op1 && op2) || (!op1 && !op2)) {
                        so_far_so_good = false;
                        break;
                    }
                }
            }

            if (so_far_so_good) {
                maximal = max(maximal, acutal);
            }
        }

        cout << maximal << endl;
    }

    return 0;
}