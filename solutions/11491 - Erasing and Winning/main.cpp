#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m, n && m) {

        m = n - m;

        string str;
        cin >> str;

        int idx = 0;

        for (int i = 0; i < m; i++) {
            char maxi = '0' - 1;
            int maxidx = 0;
            for (int j = idx; j < n - m + i + 1; j++) {
                if (str[j] > maxi) {
                    maxi = str[j];
                    maxidx = j;
                }
            }
            idx = maxidx + 1;
            printf("%c", maxi);
        }
        printf("\n");
    }

    return 0;
}