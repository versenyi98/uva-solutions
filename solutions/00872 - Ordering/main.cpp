#include <bits/stdc++.h>

using namespace std;

map<char, vector<char>> points_to;
map<char, vector<char>> pointed_by;
vector<char> characters;
map<char, bool> seen;

vector<pair<char, int>> stack_;
vector<string> sol;

string trash;

int main() {

    int tc;
    cin >> tc;
    getline(cin, trash);
    for (int tt = 0; tt < tc; tt++) {
        if (tt) putchar('\n');
        stack_.clear();
        characters.clear();
        points_to.clear();
        pointed_by.clear();
        seen.clear();
        sol.clear();

        string variables, relations;
        getline(cin, trash);
        getline(cin, variables);
        getline(cin, relations);

        for (int i = 0; i < variables.length(); i+=2) {
            characters.push_back(variables[i]);
        }

        for (int i = 0; i < relations.length(); i+=4) {
            pointed_by[relations[i + 2]].push_back(relations[i]);
            points_to[relations[i]].push_back(relations[i + 2]);
        }

        stack_.push_back({' ', -1});

        while (stack_.size() > 0) {
            stack_.back().second++;
            if (stack_.back().second == characters.size()) {
                seen[stack_.back().first] = false;
                stack_.pop_back();
                continue;
            }

            if (stack_.size() == 1 + characters.size()) {
                string solution = "";

                for (int i = 1; i < stack_.size(); i++) {
                    solution += stack_[i].first;
                }
                sol.push_back(solution) ;
                seen[stack_.back().first] = false;
                stack_.pop_back();
                continue;
            }

            bool seen_parents = true;
            for (auto i : pointed_by[characters[stack_.back().second]]) {
                if (!seen[i]) {
                    seen_parents = false;
                    break;
                }
            }

            if (!seen_parents || seen[characters[stack_.back().second]]) {
                continue;
            }

            seen[characters[stack_.back().second]] = true;
            stack_.push_back({characters[stack_.back().second], -1});
        }
        if (sol.size() == 0) {
            cout << "NO\n";
            continue;
        }
        
        sort(sol.begin(), sol.end());
        for (int i = 0; i < sol.size(); i++) {
            for (int j = 0; j < sol[i].length(); j++) {
                if (j) putchar(' ');
                putchar(sol[i][j]);
            }
            putchar('\n');
        }
    }
}