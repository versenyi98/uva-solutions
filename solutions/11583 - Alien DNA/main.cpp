#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        int n;
        scanf("%d", &n);

        char line[26];
        char common[26];
        for (int i = 0; i < 26; i++) common[i] = 'a' + i;
        int common_size = 26;

        int cuts = 0;

        for (int i = 0; i < n; i++) {
            scanf("%s", line);
            char new_common[26];
            int new_common_size = 0;
            for (int j = 0; j < strlen(line); j++) {
                for (int i = 0; i < common_size; i++) {
                    if (line[j] == common[i]) {
                        new_common[new_common_size++] = line[j];
                    }
                }
            }
            if (new_common_size == 0) {
                strcpy(common, line);
                common_size = strlen(line);
                cuts++;
            } else {
                strcpy(common, new_common);
                common_size = new_common_size;
            }
        }
        printf("%d\n", cuts);
    }

    return 0;
}