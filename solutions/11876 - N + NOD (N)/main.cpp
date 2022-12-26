#include <bits/stdc++.h>

using namespace std;

int NOD[1000001];
bool calced[1000001];
bool prime[50001];
vector<int> primes;
vector<int> N_plus_NOD;

void sieve() {
    memset(prime, true, sizeof(prime)); 
    for (int i = 2; i <= 50000; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= 50000; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= 50000; i++) {
        if (prime[i]) {
            primes.push_back(i);
            NOD[i] = 2;
            calced[i] = true;   
        }
    }
}

int calc_nod(int num) {
    if (calced[num]) return NOD[num];

    NOD[num] = 1;
    int numb = num;

    for (auto j : primes) {
        if (numb == 1) break;
        if (calced[numb]) {
            NOD[num] *= NOD[numb];
            return NOD[num];
        }
        int counter = 1;
        while (numb % j == 0) {
            numb /= j;
            counter++;
        }
        NOD[num] *= counter;
    }
    
    if (numb != 1) {
        NOD[num] *= 2;
    }

    return NOD[num];
}

void nnod() {
    N_plus_NOD.push_back(1);
    while(N_plus_NOD.back() < 1000000) {
        N_plus_NOD.push_back(N_plus_NOD.back() + calc_nod(N_plus_NOD.back()));
    }
}

int main() {
    sieve();
    nnod();

    sort(N_plus_NOD.begin(), N_plus_NOD.end());
    int n;
    cin >> n;
    int l, h;

    for (int i = 0; i < n; i++) {
        cin >> l >> h;
        cout << "Case " << i + 1 << ": ";
        cout << distance(upper_bound(N_plus_NOD.begin(), N_plus_NOD.end(), l - 1), upper_bound(N_plus_NOD.begin(), N_plus_NOD.end(), h)) << endl;
    }
}