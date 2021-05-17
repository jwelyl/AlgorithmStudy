#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
//입력의 크기가 작기 때문에 완전탐색을 사용함
vector<vector<string>> v;
set<string> result;
bool IsUniqueKey(vector<int>& picked)
{
	vector<string> keys(v.size(), "");
	set<string> s;
	for (const auto& pick : picked) {
		for (int i = 0; i<v.size(); i++)
			keys[i] += v[i][pick];
	}

	for (const auto& key : keys) {
		if (s.find(key) != s.end())
			return false;
		s.insert(key);
	}
	return true;
}
void UpdateMinimal(vector<int>& picked)
{
	string candidate = "";
	for (const auto& pick : picked)
		candidate += to_string(pick);
	for (const auto& key : result) {
		int cnt = 0;
		for (const auto& c : candidate) {
			if (c == key[cnt]) {
				cnt++;
			}
		}
		if (cnt == key.length()) {
			return;
		}
	}
	cout << "키 추가: " << candidate << endl;
	result.insert(candidate);
}
void bf(int n, vector<int>& picked, int toPick, int idx)
{
	if (toPick == 0 && IsUniqueKey(picked)) {
		UpdateMinimal(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : idx + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		bf(n, picked, toPick - 1, next);
		picked.pop_back();
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	v = relation;
	vector<int> picked;
	for (int toPick = 1; toPick <= relation[0].size(); toPick++)
		bf(relation[0].size(), picked, toPick, 0);
	answer = result.size();
	return answer;
}