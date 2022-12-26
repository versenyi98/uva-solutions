#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int64_t a, b;
        cin >> a >> b;
        if (a < b) {
            cout << "<";
        } else if (a > b) {
            cout << ">";
        } else {
            cout << "=";
        }
        cout << endl;
    }
}