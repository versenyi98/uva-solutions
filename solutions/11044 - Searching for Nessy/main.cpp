#include <iostream>

using namespace std;

int n, m;
int test_case;

int main() {

    cin >> test_case;

    while (test_case--) {
        cin >> n >> m;

        n -= 2;
        m -= 2;

        int h = (n / 3) + (n % 3 > 0 ? 1 : 0);
        int w = (m / 3) + (m % 3 > 0 ? 1 : 0);
        cout << h * w << endl;
    }
}