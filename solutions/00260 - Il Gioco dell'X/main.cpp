#include <iostream>
#include <queue>
#include <map>

using namespace std;
#define f first
#define s second

map<pair<int, int>, bool> taken;
vector<string> v;
queue<pair<int, int>> q;

int main() {

    int n;
    int cases = 0;
    bool w;

    while (cin >> n, n) {
        cases++;
        w = false;

        taken.clear();
        v.clear();
        q = queue<pair<int, int>>();

        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            v.push_back(str);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {        
                if (v[i][j] == 'w') {
                    bool left = false, right = false;

                    q.push({i, j});
                    taken[q.front()] = true;
                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();
/*
                        cout << current.f << " " << current.s << endl;
                        for (auto k : v) {
                            cout << k << endl;
                        }
                        cout << endl;
*/
                        v[current.f][current.s] = 'b';

                        if (current.s == 0) left = true;
                        if (current.s == n - 1) right = true;

                        int x[] = {-1, -1, +0, +0, +1, +1};
                        int y[] = {-1, +0, -1, +1, +0, +1};

                        for (int k = 0; k < 6; k++) {
                            if (current.f + x[k] < 0 || current.f + x[k] >= n) continue;
                            if (current.s + y[k] < 0 || current.s + y[k] >= n) continue;
                            pair<int, int> next = {current.f + x[k], current.s + y[k]};
                            if (v[next.f][next.s] == 'b') continue;

                            if (taken[next]) continue;
                            taken[next] = true;

                            q.push(next);
                        }
                    }
                    if (left && right) {
                        w = true;
                        cout << cases << " W" << endl;
                        i = n + 1;
                        j = n + 1;
                    }
                }
            }
        }
        if (!w) cout << cases << " B" << endl;
    }
}