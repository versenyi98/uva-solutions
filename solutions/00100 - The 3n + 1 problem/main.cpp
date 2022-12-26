#include <bits/stdc++.h>

using namespace std;

int count(int n) {

    int counter = 1;
    
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n =  3 * n + 1;
        }
        counter++;
    }
    
    return counter;
}

int main() {

    int from, to;
    while (cin >> from >> to) {
        int maximum = -1;
        for (int i = min(from, to); i <= max(from, to); i++) {
            maximum = max(maximum, count(i));
        }
        cout << from << " " << to << " " << maximum << endl;
    }
}