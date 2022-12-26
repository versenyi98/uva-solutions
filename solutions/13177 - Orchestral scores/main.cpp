#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int t = 0;
    while (cin >> n >> m) {
        n -= m;

        auto comp = [](pair<int, int> a, pair<int, int> b) {
            return (float)a.first / (float)a.second < (float)b.first / (float)b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            pq.push({a, 1});
        }

        while (n--) {
            auto top = pq.top();
            pq.pop();
            pq.push({top.first, top.second + 1});
        }

        cout << ceil((float)pq.top().first / (float)pq.top().second) << endl;
    }

    return 0;
}