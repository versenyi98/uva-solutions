#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;

    while (cin >> N, N) {

        string line;
        getline(cin, line);
        int val[N];
        int mini = INT_MAX;

        for (int i = 0; i < N; i++) {
            getline(cin, line);
            val[i] = (size_t)count(line.begin(), line.end(), ' ');
            mini = min(mini, val[i]);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) {
            ret += - mini + val[i];
        }
        cout << ret << endl;
    }
}