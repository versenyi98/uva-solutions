#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

int upper = 1;
int lower = 2;

void generate_primes() {
    int count = 0;

    for (int i = lower; i <= upper; i++) {
        int div = 0;
        for (int j : primes) {
            if (j > sqrt(i)) break;
            if (i % j == 0) {
                div++;
                break;
            }
        }
        if (div == 0) {
            primes.push_back(i);
        }
    }
}

int main() {
    
    int tc = 0;
    int n;
    while (cin >> n, n) {
        if (n > upper) {
            upper = max(n, upper);
            generate_primes();
        }

        int c = 0;
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] >= n / 2 + 1) break;
            c += max((long) 0, distance(primes.begin() + i, lower_bound(primes.begin() + i, primes.end(), n - primes[i] + 1) - 1));
        }

        lower = max(lower, n + 1);
        cout << "Case " << ++tc << ": " << c << endl;
    }
}