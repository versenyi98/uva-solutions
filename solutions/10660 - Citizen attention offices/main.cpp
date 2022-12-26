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
        int n;
        cin >> n;

        int area[5][5] = {0};
        int x, y, v;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> v;
            area[x][y] = v;
        }

        int best[5] = {0, 0, 0, 0, 0};
        int min_sum = INT_MAX;

        for (int a = 0; a < 25; a++) {
            for (int b = a + 1; b < 25; b++) {
                for (int c = b + 1; c < 25; c++) {
                    for (int d = c + 1; d < 25; d++) {
                        for (int e = d + 1; e < 25; e++) {
                            int abc[5] = {a, b, c, d, e};
                            int current_sum = 0;
                            pair<int, int> pairs[5];
                            for (int i = 0; i < 5; i++) {
                                pairs[i] = {abc[i] / 5, abc[i] % 5};
                            }

                            for (int i = 0; i < 5; i++) {
                                for (int j = 0; j < 5; j++) {
                                    int closest = INT_MAX;
                                    for (int k = 0; k < 5; k++) {
                                        int current = abs(i - pairs[k].first) + abs(j - pairs[k].second);
                                        closest = min(current, closest);
                                    }
                                    current_sum += closest * area[i][j];
                                }
                            }

                            if (current_sum < min_sum) {
                                min_sum = current_sum;
                                for (int i = 0; i < 5; i++) best[i] = abc[i];
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            if (i) cout << ' ';
            cout << best[i];
        }
        cout << endl;
    }

    return 0;
}