#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		right += v[i];
	}
	int left = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			sum += v[i];
			if (sum >= mid) {
				sum = 0;
				cnt++;
			}
		}

		if (cnt >= m) left = mid + 1;
		else right = mid - 1;
	}
	cout << right << endl;
	return 0;
}