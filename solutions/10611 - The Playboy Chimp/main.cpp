#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int qq;
        cin >> qq;

        auto l = lower_bound(v.begin(), v.end(), qq);
        auto r = upper_bound(v.begin(), v.end(), qq);

        if (l - 1 < v.begin()) {
            putchar('X');
        } else {
            cout << *(l - 1);
        }

        putchar(' ');

        if (r == v.end()) {
            putchar('X');
        } else {
            cout << *r;
        }
        cout << endl;
    }
}