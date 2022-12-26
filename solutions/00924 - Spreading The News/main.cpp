#include <bits/stdc++.h>

using namespace std;

#define s second
#define f first

int main() {

    int employees;
    cin >> employees;
    map<int, vector<int>> friends;

    for (int i = 0; i < employees; i++) {
        int number_of_friends;
        cin >> number_of_friends; 
        while (number_of_friends--) {
            int a;
            cin >> a;
            friends[i].push_back(a);
        }   
    }

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        bool taken[2500];
        int news_on_day[2500];

        int current_max = 0;
        int max_day = 0;
        
        for (int i = 0; i < employees; i++) {
            taken[i] = false;
            news_on_day[i] = 0;
        }
        
        queue<pair<int, int>> q;

        int source;
        cin >> source;

        q.push({source, 0});

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;

            if (++news_on_day[top.s] > current_max && top.s != 0) {
                current_max = news_on_day[top.s];
                max_day = top.s;
            }

            for (auto i : friends[top.f]) {
                if (taken[i]) continue;
                q.push({i, top.s + 1});
            }
        }
        if (max_day == 0) {
            cout << 0 << endl;
        } else {
            cout << current_max << " " << max_day << endl;
        }
    }
}