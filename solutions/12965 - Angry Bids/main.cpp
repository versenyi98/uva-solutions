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
        int prod, cons;
        cin >> prod >> cons;

        vector<int> p, c;
        vector<int> sorted;

        for (int i = 0; i < prod; i++) {
            int a;
            cin >> a;
            p.push_back(a);
            sorted.push_back(a);
        }

        for (int i = 0; i < cons; i++) {
            int a;
            cin >> a;
            c.push_back(a);
            sorted.push_back(a);
        }

        sorted.push_back(0);
        sort(sorted.begin(), sorted.end());
        sort(p.begin(), p.end());
        sort(c.begin(), c.end());

        int ans1 = INT_MAX, ans2 = INT_MAX;

        for (int i = 0; i < cons + prod + 1; i++) {
            int test = sorted[i];
            int counter = 0;

            for (int j = 0; j < cons; j++) {
                if (c[j] < test) {
                    counter++;
                } else {
                    break;
                }
            }

            for (int j = prod - 1; j >= 0; j--) {
                if (p[j] > test) {
                    counter++;
                } else {
                    break;
                }
            }

            if (counter < ans2) {
                ans1 = test;
                ans2 = counter;
            }
        }

        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}