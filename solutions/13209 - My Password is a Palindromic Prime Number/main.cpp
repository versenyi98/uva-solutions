#include <bits/stdc++.h>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    
    int used[150000] = {};
    for (int i = 1; i <= tc; i++) {
        int pr;
        cin >> pr;

        putchar('0');
        putchar('.');
        int curr = 10;
        while (true) {
            if (used[curr % pr] == i) break;
            used[curr % pr] = i;

            putchar('0' + (curr / pr));
            curr = (curr % pr) * 10;
        }
        puts("");
    }
}