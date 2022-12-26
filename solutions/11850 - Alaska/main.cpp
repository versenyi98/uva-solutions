#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while (cin >> n, n) {
        bool station[1423];
        for (int i = 0; i < 1423; i++) station[i] = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            station[x] = true;
        }
        int last = 0;
        int current_fuel = 0;
        int i;
        for (i = 0; i <= 1422; i++) {
            if (current_fuel < 0) break;
            if (station[i]) {
                current_fuel = 200;
                last = i;
            }
            current_fuel--;
        }
        cout << (last >= 1322 ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        
    }

}