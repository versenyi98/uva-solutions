#include <bits/stdc++.h>

using namespace std;

bool taken[10000];
int dp[10000];

int dynamic(int rem) {

    if (rem == 0) return 0;
    if (rem < 0) return 100001;

    if (taken[rem]) return dp[rem];
    taken[rem] = true;

    int ret = INT_MAX;
    for (int i = 1; i <= 100; i++) {
        ret = min(ret, 1 + dynamic(rem - i * i));
    }
    dp[rem] = ret;
    return dp[rem];
}

int main() {
    int n, t;
    cin >> n;

    while (n--) {
        cin >> t;
        cout << dynamic(t) << endl;
    }
}