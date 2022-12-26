#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<uint64_t> squares;
    uint64_t num = 1;

    while (!squares.size() || squares.back() < pow(100000, 2)) {
        squares.push_back(num * num);
        num += 2;
    }

    uint64_t n, m;
    uint64_t tt = 0;
    while (cin >> n >> m, n || m) {

        uint64_t spiral_num = distance(squares.begin(), lower_bound(squares.begin(), squares.end(), m));

        uint64_t x = (n + 1) / 2;
        uint64_t y = (n + 1) / 2;
        if (spiral_num == 0) {
        cout << "Line = " << y << ", column = " << x << "." << endl;
            continue;
        }
        x += spiral_num - 1;
        y += spiral_num;

        uint64_t actual = squares[spiral_num - 1] + 1;

        if (actual + spiral_num * 2 - 1 < m) {
            actual += spiral_num * 2 - 1;
            x -= spiral_num * 2 - 1;
        } else {
            x -= (m - actual);
            actual = m;
        }

        if (actual + spiral_num * 2 < m) {
            actual += spiral_num * 2;
            y -= spiral_num * 2;
        } else {
            y -= (m - actual);
            actual = m;
        }

        if (actual + spiral_num * 2 < m) {
            actual += spiral_num * 2;
            x += spiral_num * 2;
        } else {
            x += (m - actual);
            actual = m;
        }

        if (actual + spiral_num * 2 < m) {
            actual += spiral_num * 2;
            y += spiral_num * 2;
        } else {
            y += (m - actual);
            actual = m;
        }
        cout << "Line = " << y << ", column = " << x << "." << endl;
    }
}