#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> res;

void recursion(int l, int r, int h) {
    if (l == r) return;
    if (!h) return;

    for (int i = l; i < r; i++) {
        if (i - l <= pow(2, h - 1) - 1 && (r - i - 1 <= pow(2, h - 1) - 1)) {
            res.push_back(i + 1);
            recursion(l, i, h - 1);
            recursion(i + 1, r, h - 1);
            break;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h;
    int t = 1;
    while (cin >> n >> h, n && h) {
        res.clear();
        cout << "Case " << t++ << ":";
        if (pow(2, h) <= n) {
            cout << " Impossible." << endl;
            continue;
        }
        recursion(0, n, h);
        for (int i = 0; i < res.size(); i++) {
            cout << ' ' << res[i];
        }
        cout << endl;

    }

    return 0;
}