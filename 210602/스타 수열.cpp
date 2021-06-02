#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
int solution(vector<int> a) {
	int answer = 0;
	
	unordered_map<int, int> m;
	vector<vector<int>> idx(a.size());
	for (int i = 0; i < a.size(); i++) {
		m[a[i]]++;
		idx[a[i]].push_back(i);
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		int value = it->first;
		//0 3 6 9
		vector<bool> visit(a.size(), false);
		int max = 0;
		for (int i = 0; i < idx[value].size(); i++) {
			int start = idx[value][i];

			if ((start - 1 >= 0 && !visit[start - 1] && a[start] != a[start - 1])) {

				visit[start - 1] = true;
				max += 2;
			}
			else if (start + 1 < a.size() && !visit[start + 1] && a[start] != a[start + 1]) {
				visit[start + 1] = true;
				max += 2;
			}

			if (answer < max) {
				answer = max;
			}
		}

	}
	return answer;
}