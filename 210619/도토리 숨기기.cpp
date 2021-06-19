#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
#include<cmath>
using namespace std;
struct info {
	int s;
	int e;
	int c;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int k;
	int d;
	cin >> n >> k >> d;
	vector<info> box;
	int start = 0;
	int end = n;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		box.push_back({ a,b,c });
	}

	while (start <= end) {
		int mid = (start + end) / 2;
		long long int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (mid < box[i].s) continue;
			int min2 = min(mid, box[i].e);
			cnt += (min2 - box[i].s) / box[i].c + 1;

		}

		if (cnt >= d) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}

	}
	cout << start << endl;
	return 0;
}