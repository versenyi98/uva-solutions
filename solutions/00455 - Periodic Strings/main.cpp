#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int nn = 0; nn < n; nn++) {
        string line;
        cin >> line;
        int sz = 1;

        while (true) {
            if (line.length() % sz != 0) {
                sz++;
                continue;
            }

            string mask = line.substr(0, sz);
            bool good = true;

            for (int i = 0; i < line.length(); i += sz) {
                if (line.substr(i, sz) != mask) {
                    good = false;
                    break;
                }
            }

            if (good) {
                if (nn) cout << endl;
                cout << sz << endl;
                break;
            }
            sz++;
        }
    }
}