#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases = 0;
	cin >> test_cases;
	while (test_cases--) {
		int N, CAP_s, CAP_q;

		cin >> N >> CAP_s >> CAP_q;

		queue<int> queues[N];
		stack<int> carrier;

		for (int i = 0; i < N; i++) {
			int n, num;
			cin >> n;
			while (n--) {
				cin >> num;
				queues[i].push(num);
			}
		}

		int res = 0;
		int current_station = 0;
		while (true) {
			
			bool finish = true;
			for (int i = 0; i < N; i++) {
				if (queues[i].size()) finish = false;
			}
			finish = finish && carrier.empty();
			if (finish) break;

			while (queues[current_station].size() != CAP_q && carrier.size()) {
				if (carrier.top() == current_station + 1) {
					carrier.pop();
				} else {
					queues[current_station].push(carrier.top());
					carrier.pop();
				}
				res++;
			}

			while (carrier.size() && carrier.top() == current_station + 1) {
				carrier.pop();
				res++;
			}

			while (queues[current_station].size() && carrier.size() != CAP_s) {
				carrier.push(queues[current_station].front());
				queues[current_station].pop();
				res++;
			}

			res += 2;
			current_station = (current_station + 1) % N;
		}

		cout << max(0, res - 2	) << endl;
	}

	return 0;
}