#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string arr = "ACFJMNRT";
vector<string> _data;
bool visit[8];
int result = 0;
bool check(string& comb)
{
	for (const auto& str : _data) {
		char a = str[0];
		char b = str[2];
		char op = str[3];
		int dist = str[4] - '0';
		int indexA = -1;
		int indexB = -1;
		for (int i = 0; i < comb.length(); i++) {
			if (comb[i] == a)
				indexA = i;
			if (comb[i] == b)
				indexB = i;
		}
		int d = abs(indexA - indexB) - 1;
		switch (op) {
		case '=':
			if (d != dist)
				return false;
			break;
		case '>':
			if (d <= dist)
				return false;
			break;
		case '<':
			if (d >= dist)
				return false;
			break;
		}
	}
	return true;
}
void dfs(int n, int cnt, string& comb)
{
	if (cnt == 8) {
		if (check(comb))
			result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			comb.push_back(arr[i]);
			dfs(n, cnt + 1, comb);
			visit[i] = false;
			comb.pop_back();
		}
	}
}
int solution(int n, vector<string> data) {
	int answer = 0;
	result = 0; //이거 없음 틀림.. 왜지
	for (int i = 0; i < 8; i++)
		visit[i] = false;
	_data = data;
	string comb;
	dfs(arr.length(), 0, comb);
	answer = result;
	return answer;
}