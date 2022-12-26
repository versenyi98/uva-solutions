#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main() {

    lli sr, sc, dr, dc;

    while (cin >> sr >> sc >> dr >> dc, sr || sc || dr || dc) {

        lli down = abs(sr - dr);
        lli side = abs(sc - dc);
        lli downside;
        // nn - nn, nn - ss, ss - ss, ss - nn
        if (abs(sr - sc) % 2 == abs(dr - dc) % 2) {
            downside = down;
        } else if (abs(sr - dr) == abs(sc - dc)) {
            downside = down;
        } else if (sr == dr) {
                downside = 0;
        } else {
            downside = (down <= 1) ? 0 : down - 1;

            if (sr < dr) {
                if (sr % 2 != sc % 2) {
                downside++;
                }
                if (dr % 2 == dc % 2) {
                    downside++;
                }
            } else {
                if (sr % 2 == sc % 2) {
                downside++;
            }
                if (dr % 2 != dc % 2) {
                    downside++;
                }
            }
        }
        cout << down + max(side, downside) << std::endl;
    }
} 