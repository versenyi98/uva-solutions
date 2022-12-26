#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        int n;
        scanf("%d\n", &n);

        map<char, int> m;

        for (int i = 0; i < n; i++) {
            char ch;
            int num;
            scanf("%c", &ch);
            scanf("%d\n", &num);
            m[ch] = num;
        }

        scanf("%d", &n);
        string line;
        getline(cin, line);

        int sum = 0;
        while (n--) {
            getline(cin, line);
            for (auto i : line) {
                sum += m[i];
            }
        }
        printf("%.2f$\n", sum / 100.00);

    }


}