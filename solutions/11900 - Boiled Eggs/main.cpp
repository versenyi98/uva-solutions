#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        int n, m, o;
        cin >> n >> m >> o;
        vector<int> v(n);

        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end());

        int idx = 0;
        int sum = 0;
        while (idx < v.size() && idx < m && sum + v[idx] <= o) {
            sum += v[idx];
            idx++;
        }
        cout << "Case " << i + 1 << ": " << idx << endl;
    }

    return 0;
}