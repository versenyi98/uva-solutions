#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        vector<int> pq;
        int s, r;
        for (int i = 0; i < n; i++) {
            cin >> s >> r;
            pq.push_back(s - r);
        }

        sort(pq.begin(), pq.end(), greater<int>());

        int res = 0;
        int i = 0;
        while (i < pq.size()) {
            int top = pq[i];
            if (top > 0) {
                res += 3;
            } else if (abs(top) + 1 <= m) {
                m = m + top - 1;
                res += 3;
            } else if (abs(top) == m) {
                res++;
                m += top;
            }
            i++;
        }

        cout << res << endl;
    }

    return 0;
}