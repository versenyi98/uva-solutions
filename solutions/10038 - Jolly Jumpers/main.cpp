#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while (cin >> n) {

        bool t[n];
        int last = 0;
        int next;
        if (n) {
            cin >> last;
        }

        for (int i = 0; i < n; i++) {
            t[i] = false;
        }
        
        bool all_good = true;
        for (int i = 0; i < n -1; i++) {
            cin >> next;
            
            if (abs(next - last) >= n) {
                all_good = false;
                continue;
            }

            t[abs(next - last)] = true;
            last = next;
        }

        for (int i = 1; i < n; i++) {
            all_good = all_good && t[i];
        }

        if (all_good) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
}