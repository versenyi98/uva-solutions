#include <bits/stdc++.h>

using namespace std;

int main() {

    int set_num = 1;
    string line;

    while (getline(cin, line)) {

        int turns_green[3700] = {0};
        int turns_red[3700] = {0};
        int pos;
        int minimal = INT_MAX;
        int x = 0;

        auto last = line.find_last_not_of(' ');
        line = line.substr(0, last + 1);
        while (pos = line.find(' '), pos != string::npos) {
            x++;

            int val = stoi(line.substr(0, pos));
            minimal = min(minimal, val);

            bool g = true;
            int po = 0;

            while (po < 3700) {
                if (g) {
                    turns_green[po]++;
                } else {
                    turns_red[po - 5]++;
                }

                g = !g;
                po += val;
            }
            line = line.substr(pos + 1);
        }

        int val = stoi(line);
        minimal = min(minimal, val);
        bool g = true;
        int po = 0;
        x++;

        while (po < 3700) {
            if (g) {
                turns_green[po]++;
            } else {
                turns_red[po - 5]++;
            }

            g = !g;
            po += val;
        }

        int active_counter = 0;
        bool found = false;
        int solution;
        for (int i = 0; i <= 3600; i++) {
            active_counter += turns_green[i];
            active_counter -= turns_red[i];

            if (active_counter == x && i > minimal) {
                solution = i;
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Set %d is unable to synch after one hour.\n", set_num++);
        } else {
            printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", set_num++, solution / 60, solution % 60);
        }
    }
}