#include <bits/stdc++.h>

using namespace std;

vector<uint64_t> v;

void gen() {
    for (int i = 0; i <= 32; i++) {
        for (int j = 0; j <= 32; j++) {
            v.push_back(pow(2, i) * pow(3, j));
        }
    }
}

int main() {

    gen();
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());

    int n;
    while (cin >> n, n) {
        cout << *(upper_bound(v.begin(), v.end(), n - 1)) << endl;
    }
}