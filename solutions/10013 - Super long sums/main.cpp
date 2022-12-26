#include <bits/stdc++.h>

using namespace std;

int a[1000000];
int b[1000000];
int tc, n;

void rec(int index, int rem) {

    if (index < 0) return;
    rec(index - 1, (a[index] + b[index] + rem) / 10);

    if (index == 0) {
        cout << a[index] + b[index] + rem;
    } else {
        putchar('0' + (a[index] + b[index] + rem) % 10);
    }
}



int main() {

    cin >> tc;

    while (tc--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        rec(n - 1, 0);
        if (tc != 0) cout << endl;
        cout << endl;
    }

}



