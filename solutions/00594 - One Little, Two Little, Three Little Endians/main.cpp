#include <bits/stdc++.h>

using namespace std;

int main() {

	int number;
	int result;
	while (cin >> number) {
		result = 0;
		// Reverse bit groups
		// From: 00000111 01011011 11001101 00010101
		// To:   00010101 11001101 01011011 00000111
		for (int i = 0; i < 4; i++) {
			result <<= 8;
			result |= (number >> (i * 8)) & 255;
		}

		cout << number << " converts to " << result << endl;
	}


	return 0;
}