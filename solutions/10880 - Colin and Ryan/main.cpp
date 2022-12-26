#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

#define ulli unsigned long long int

using namespace std;

int main() {

    int test_cases;
    ulli cookies, cookies_left, diff;

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {

        set<ulli> divisors;
        vector<ulli> divisors_;

        cin >> cookies >> cookies_left;
        diff = cookies - cookies_left;

        cout << "Case #" << i + 1 << ":";
        
        if (diff == 0) {
            cout << " 0" << endl;
            continue;
        }

        for (ulli i = 1; i <= sqrt(diff); i++) {
            if (diff % i == 0) {
                divisors.insert(diff / i);
                divisors.insert(i);
            }
        }

        for (auto i : divisors) {
            divisors_.push_back(i);
        }

        sort(divisors_.begin(), divisors_.end());

        for (auto i : divisors_) {
            if (i > cookies_left) cout << " " << i;
        }
        cout << endl;
    }
}
