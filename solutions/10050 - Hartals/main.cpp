#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {

        int days, parties;
        cin >> days >> parties;

        bool flag[days];
        
        for (int i = 0; i < days; i++) flag[i] = false;
        
        int counter = 0;

        for (int i = 0; i < parties; i++) {
            int period;
            cin >> period;

            int actual = period - 1;

            while (actual <= days - 1) {
                if (!flag[actual] && actual % 7 < 5) {
                    counter++;
                    flag[actual] = true;
                }

                actual += period;
            }
        }

        cout << counter << endl;
    }
}