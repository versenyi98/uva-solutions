#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while (test--) {
        int n, w;
        cin >> n >> w;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a; v.push_back(a);
        }

        sort(v.begin(), v.end());

        int idx = 0, sum = 0;

        while (idx < v.size() && sum + v[idx] <= w) {
            sum += v[idx];
            idx++;
        }

        cout << idx << endl;
    }

    return 0;
}