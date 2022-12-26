#include <bits/stdc++.h>

using namespace std;

map<char, vector<char>> adj;
map<char, bool> visited;
set<char> exists;
vector<string> words;

vector<char> topological_sorted;

void dfs(char ind) {

    visited[ind] = true;
    
    for (auto i : adj[ind]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    topological_sorted.push_back(ind);
}

int main() {

    for (int i = 0; i < 26; i++) visited[i] = false;

    string line;
    
    while (cin >> line, line.compare("#") != 0) {
        for (auto i : line) exists.insert(i);
        words.push_back(line);
        if (words.size() > 1) {
            for (int i = 0; i < min(words.back().length(), words[words.size() - 2].length()); i++) {
                if (words.back()[i] == words[words.size() - 2][i]) continue;
                adj[words.back()[i]].push_back(words[words.size() - 2][i]);
                break;
            }
        }
    }

    for (auto i : exists) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < topological_sorted.size(); i++) {
        cout << topological_sorted[i];
    }
    cout << endl;

}