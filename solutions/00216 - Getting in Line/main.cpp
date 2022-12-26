#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pos;

vector<pos> poses;
vector<pos> solve;
double max_dist;

int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

double dist(pos a, pos b) {
    return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

int main() {

    int size;
    int tc = 1;
    while (cin >> size, size) {

        printf("**********************************************************\nNetwork #%d\n", tc++);

        max_dist = INT_MAX;
        solve.clear();
        poses.clear();

        for (int i = 0; i < size; i++) {
            pos p;
            cin >> p.x >> p.y;

            poses.push_back(p);
        }

        for (int i = 0; i < fact(size); i++) {
            next_permutation(poses.begin(), poses.end());

            double c = 0;
            for (int j = 0; j < size - 1; j++) {
                c += dist(poses[j], poses[j + 1]);
            }

            if (c < max_dist) {
                solve = poses;
                max_dist = c;
            }
        }

        for (int i = 0; i < size - 1; i++) {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", solve[i].x, solve[i].y, solve[i + 1].x, solve[i + 1].y, dist(solve[i], solve[i + 1]) + 16.00);
        }
        printf("Number of feet of cable required is %.2f.\n", max_dist + (size - 1) * 16.00);

    }
}