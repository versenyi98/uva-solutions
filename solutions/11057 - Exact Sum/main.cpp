#include <bits/stdc++.h>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        int nn = n;
        vector<int> books(n);
        map<int, int> counter;
        counter.clear();
        
        while (n != 0) {
            cin >> books[--n];
            counter[books[n]]++;
        }

        sort(books.begin() + 0, books.begin() + nn);

        int diff = INT_MAX;
        int act;
        int money;
        cin >> money;
        if (money % 2 == 0 && counter[money / 2] > 1) {
            act = money / 2;
        } else {
            for (auto i : books) {
                if (i + i == money) continue;
                if (diff > abs(money - i - i) && std::binary_search(books.begin(), books.end(), money - i)) {
                    
                    diff = abs(money - i - i);
                    act = i;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << min(act, money - act) <<  " and " << max(act, money - act) << "." << endl;
        cout << endl;
    }
}