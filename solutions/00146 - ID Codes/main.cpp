#include <bits/stdc++.h>

using namespace std;

int main() {

	string line, line2;

	while (cin >> line, line2 = line, next_permutation(line2.begin(), line2.end()), cout << (line == "#" ? "" : (line2 <= line ? "No Successor\n" : line2 + "\n")), line != "#");

	return 0;
}