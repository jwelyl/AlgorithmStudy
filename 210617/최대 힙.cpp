#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != 0) pq.push(x);
		else {
			if (pq.empty()) cout << "0" << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
	return 0;
}