#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> m;

int main() {

    int n;
    int M, K;
    cin >> n;

    while (n--) {
        cin >> M >> K;

        if (m[M].size() == 0) {

            queue<int> nxt, how;

            nxt.push(pow(2, M) - 1);
            how.push(1);

            while(nxt.size()) {
                int nxt_top = nxt.front();
                int how_top = how.front();

                nxt.pop();
                how.pop();

                m[M].push_back(nxt_top);

                if (nxt_top > pow(2, M - 1)) {
                    nxt.push(nxt_top - how_top * 2);
                    nxt.push(nxt_top - how_top);

                    how.push(how_top * 2);
                    how.push(how_top * 2);
                }
            }
        }
        cout << distance(m[M].begin(), find(m[M].begin(), m[M].end(), K)) + 1 << endl;
    }
}
