#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, v;
    while (cin >> n >> v) {

        int containers[n];
        
        int l = 1;
        int u = 1000000000;

        for (int i = 0; i < n; i++) {
            cin >> containers[i];
        }

        int ans = INT_MAX;
        
        while (l <= u) {
            int mid = (u + l) / 2;
            int counter = 0;
            int curr = 0;
            bool good = false;
            for (int i = 0; i < n; i++) {
                if (curr + containers[i] <= mid) {
                    curr += containers[i];
                } else {
                    counter++;
                    curr = containers[i];

                    if (containers[i] > mid) {
                        counter = v + 1;
                    }
                }

                if (curr == mid) good = true;
            }
            counter++;

            if (counter <= v && good) {
                ans = min(ans, mid);
            }

            if (counter > v) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }

        cout << ans << endl;
    }
}