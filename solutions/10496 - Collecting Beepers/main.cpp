#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> pos;

int test_cases;
pos map_size;
int beepers_number;
pos beepers[11];
int dp[11][2048];
bool taken[11][2048];

int tsp(int i, int path, int depth) {
    /*
    for (int ii = 0; ii < depth; ii++) {
        cout << "\t";
    }
    cout << i << " " << path << endl;
    */
    if (path == pow(2, beepers_number + 1) - 1) {
        return abs(beepers[i].x - beepers[0].x) + abs(beepers[i].y - beepers[0].y);
    } 
    if (taken[i][path]) return dp[i][path];

    taken[i][path] = true;
    for (int ii = 0; ii <= beepers_number; ii++) {
        if (path & (1 << ii) == 1) continue;
        dp[i][path] = min(dp[i][path], abs(beepers[i].x - beepers[ii].x) + abs(beepers[i].y - beepers[ii].y) + tsp(ii, path | (1 << ii), depth + 1));
    }

    return dp[i][path];
}

int main() {

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {

        cin >> map_size.x >> map_size.y;
        cin >> beepers[0].x >> beepers[0].y;

        cin >> beepers_number;

        for (int i = 1; i <= beepers_number; i++) {
            cin >> beepers[i].x >> beepers[i].y;
        }

        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 2048; j++) {
                taken[i][j] = false;
                dp[i][j] = 1000000000;
            }
        }
        cout << "The shortest path has length " << tsp(0, 1, 0) << endl;
    }
}