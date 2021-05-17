/*

아직 테케 통과 안되는게 있어서 수정예정

*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string> temp;
bool visit[30] = { false };

string n;
void dfs(vector<string>& v, int start, int idx, int size, vector<vector<pair<string, string>>>& p) {
	if (idx == temp.size()) {

		string s;
		for (int i = 0; i < temp.size(); i++) {
			s += temp[i];
		}
		p[size].push_back(make_pair(s, n));
		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			temp.push_back(v[i]);
			n += to_string(i);
			dfs(v, i + 1, idx, size, p);
			temp.pop_back();
			n.pop_back();
			visit[i] = false;
		}
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	vector<vector<pair<string, string>>> p(relation.size());
	bool check[10] = { false };

	for (int i = 0; i < relation[0].size(); i++) {
		for (int j = 0; j < relation.size(); j++) {
			dfs(relation[j], 0, i + 1, j, p);
		}

		bool chk = true;
		int size = 0;
		vector<string> v;

		for (int j = 0; j < p[0].size(); j++) {
			unordered_map<string, string> m;
			string value = "";
			for (int k = 0; k < p.size(); k++) {
				m[p[k][j].first] = p[k][j].second;
				value = p[k][j].second;
			}

			if (m.size() == p.size()) {
				chk = true;
				for (int k = 0; k < value.size(); k++) {
					if (check[value[k] - '0']) {
						chk = false;
					}
				}

				if (chk) {
					v.push_back(value);
					answer++;
				}
				size = value.size();
			}//발견
		}


		for (int k = 0; k < v.size(); k++) {
			for (int q = 0; q <= v[k].size(); q++) {
				if (q == v[k].size()) {
					for (int r = 0; r < v[k].size(); r++) {
						cout << v[k].at(r);
						check[v[k].at(r) - '0'] = true;
					}
					break;
				}

				if (check[v[k].at(q) - '0']) {
					break;
				}
			}
			cout << endl;
		}
		//cout << endl;

		vector<vector<pair<string, string>>> t(relation.size());
		p = t;
	}

	return answer;
}