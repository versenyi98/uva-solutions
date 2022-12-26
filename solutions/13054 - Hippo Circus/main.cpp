#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        cout << "Case " << t + 1 << ": ";
        int N, H, TA, TD;
        cin >> N >> H >> TA >> TD;

        vector<int> v(N);

        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int solo = N, duo = 0;
        int low = 0; int high = N - 1;

        if (2 * TA > TD) {
            while (low < high) {
                if (v[low] + v[high] < H) {
                    high--;
                    low++;
                    solo -= 2;
                    duo++;
                } else {
                    high--;
                }
            }
        }

        cout << duo * TD + solo * TA << endl;
    }

    return 0;
}