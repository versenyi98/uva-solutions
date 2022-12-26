#include <bits/stdc++.h>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);

    int N, M;

    while (scanf("%d %d", &M, &N) == 2) {
        int popes[N];
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &popes[i]);
        }

        int L = 0, R = 0, MAX = 0;
        queue<long long> q;

        for (int i = 0; i < N; i++) {

            while (q.size() && popes[i] - q.front() + 1 > M) {
                q.pop();
            }

            q.push(popes[i]);

            if (q.size() > MAX) {
                MAX = q.size();
                L = q.front();
                R = popes[i];
            }
        }
        printf("%d %d %d\n", MAX, L, R);
    }
}