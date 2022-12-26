#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int help() {

    for (int i = 0; i <= 999; i++) {
        for (int j = i; j <= 999; j++) {
            ll res = (i + j) * (i + j);

            if (res / 1000 == i && res % 1000 == j) {
                cout << res << endl;
            } else if (res / 1000 == j && res % 1000 == i) {
                cout << res << endl;
            }
        }
    }
}

int main() {

    vector<string> k2 = {"00","01","81"};
    vector<string> n4 = {"0000","0001","9801","2025","3025"};
    vector<string> h6 = {"000000","000001","998001","088209","494209"};
    vector<string> n8 = {"00000000","00000001","99980001","04941729","07441984",
                    "60481729","52881984", "24502500", "25502500"
    };

    sort(k2.begin(), k2.end());
    sort(n4.begin(), n4.end());
    sort(n8.begin(), n8.end());
    sort(h6.begin(), h6.end());

    int n;
    while (cin >> n) {
        if (n == 2) for (auto i : k2) cout << i << endl;
        if (n == 4) for (auto i : n4) cout << i << endl;
        if (n == 8) for (auto i : n8) cout << i << endl;
        if (n == 6) for (auto i : h6) cout << i << endl;
    }
}