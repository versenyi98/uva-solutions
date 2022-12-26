#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int tt = 0; tt < tc; tt++) {
        int city;
        cin >> city;
        vector<int> h, w, dec, inc;
        for (int i = 0; i < city; i++) {
            int tmp;
            cin >> tmp;

            h.push_back(tmp);
        }
        int maxi = INT_MIN, maxd = INT_MIN;

        for (int i = 0; i < city; i++) {
            int tmp;
            cin >> tmp;
            w.push_back(tmp);
            dec.push_back(tmp);
            inc.push_back(tmp);
                            
            maxd = max(maxd, tmp);
            maxi = max(maxi, tmp);
        }

        for (int i = city - 1; i >= 0; i--) {
            for (int j = i + 1; j < city; j++) {
                if (h[j] > h[i]) {
                    inc[i] = max(inc[i], inc[j] + w[i]);
                    maxi = max(inc[i], maxi);
                } else if (h[j] < h[i]) {
                    dec[i] = max(dec[i], dec[j] + w[i]);
                    maxd = max(maxd, dec[i]);
                }
            }
        }

        if (maxi >= maxd) {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", tt + 1, maxi, maxd);
        } else {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", tt + 1, maxd, maxi);
        }
    }
}