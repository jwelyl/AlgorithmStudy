#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;
	if (a > b) {
		int temp = b;
		b = a;
		a = temp;
	}
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		v.push_back({ i + 1,i + 1 });
	}
	bool chk = false;
	while (1) {
		vector<pair<int, int>> v2;
		answer++;
		for (int i = 0; i < v.size(); i += 2) {

			if (i != v.size() - 1) {
				if (v[i].second == a && v[i + 1].second == b) {
					chk = true;
					break;
				}

				if (v[i + 1].second == a || v[i + 1].second == b) {
					v2.push_back({ i + 1, v[i + 1].second });
					continue;
				}

				if (v[i].second == a || v[i].second == b) {
					v2.push_back({ i + 1, v[i].second });
					continue;
				}
			}

			v2.push_back({ i + 1, v[i].second });
		}
		if (chk) {
			break;
		}
		v = v2;

	}

	return answer;
}