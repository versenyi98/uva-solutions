#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int tt = 0;
    while (cin >> n, n) {
        int arr[n];
        if (tt++) printf("\n");
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        for (int m = l + 1; m < n; m++) {
                            for (int o = m + 1; o < n; o++) {
                                printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[k], arr[l], arr[m], arr[o]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}