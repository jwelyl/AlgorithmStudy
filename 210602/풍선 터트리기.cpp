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
	//-16,27,65,-2,58,-92,-71,-68,-61,-33

	//-16,27,65,-2,58,-92,-71,-68,-61,-33
	int start = 0;
	int end = a.size();

	vector<int> left(a.size());
	vector<int> right(a.size());
	left[0] = a[0];
	right[a.size() - 1] = a[a.size() - 1];

	for (int i = 1; i < a.size(); i++) {
		if (left[i - 1] < a[i]) {
			left[i] = left[i - 1];
		}
		else {
			left[i] = a[i];
		}
	}

	for (int i = a.size() - 2; i >= 0; i--) {
		if (right[i + 1] < a[i]) {
			right[i] = right[i + 1];
		}
		else {
			right[i] = a[i];
		}
	}

	for (int i = 0; i < a.size(); i++) {
		if (i == 0 || i == a.size() - 1) {
			answer++;
			continue;
		}
		else {
			if (left[i - 1] < a[i] && right[i + 1] < a[i]) continue;
		}
		answer++;
	}
	return answer;
}