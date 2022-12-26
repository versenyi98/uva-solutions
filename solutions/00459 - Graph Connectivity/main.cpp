#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {

        char last_node;
        cin >> last_node;

        int number_of_nodes = last_node - 'A' + 1;

        vector<int> adj[number_of_nodes];
        bool visited[number_of_nodes];

        string input;
        getline(cin, input);
        while (getline(cin, input), input.length()) {
            adj[input[0] - 'A'].push_back(input[1] - 'A');
            adj[input[1] - 'A'].push_back(input[0] - 'A');
        }

        for (int i = 0; i < number_of_nodes; i++) {
            visited[i] = false;
        }

        int counter = 0;
        for (int i = 0; i < number_of_nodes; i++) {
            if (!visited[i]) {
                counter++;
                queue<int> q;
                q.push(i);

                while (q.size()) {
                    int front = q.front();
                    q.pop();
                    if (visited[front]) continue;

                    visited[front] = true;
                    for (auto j : adj[front]) {
                        if (!visited[j]) {
                            q.push(j);
                        }
                    }
                }
            }
        }

        if (tc) cout << endl;
        cout << counter << endl;
    }
}