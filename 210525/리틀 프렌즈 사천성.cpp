#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

string s = "";
struct info {
	int x;
	int y;
	char tile;
	int dir;
	int cost;
};
int value[101][101];
bool check;

void dfs(vector<vector<char>>& map, info v, int ori_x, int ori_y, int chk) {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	for (int i = 0; i < 4; i++) {
		int x = v.x + dx[i];
		int y = v.y + dy[i];
		char nTile = v.tile;
		int nCost = v.cost;
		int dir = v.dir;
		if (nCost > 1) continue;
		if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size()) continue;
		if (map[x][y] == '*') continue;
		if (map[x][y] != nTile && map[x][y] != '.') continue;

		if (map[v.x][v.y] == nTile && (v.x != ori_x || v.y != ori_y)) {
			s += nTile;
			map[v.x][v.y] = '.';
			map[ori_x][ori_y] = '.';
			check = true;
			break;
		}

		info in;
		in.x = x;
		in.y = y;
		in.tile = nTile;
		in.dir = i;
		if (dir == -1 || dir == i) {
			in.cost = nCost;
		}
		else {
			in.cost = nCost + 1;
		}
		if (in.cost <= value[x][y] && in.cost < 2) {
			value[x][y] = in.cost;
			dfs(map, in, ori_x, ori_y, chk);
		}
	}
}


string solution(int m, int n, vector<string> board) {
	string answer = "";
	s = "";
	vector<vector<char>> v(m, vector<char>(n));

	unordered_map<char, pair<int, int>> map;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] = board[i].at(j);
			if ('A' <= v[i][j] && v[i][j] <= 'Z') {
				map[v[i][j]] = make_pair(i, j);
			}
		}
	}
	vector < pair<char, pair<int, int>>> temp(map.begin(), map.end());
	sort(temp.begin(), temp.end());
	vector<info> data;
	for (auto it = temp.begin(); it != temp.end(); it++) {
		info info;
		info.x = it->second.first;
		info.y = it->second.second;
		info.tile = it->first;
		info.dir = -1;
		info.cost = 0;
		data.push_back(info);
	}
	int a = 0;

	while (1) {
		for (int i = 0; i < temp.size(); i++) {
			check = false;
			fill(&value[0][0], &value[100][101], 987654321);

			dfs(v, data[i], data[i].x, data[i].y, i);
			if (check) {
				//»èÁ¦
				temp.erase(temp.begin() + i);
				data.erase(data.begin() + i);
				break;
			}

		}
		if (check == false || temp.size() == 0) {
			break;
		}
	}

	if (check == false) {
		answer = "IMPOSSIBL";
	}
	else {
		answer = s;
	}

	return answer;
}