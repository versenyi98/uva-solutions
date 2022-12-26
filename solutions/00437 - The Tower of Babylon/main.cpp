#include <bits/stdc++.h>

using namespace std;

struct tripple {
    int x, y, z;

    tripple(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int main() {

    int n;
    int tc = 0;
    while (cin >> n, n) {
        tc++;
        int x, y, z;
        vector<tripple> triples;
        vector<int> values;

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            
            triples.push_back(tripple(x, y, z));
            triples.push_back(tripple(y, x, z));
            triples.push_back(tripple(y, z, x));
            triples.push_back(tripple(z, y, x));
            triples.push_back(tripple(z, x, y));
            triples.push_back(tripple(x, z, y));
        }

        sort(triples.begin(), triples.end(), [] (tripple a, tripple b) {
            if (a.x == b.x) {
                return a.y < b.y;
            }
            return a.x < b.x;
        });

        values.resize(triples.size(), 0);

        int mx = 0;
        for (int i = triples.size() - 1; i >= 0; i--) {
            values[i] = triples[i].z;
            mx = max(mx, values[i]);

            for (int j = i + 1; j <= triples.size(); j++) {
                if (triples[i].x < triples[j].x && triples[i].y < triples[j].y) {
                    values[i] = max(values[i], values[j] + triples[i].z);
                    mx = max(mx, values[i]);
                }
            }
        }
        
        cout << "Case " << tc << ": maximum height = " <<  mx << endl;
    }
}