#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        double T, S, D;
        cin >> T >> S >> D;
        bool remove = D > 0;

        if (!remove) D *= -1;

        double high = 100000000000000;
        double low = 0;

        double current_dist = (T * 24 * 60 * 60);
        while (abs(high - low) > 0.00001) {
            double mid = (high + low) / 2;
            if (T * 24 * 60 * 60 * mid >= D * 1000 * 10 * 10 * 10) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (static_cast<int>(high) == 0) remove = false;
        printf("%s %d tons\n", (remove ? "Remove" : "Add"), static_cast<int>(high));
    }

    return 0;
}