#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n, n) {
        int a;
        int counter = 0;

        while (n--) {
            cin >> a;
            if (a) {
                if (counter++) {
                    cout << ' ';
                }
                cout << a;
            }
        }
        if (!counter) {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}