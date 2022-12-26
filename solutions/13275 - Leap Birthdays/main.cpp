#include <bits/stdc++.h>

using namespace std;

bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int main() {

    int n;
    cin >> n;

    for (int tc = 1; tc <= n; tc++) {
        int d, m, y, yy;
        cin >> d >> m >> y >> yy;
        bool feb29leap = isLeap(y) && d == 29 && m == 2;
        cout << "Case " << tc << ": ";
        if (feb29leap) {
            int c = 0;
            for (int i = y + 1; i <= yy;) {
                if (isLeap(i)) {
                    c++;
                    i += 4;
                } else {
                    i++;
                }
            }
            cout << c << endl;
        } else {
            cout << max(yy - y, 0) << endl;
        }
    }
}